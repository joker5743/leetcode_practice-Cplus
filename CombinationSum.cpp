// 39. 组合总和

#include <vector>
using namespace std;

class CombinationSum {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> combine;
    dfs(candidates, target, ans, combine, 0);
    return ans;
  }

  void dfs(vector<int> candidates, int target, vector<vector<int>>& ans,
           vector<int>& combine, int index) {
    if (index == candidates.size()) return;

    if (target == 0) {
      ans.push_back(combine);
      return;
    }

    // 跳过这个元素
    dfs(candidates, target, ans, combine, index + 1);

    if (target - candidates[index] >= 0) {
      combine.push_back(candidates[index]);
      dfs(candidates, target - candidates[index], ans, combine,
          index);  // 重复选择该元素
      combine.pop_back();
    }
  }
};