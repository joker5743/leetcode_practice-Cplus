// 2306. 公司命名

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class DistinctNames {
 public:
  long long distinctNames(vector<string> &ideas) {
    unordered_map<char, unordered_set<string>>
        names;  // key：26个字母；value：所给的备选名字集合里，每个首字母对应的后缀
    for (const string &idea : ideas) {
      string suffix_str = idea.substr(1, idea.size() - 1);
      names[idea[0]].insert(suffix_str);
    }

    // 计算两个集合的交集元素数目，用于后续差集的计算。
    auto get_intersect_size = [](const unordered_set<string> &a,
                                 const unordered_set<string> &b) -> size_t {
      size_t ans = 0;
      for (const string &s : a) {
        if (b.count(s)) {
          ++ans;
        }
      }
      return ans;
    };

    long long ans = 0;
    for (auto &[pre_a, suff_a] : names) {
      for (auto &[pre_b, suff_b] : names) {
        if (pre_a == pre_b) {
          continue;
        }

        int intersect = get_intersect_size(suff_a, suff_b);
        ans += static_cast<long long>(suff_a.size() - intersect) *
               (suff_b.size() - intersect);
      }
    }
    return ans;
  }
};