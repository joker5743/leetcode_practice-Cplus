// 3176. 求出最长好子序列 I
#include <unordered_map>
#include <vector>

using namespace std;

class MaximumLength {
 public:
  // 1.
  // 直接二维动态规划，dp[i][j]表示以nums[i]结尾的最长好子序列，有j个数字与在序列的后一个数字不相等
  int maximumLength_1(vector<int> &nums, int k) {
    int ans = 0;
    int len = nums.size();
    vector<vector<int>> dp;
    dp.resize(len, vector<int>(51, -1));

    for (int i = 0; i < len; i++) {
      dp[i][0] = 1;
      for (int l = 0; i <= k; l++) {
        for (int j = 0; j < i; j++) {
          int add = (nums[i] != nums[j]);
          if (l - add >= 0 && dp[j][l - add] != -1) {
            dp[i][l] = max(dp[i][l], dp[j][l - add] + 1);
          }
        }
        ans = max(ans, dp[i][l]);
      }
    }
    return ans;
  }

  // 2.
  // 优化版本动态规划，使用一维dp记录最长序列，哈希表记录对应最长序列的最近末尾索引。
  int maximumLength_2(vector<int> &nums, int k) {
    int len = nums.size();
    unordered_map<int, vector<int>> dp;
    vector<int> zd(k + 1, 0);

    for (int i = 0; i < len; i++) {
      int v = nums[i];
      if (!dp.count(v)) {
        dp[v] = vector<int>(k + 1, 0);
      }

      auto &temp = dp[v];
      for (int j = 0; j <= k; j++) {
        temp[j] = temp[j] + 1;
        if (j > 0) {
          temp[j] = max(temp[j], zd[j - 1] + 1);
        }
      }

      for (int j = 0; j <= k; j++) {
        zd[j] = max(zd[j], temp[j]);
      }
    }
    return zd[k];
  }
};