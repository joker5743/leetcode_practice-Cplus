// 815. 公交路线

#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class NumBusesToDestination {
 public:
  /* 构建新的图关系，减少直接用站点来表示图的点，减少复杂度
  将某一条线路构建为图的点，线路之间存在换乘关系则存在边连接 */
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    int n = routes.size();
    vector<vector<int>> edge(n, vector<int>(n));  // 每条线路之间的连接关系
    unordered_map<int, vector<int>>
        rec;  // key站点编号：value是该站点存在于哪些线路

    for (int i = 0; i < n; i++) {
      for (int site : routes[i]) {
        for (int j : rec[site]) {
          edge[i][j] = edge[j][i] = true;
        }
        rec[site].push_back(i);
      }
    }

    vector<int> dist(n, -1);
    queue<int> que;
    for (int bus : rec[source]) {
      // 索引bus的线路，初始化为触发的第一辆车
      dist[bus] = 1;
      que.push(bus);
    }

    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (int y = 0; y < n; y++) {
        if (edge[x][y] && dist[y] == -1) {
          // dist[y] == -1保证x->y这条换乘线路没有被使用过，不会成环
          dist[y] = dist[x] + 1;
          que.push(y);
        }
      }
    }

    int ret = numeric_limits<int>::max();
    for (int bus : rec[target]) {
      if (dist[bus] != -1) {
        ret = min(ret, dist[bus]);
      }
    }
    return ret == numeric_limits<int>::max() ? -1 : ret;
  }
};