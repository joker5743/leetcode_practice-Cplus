// 2398. 预算内的最多机器人数目

#include <deque>
#include <vector>

using namespace std;

class MaximumRobots {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                    long long budget) {
    int res = 0, n = chargeTimes.size();
    long long runningCostSum = 0;
    deque<int> q;

    // 移动滑窗的右边界
    for (int i = 0, j = 0; i < n; i++) {
      runningCostSum += runningCosts[i];
      while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[i]) {
        q.pop_back();
      }
      q.push_back(i);

      // 移动滑窗的左边界
      while (j <= i &&
             (i - j + 1) * runningCostSum + chargeTimes[q.front()] > budget) {
        // 左边界退出的机器人，如果耗时是最多的，则同时更新去除单调栈中的栈底内容。
        if (!q.empty() && q.front() == j) {
          q.pop_front();
        }

        runningCostSum -= runningCosts[j];
        j++;
      }
      res = max(res, i - j + 1);
    }
    return res;
  }
};