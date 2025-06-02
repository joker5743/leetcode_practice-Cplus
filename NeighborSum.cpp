// 3242. 设计相邻元素求和服务

#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class NeighborSum {
 public:
  NeighborSum(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        pos[grid[i][j]] = {i, j};
      }
    }
    this->grid = std::move(grid);  // 把网格内的值记录到类成员变量中
  }

  int adjacentSum(int value) { return GetSum(value, 0); }

  int diagonalSum(int value) { return GetSum(value, 1); }

  int GetSum(int value, int idx) {
    auto [x, y] = pos[value];
    int ans = 0;
    for (int d = 0; d < 4; d++) {
      int nx = x + dirs[idx][d][0];
      int ny = y + dirs[idx][d][1];
      if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size()) {
        ans += grid[nx][ny];
      }
    }
    return ans;
  }

 private:
  vector<vector<int>> grid;
  unordered_map<int, pair<int, int>> pos;  // 记录值和对应的位置
  static constexpr int dirs[2][4][2] = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
                                        {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};
};