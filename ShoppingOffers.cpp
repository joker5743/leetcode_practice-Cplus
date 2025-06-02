// 638. 大礼包

#include <map>
#include <vector>

using namespace std;

class ShoppingOffers {
 public:
  //  记忆化搜索
  map<vector<int>, int> memo;  // 记录在某些需求下的情况下，所对应的最低价格

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    int n = price.size();

    // 剔除购买后并不优惠的大礼包
    vector<vector<int>> filterSpecial;
    for (auto& sp : special) {
      int totalcount = 0, totalprice = 0;
      for (int i = 0; i < n; i++) {
        totalcount += sp[i];
        totalprice += sp[i] * price[i];
      }
      if (totalcount > 0 && totalprice > sp[n]) {
        filterSpecial.push_back(sp);
      }
    }

    return dfs(price, special, needs, filterSpecial, n);
  }

  int dfs(vector<int>& price, vector<vector<int>>& special,
          vector<int> curNeeds, vector<vector<int>>& filterSpecial, int n) {
    if (!memo.count(curNeeds)) {
      int minprice = 0;
      for (int i = 0; i < n; i++) {
        minprice += curNeeds[i] * price[i];  // 原价购买产品的价格
      }

      for (auto& curSpecial : filterSpecial) {
        int specialPrice = curSpecial[n];
        vector<int> nxtNeeds;
        for (int i = 0; i < n; i++) {
          if (curSpecial[i] > curNeeds[i]) {
            break;  // 购买产品数量超出了自身需求
          }
          nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
        }

        if (nxtNeeds.size() == n) {
          minprice =
              min(minprice, dfs(price, special, nxtNeeds, filterSpecial, n) +
                                specialPrice);
        }
      }

      memo[curNeeds] = minprice;
    }
    return memo[curNeeds];
  }
};