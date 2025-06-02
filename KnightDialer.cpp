// 935. 骑士拨号器

#include <algorithm>
#include <vector>


using namespace std;

class KnightDialer {
  static constexpr int mod = 1e9 + 7;

 public:
  // 1. 动态规划
  int knightDialer_1(int n) {
    vector<vector<int>> moves = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                                 {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    vector<vector<int>> dp(2, vector<int>(10, 0));    // dp[0]表示第i轮，dp[1]表示第i-1轮，利用滚动数组的方法节省内存。
    fill(dp[1].begin(), dp[1].end(), 1);

    for (int i = 2; i <= n; i++) {
      int x = i & 1;       // 滚动数组,通过最后一位的奇偶来判断是当前轮数还是上一轮数。
      for (int j = 0; j < 10; j++) {
        dp[x][j] = 0;
        for (auto const &k : moves[j]) {
          dp[x][j] = (dp[x][j] + dp[x ^ 1][k]) % mod;
        }
      }
    }

    int res = 0;
    for (auto x : dp[n % 2]) {
      res = (res + x) % mod;
    }
    return res;
  }
};