// 997. 找到小镇的法官

#include <vector>

using namespace std;

class FindJudge {
 public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> inDegree(n + 1);
    vector<int> outDegree(n + 1);
    for (auto &edge : trust) {
      int x = edge[0], y = edge[1];
      ++inDegree[y];
      ++outDegree[x];
    }

    for (int i = 1; i <= n; ++i) {
      if (inDegree[i] == n - 1 && outDegree[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};