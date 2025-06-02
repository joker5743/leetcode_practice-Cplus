// 3240. 最少翻转次数使二进制矩阵回文 II

#include <limits>
#include <vector>

using namespace std;

class MinFlipsV2 {
 public:
  // 1. 模拟
  int minFlips_1(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for (int i = 0; i < m / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        int cnt1 =
            grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] +
            grid[m - 1 - i]
                [n - 1 -
                 j];  // 计算行、列、对角线方向上对称的四个元素中含有的1个数
        ans += min(cnt1, 4 - cnt1);
      }
    }

    // 当行列都是偶数的时候，上面的代码就是答案，对于存在的奇数行列，需要额外讨论
    int diff = 0, cnt1 = 0;
    // 奇数行
    if (m & 1) {
      for (int j = 0; j < n / 2; j++) {
        if (grid[m / 2][j] ^ grid[m / 2][n - 1 - j]) {
          diff++;
        } else {
          cnt1 += grid[m / 2][j] * 2;
        }
      }
    }

    if (n & 1) {
      for (int i = 0; i < m / 2; i++) {
        if (grid[i][n / 2] ^ grid[m - 1 - i][n / 2]) {
          diff++;
        } else {
          cnt1 += grid[i][n / 2] * 2;
        }
      }
    }

    if (m & 1 && n & 1) {
      ans +=
          grid[m / 2]
              [n / 2];  // 奇数行奇数列，正中间元素必须是0才能保证1的个数被4整除
    }

    if (diff > 0) {
      ans += diff;
    } else {
      ans += cnt1 % 4;
    }
    return ans;
  }

  // 2. 动态规划
  int minFlips_2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> f(4, numeric_limits<int>::max() / 2);
    f[0] = 0;
    for (int i = 0; i < (m + 1) / 2; i++) {
      for (int j = 0; j < (n + 1) / 2; j++) {
        int ones = grid[i][j], cnt = 1;
        if (j != n - 1 - j) {
          ones += grid[i][n - 1 - j];
          cnt++;
        }

        if (i != m - 1 - i) {
          ones += grid[m - 1 - i][j];
          cnt++;
        }

        if (i != m - 1 - i && j != n - 1 - j) {
          ones += grid[m - 1 - i][n - 1 - j];
          cnt++;
        }

        // 将这一组变成1的代价
        int cnt1 = cnt - ones;
        // 变成0的代价
        int cnt0 = ones;
        vector<int> tmp(4);
        for (int k = 0; k < 4; k++) {
          tmp[k] = f[k] + cnt0;
        }
        for (int k = 0; k < 4; k++) {
          tmp[(k + cnt) % 4] = min(tmp[(k + cnt) % 4], f[k] + cnt1);
        }
        swap(f, tmp);
      }
    }
    return f[0];
  }
};