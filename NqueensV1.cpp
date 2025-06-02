// 51. N皇后I

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class NQueensV1 {
 public:
  // 方法一：回溯+集合
  vector<vector<string>> solveNQueens_1(int n) {
    vector<vector<string>> solutions;
    vector<int> queens(n, -1);  // 记录每一行放置皇后棋子的列索引
    unordered_set<int> columns;
    unordered_set<int> diagonals1;
    unordered_set<int> diagonals2;
    backtrack_1(solutions, queens, n, 0, columns, diagonals1, diagonals2);
    return solutions;
  }

  void backtrack_1(vector<vector<string>> &solutions, vector<int> &queens,
                   int n, int row, unordered_set<int> &columns,
                   unordered_set<int> &diagonals1,
                   unordered_set<int> &diagonals2) {
    if (row == n) {
      cout << "has get one solution" << endl;
      solutions.push_back(generateBoard(queens, n));
    } else {
      for (int i = 0; i < n; i++) {
        // 如果该列已经有其他皇后，跳过
        if (columns.find(i) != columns.end()) continue;

        // 主对角线方向存在其他皇后，跳过
        int diagonal1 = row - i;  // 针对某一条主对角线，行索引 - 列索引=固定值
        if (diagonals1.find(diagonal1) != diagonals1.end()) continue;

        // 副对角线方向存在其他皇后，跳过
        int diagonal2 = row + i;  // 针对某一条副对角线，行索引 + 列索引=固定值
        if (diagonals2.find(diagonal2) != diagonals2.end()) continue;

        queens[row] = i;  // 在第row行，第i列放置棋子
        columns.insert(i);
        diagonals1.insert(diagonal1);
        diagonals2.insert(diagonal2);

        backtrack_1(solutions, queens, n, row + 1, columns, diagonals1,
                    diagonals2);
        queens[row] = -1;  // 回溯，撤销刚才放置的棋子
        columns.erase(i);
        diagonals1.erase(diagonal1);
        diagonals2.erase(diagonal2);
      }
    }
  }

  vector<string> generateBoard(vector<int> &queens, int n) {
    auto board = vector<string>();
    for (int i = 0; i < n; i++) {
      string row = string(n, '.');
      row[queens[i]] = 'Q';
      board.push_back(row);
    }
    return board;
  }

  // 方法二：回溯+位运算
  vector<vector<string>> solveNQueens_2(int n) {
    auto solutions = vector<vector<string>>();
    auto queens = vector<int>(n, -1);
    solve(solutions, queens, n, 0, 0, 0, 0);
    return solutions;
  }

  void solve(vector<vector<string>> &solutions, vector<int> &queens, int n,
             int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
      solutions.push_back(generateBoard(queens, n));
    } else {
      int availablePositions =
          ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
      while (availablePositions != 0) {
        int position = availablePositions & (~availablePositions + 1);
        availablePositions = availablePositions & (availablePositions - 1);
        int column = __builtin_ctz(position);
        queens[row] = column;
        solve(solutions, queens, n, row + 1, columns | position,
              (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
        queens[row] = -1;  // 回溯，撤销刚才放置的棋子
      }
    }
  }
};