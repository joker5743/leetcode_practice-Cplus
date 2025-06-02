// 3243. 新增道路查询后的最短距离 I

#include <queue>
#include <vector>

using namespace std;

class ShortestDistanceAfterQueriesV1 {
 public:
  // 1. 构建邻接图数组 + BFS
  vector<int> shortestDistanceAfterQueries_1(int n,
                                             vector<vector<int>>& queries) {
    vector<vector<int>> neighbors;
    for (int i = 0; i < n - 1; i++) {
      neighbors[i].emplace_back(i + 1);
    }

    vector<int> ans;
    for (auto& query : queries) {
      neighbors[query[0]].emplace_back(query[1]);
      ans.push_back(bfs(n, neighbors));
    }
    return ans;
  }

  int bfs(int n, vector<vector<int>>& neighbors) {
    vector<int> dist(n, -1);  // 起点城市到各个城市的最短距离
    queue<int> q;

    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : neighbors[x]) {
        if (dist[y] >= 0) {
          continue;
          /* 由于每一条边的权重都是1，因此最先被修改的时候就是最快到达该节点的路径。
          此时如果已经被记录了则表示已经找到最短路径，无需重复计算。
          类似于visited[i]数组记录是否被访问 */
        }
        q.push(y);
        dist[y] = dist[x] + 1;
      }
    }
    return dist[n - 1];
  }

  // 2. 动态规划
  vector<int> shortestDistanceAfterQueries_2(int n,
                                             vector<vector<int>>& queries) {
    vector<vector<int>> prev(
        n);  // 记录每个以该城市为终点，存在道路能到达的起点城市（有连接）
    vector<int> dp(
        n);  // dp记录从城市0到城市i的最短路径，题目所求为不同道路情况下的dp[n-1]
    for (int i = 1; i < n; i++) {
      prev[i].push_back(i - 1);
      dp[i] = i;
    }

    vector<int> res;
    for (auto& query : queries) {
      prev[query[1]].emplace_back(query[0]);
      for (int v = query[1]; v < n; v++) {
        for (int u : prev[v]) {
          dp[v] = min(dp[v], dp[u] + 1);
        }
      }
      res.emplace_back(dp[n - 1]);
    }
    return res;
  }
};
