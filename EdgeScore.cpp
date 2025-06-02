// 2374. 边积分最高的节点

#include <vector>

using namespace std;

class EdgeScore {
 public:
  int edgeScore(vector<int> &edges) {
    int n = edges.size();
    vector<long long> points(n);
    for (int i = 0; i < n; i++) {
      points[edges[i]] += i;
    }

    long long max_points = -1;
    int res = -1;
    for (int i = 0; i < n; i++) {
      if (points[i] > max_points) {
        max_points = points[i];
        res = i;
      }
    }
    return res;
  }
};