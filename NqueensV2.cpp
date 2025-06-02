// 51. N皇后II
// 参考N皇后I问题，思路一致只是从求解全部具体方案变化为求解所有方案数量，返回值变化了而已

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class NQueensV2 {
 public:
  // 方法一：回溯+集合
  int solveNQueens_1(int n) {
    unordered_set<int> columns;
    unordered_set<int> diagonals1;
    unordered_set<int> diagonals2;
    return backtrack_1(n, 0, columns, diagonals1, diagonals2);
  }

  int backtrack_1(int n, int row, unordered_set<int> &columns,
                  unordered_set<int> &diagonals1,
                  unordered_set<int> &diagonals2) {
    if (row == n) {
      return 1;
    } else {
      int count = 0;
      for (int i = 0; i < n; i++) {
        // 如果该列已经有其他皇后，跳过
        if (columns.find(i) != columns.end()) continue;

        // 主对角线方向存在其他皇后，跳过
        int diagonal1 = row - i;  // 针对某一条主对角线，行索引 - 列索引=固定值
        if (diagonals1.find(diagonal1) != diagonals1.end()) continue;

        // 副对角线方向存在其他皇后，跳过
        int diagonal2 = row + i;  // 针对某一条副对角线，行索引 + 列索引=固定值
        if (diagonals2.find(diagonal2) != diagonals2.end()) continue;

        columns.insert(i);
        diagonals1.insert(diagonal1);
        diagonals2.insert(diagonal2);

        count += backtrack_1(n, row + 1, columns, diagonals1, diagonals2);
        // 回溯，撤销刚才放置的棋子
        columns.erase(i);
        diagonals1.erase(diagonal1);
        diagonals2.erase(diagonal2);
      }
      return count;
    }
  }

  // 方法二：回溯+位运算
  int solveNQueens_2(int n) { return solve(n, 0, 0, 0, 0); }

  int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
      return 1;
    } else {
      int count = 0;
      int availablePositions =
          ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
      while (availablePositions != 0) {
        int position = availablePositions &
                       (~availablePositions +
                        1);  // 这一行将要放置的皇后棋子列位置对应的二进制码
        availablePositions = availablePositions & (availablePositions - 1);
        count +=
            solve(n, row + 1, columns | position, (diagonals1 | position) << 1,
                  (diagonals2 | position) >> 1);  // 回溯，撤销刚才放置的棋子
      }
      return count;
    }
  }
};