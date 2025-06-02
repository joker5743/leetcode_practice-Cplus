// 3249. 统计好节点的数目

#include <functional>
#include <vector>

using namespace std;

class CountGoodNodes {
 public:
  int countGoodNodes(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    int res = 0;
    // 构建拓扑矩阵
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    function<int(int, int)> dfs = [&](int node, int parent) -> int {
      bool valid = true;
      int treeSize = 0;
      int subTreeSize = 0;

      for (int child : graph[node]) {
        if (child != parent) {
          // 如果该节点不是叶子节点，还有其他的子节点
          int size = dfs(child, node);  // 以child子节点为根的子树节点数目
          if (subTreeSize == 0) {
            subTreeSize = size;
          } else if (
              size !=
              subTreeSize)  // 如果当前child节点为根的子树节点数目，和同级别其他子节点为根的子树节点数目不等，则判断不是“好”节点。
          {
            valid = false;
          }
          treeSize +=
              size;  // 该节点是好节点，把该节点为根的所在子树包含的节点数量加入到其父节点下的其中一部分。
        }
      }

      if (valid) {
        res++;
      }
      return treeSize + 1;  // 加上最后的根节点
    };

    dfs(0, -1);
    return res;
  }
};