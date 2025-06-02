// 3233. 统计不是特殊数字的数字数量

/* 题目主要考察对质数的判断，参考
204. 计数质数
这一道题目的考察 */

#include <cmath>
#include <vector>

using namespace std;

class NonSpecialCount {
 public:
  //  欧式筛判断质数
  int nonSpecialCount(int l, int r) {
    int n = sqrt(n);
    vector<int> v(n + 1);  // 记录0-n这n+1个数哪些是质数，0为质数1为合数
    int res = r - l + 1;

    for (int i = 2; i <= n; i++) {
      if (!v[i]) {
        if (i * i >= l && i * i <= r) {
          res--;
        }
        for (int j = i * 2; j <= n; j += i) {
          v[j] = 1;
        }
      }
    }
    return res;
  }
};