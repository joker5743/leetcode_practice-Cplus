// 2207. 字符串中最多数目的子序列

#include <string>

using namespace std;

class MaximumSubsequenceCount {
 public:
  // 统计两个字符出现的频数。如果遇见 pattern[1]，就可以和前面出现过的
  // pattern[0] 组成子序列
  long long maximumSubsequenceCount(string text, string pattern) {
    long long res = 0;
    int cnt1 = 0,
        cnt2 =
            0;  // pattern[0]插入字符开头，pattern[1]插入字符末尾得到的子序列数量
    for (char c : text) {
      // pattern[0]加载字符串开头
      if (c == pattern[1]) {
        res += cnt1;  // 在现存的字符串里，能得到的子序列数量
        cnt2++;
      }
      // 记录字符串中的pattern[0]数量
      if (c == pattern[0]) {
        cnt1++;
      }
    }
    return res +
           max(cnt1,
               cnt2);  // 现存的子序列res,再加上两个字符中数量较多的即可得到最多的子序列数量
  }
};