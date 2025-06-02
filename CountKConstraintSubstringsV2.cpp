// 3261. 统计满足 K 约束的子字符串数量 II

#include <string>
#include <vector>

using namespace std;

class CountKConstraintSubstringsV1 {
 public:
  vector<long long> countKConstraintSubstrings(string s, int k,
                                               vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> count(2, 0);
    vector<int> right(n, n);
    vector<long long> prefix(n + 1, 0);

    int i = 0;
    for (int j = 0; j < n; j++) {
      count[s[j] - '0']++;
      while (count[0] > k && count[1] > k) {
        count[s[i] - '0']--;
        right[i] =
            j;  // 此时子字符串[i, j]刚开始不满足约束条件时，右侧的索引位置
        i++;
      }
      prefix[j + 1] = prefix[j] + j - i + 1;
    }

    vector<long long> res;
    for (auto& query : queries) {
      int l = query[0], r = query[1];
      int i = min(right[l], r + 1);
      long long part1 = 1LL * (i - l + 1) * (i - l) / 2;
      long long part2 = prefix[r + 1] - prefix[i];
      res.push_back(part1 + part2);
    }
    return res;
  }
};