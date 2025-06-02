// 983. 最低票价

#include <limits>
#include <unordered_set>
#include <vector>
using namespace std;

class MincostTickets {
 public:
  // 方法1：记忆化搜索（日期变量），从后往前进行动态规划，dp[i]表示从第i天到一年的结束，所需的最小花费
  unordered_set<int> dayset;
  vector<int> costs;
  int memo[366] = {0};

  int dp_1(int i) {
    if (i > 365) {
      return 0;
    }

    if (memo[i] != -1) {
      return memo[i];
    }

    if (dayset.count(i)) {
      memo[i] = min(min(dp_1(i + 1) + costs[0], dp_1(i + 7) + costs[1]),
                    dp_1(i + 30) + costs[2]);
    } else {
      memo[i] = dp_1(i + 1);
    }
    return memo[i];
  }

  int mincostTickets_1(vector<int>& days, vector<int>& costs) {
    this->costs = costs;
    for (int day : days) {
      dayset.insert(day);
    }

    memset(memo, -1, sizeof(memo));
    return dp_1(1);
  }

  // 2.
  // 记忆化搜索，窗口变量型。在方法1的基础上进行一定优化，避免递归时的一些冗余计算（剪枝）
  vector<int> days;
  // vector<int> costs;
  vector<int> memo_vec;
  int duration[3] = {1, 7, 30};
  int mincostTickets_2(vector<int>& days, vector<int>& costs) {
    this->days = days;
    this->costs = costs;
    memo_vec.assign(days.size(), -1);
    return dp_2(0);
  }

  int dp_2(int i) {
    if (i >= days.size()) return 0;

    if (memo_vec[i] != -1) {
      return memo_vec[i];
    }

    memo_vec[i] = numeric_limits<int>::max();
    int j = i;
    for (int k = 0; k < 3; k++) {
      while (j < days.size() && days[j] < days[i] + duration[k]) {
        ++j;
      }
      memo_vec[i] = min(memo_vec[i], costs[k] + dp_2(j));
    }
    return memo_vec[i];
  }

  // 3. 动态规划
  int mincostTickets_3(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    // vector<int> dp_3(400, 0x3f3f3f3f);
    vector<int> dp_3(400, numeric_limits<int>::max());
    dp_3[0] = 0;
    dp_3[0] = 0;
    for (int i = 1, j = 0; i <= 365 && j < n; i++) {
      dp_3[i] = dp_3[i - 1];
      if (i == days[j]) {
        dp_3[i] = dp_3[max(0, i - 1)] + costs[0];
        dp_3[i] = min(dp_3[i], dp_3[max(0, i - 7)] + costs[1]);
        dp_3[i] = min(dp_3[i], dp_3[max(0, i - 30)] + costs[2]);
        j++;
      }
    }
    return dp_3[days.back()];
  }
};