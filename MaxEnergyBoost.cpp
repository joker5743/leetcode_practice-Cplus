// 3259. 超级饮料的最大强化能量

#include <vector>

using namespace std;

class MaxEnergyBoost {
 public:
  long long maxEnergyBoost(vector<int>& energyDrinkA,
                           vector<int>& energyDrinkB) {
    int n = energyDrinkA.size();
    vector<vector<long long>> d(n + 1, vector<long long>(2, 0));

    for (int i = 1; i <= n; i++) {
      // 假设连续引用同品质饮料，能摄入到的最大能量
      d[i][0] = d[i - 1][0] + energyDrinkA[i - 1];
      d[i][1] = d[i - 1][1] + energyDrinkB[i - 1];

      // 如果引用不同类饮料，更新所能获得的最大能量
      if (i >= 2) {
        // 由于更换饮料需要增加一天戒断，因此至少要到第三天（从第0天开始计时）才可能使用另一种饮料。
        d[i][0] = max(d[i][0], d[i - 2][1] + energyDrinkA[i - 1]);
        d[i][1] = max(d[i][1], d[i - 2][0] + energyDrinkB[i - 1]);
      }
    }
    return max(d[n][0], d[n][1]);
  }
};