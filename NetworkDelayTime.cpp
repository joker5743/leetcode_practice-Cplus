// 743. 网络延迟时间

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class NetworkDelayTime {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // 构造邻接图
    const int inf = numeric_limits<int>::max() /
                    2;  // 除以2是防止数字过大，增加1就会出现溢出的异常情况。
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (auto time : times) {
      int x = time[0] - 1, y = time[1] - 1;
      g[x][y] = time[2];
    }

    vector<int> dist(n, inf);  // 记录从K到其他节点的最短距离
    dist[k - 1] = 0;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
      int x = -1;
      for (int y = 0; y < n; y++) {
        if (!used[y] && (x == -1 || dist[y] < dist[x])) {
          x = y;
        }
      }
      // 寻找中间节点X，使得k -> y的距离能最近
      used[x] = true;
      for (int y = 0; y < n; y++) {
        dist[y] = min(dist[y], dist[x] + g[x][y]);
      }
    }

    int ans = *max_element(dist.begin(), dist.end());
    return ans == inf ? -1 : ans;
  }
};