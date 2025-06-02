// 688. 骑士在棋盘上的概率

#include <vector>

using namespace std;

class KnightProbability {
 public:
  // 8方向移动坐标
  vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                              {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
  double knightProbability(int n, int k, int row, int column) {
    // 动态规划
    // 定义dp[i][j][k]表示从(i,j)出发，走k步，还留在棋盘上的概率
    vector<vector<vector<double>>> dp(
        k + 1, vector<vector<double>>(n, vector<double>(n)));
    for (int step = 0; step <= k; step++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (step == 0) {
            dp[step][i][j] = 1;
          } else {
            for (const auto &dir : dirs) {
              int ni = i + dir[0];
              int nj = j + dir[1];
              if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
              }
            }
          }
        }
      }
    }
    return dp[k][row][column];
  }
};