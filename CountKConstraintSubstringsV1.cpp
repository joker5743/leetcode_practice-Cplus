// 3258. 统计满足 K 约束的子字符串数量 I

#include <string>
#include <vector>

using namespace std;

class CountKConstraintSubstringsV1 {
 public:
  // 1. 暴力双重遍历
  int countKConstraintSubstrings_1(string s, int k) {
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++) {
      int count[2] = {0};
      for (int j = i; j < n; j++) {
        count[s[j] - '0']++;
        if (count[0] > k && count[1] > k) {
          break;
        }
        res++;
      }
    }
    return res;
  }
  // 2. 双指针or滑动窗口
  int countKConstraintSubstrings_2(string s, int k) {
    int n = s.size(), cnt0 = 0, cnt1 = 0, res = 0;
    for (int l = 0, r = 0; r < n; r++) {
      if (s[r] == '0')
        cnt0++;
      else
        cnt1++;

      while (l <= r && (cnt0 > k && cnt1 > k)) {
        if (s[l] == '0')
          cnt0--;
        else
          cnt1--;

        l++;
      }
      res += r - l + 1;
    }
    return res;
  }
};