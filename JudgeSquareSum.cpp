// 633. 平方数之和

#include <cmath>

class JudgeSquareSum {
 public:
  //  1. 遍历 + sqrt函数
  bool judgeSquareSum_1(int c) {
    for (long a = 0; a * a <= c; a++) {
      double b = std::sqrt(c - a * a);
      if (b == static_cast<int>(b)) {
        return true;
      }
    }
    return false;
  }

  // 2. 双指针
  bool judgeSquareSum_2(int c) {
    long left = 0, right = static_cast<long>(std::sqrt(c));
    while (left <= right) {
      long sum = left * left + right * right;
      if (sum == c) {
        return true;
      } else if (sum > c) {
        right--;
      } else {
        left++;
      }
    }
    return false;
  }

  // 3.数学原理
  bool judgeSquareSum_3(int c) {
    for (int base = 2; base * base < c; base++) {
      if (c % base != 0) {
        continue;
      }

      int exp = 0;
      while (c % base == 0) {
        c /= base;
        exp++;
      }

      if (base % 4 == 3 && exp % 2 != 0) {
        return false;
      }
    }
    return c % 4 != 3;
  }
};