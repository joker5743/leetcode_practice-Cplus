// 2414. 最长的字母序连续子字符串的长度

#include <string>

using namespace std;

class LongestContinuousSubstring {
 public:
  int longestContinuousSubstring(string s) {
    int cur = 1, res = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1] + 1) {
        cur++;
      } else {
        cur = 1;
      }
      res = max(res, cur);
    }
    return res;
  }
};