// 3244. 新增道路查询后的最短距离 II

#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class ShortestDistanceAfterQueriesV2 {
 public:
  //  题目表示新建的路径不会有交叉的情况，因此比V1要简单一些，直接使用贪心算法思路即可
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>>& queries) {
    vector<int> roads(n);  // roads[u]=v 表示从城市 u 到城市 v 的一条单向道路
    iota(roads.begin(), roads.end(), 1);  //(1,2,3,4 ... n)
    vector<int> res;
    int dis = n - 1;

    for (const auto& query : queries) {
      int k = roads[query[0]];  // 目前query之前的路况下，找到的最短路径
      roads[query[0]] =
          query[1];  // 更新当前query后的路况，理论上更新后的路径终点query[1]
                     // >= k
      while (k != -1 && k < query[1]) {
        int t = roads[k];  // 通过城市k能到达的城市t
        roads[k] = -1;     // 到达t的路线可以不经过城市K了
        k = t;
        dis--;  // 因为目的地是最后一个城市，所以中间任意一条线路有更短的路径，总路径都会缩短
      }
      res.emplace_back(dis);
    }
    return res;
  }
};
