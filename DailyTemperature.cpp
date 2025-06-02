// 739. 每日温度

#include <climits>
#include <numeric>
#include <stack>
#include <vector>
using namespace std;

class DailyTemperature {
 public:
  // 暴力迭代
  vector<int> dailyTemperatures_1(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    vector<int> next(101, INT_MAX);  // 记录每一度对应在哪一天。温度范围在30 -
                                     // 101之间，101个空间的数组足够。

    for (int i = n - 1; i >= 0; i--) {
      int warnerIndex = INT_MAX;
      for (int t = temperatures[i] + 1; t <= 100; t++) {
        warnerIndex = min(warnerIndex, next[t]);
      }
      if (warnerIndex != INT_MAX) {
        res[i] = warnerIndex - i;
      }
      next[temperatures[i]] = i;
    }
  }

  // 单调栈
  vector<int> dailyTemperatures_2(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int prevIndex = st.top();
        st.pop();
        res[prevIndex] = i - prevIndex;
      }
      st.push(i);
    }
    return res;
  }
};