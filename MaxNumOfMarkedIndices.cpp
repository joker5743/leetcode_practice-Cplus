// 2576. 求出最多标记下标
#include <algorithm>
#include <vector>

using namespace std;

class MaxNumOfMarkedIndices {
 public:
  // 1. 二分查找,
  int maxNumOfMarkedIndices_1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n / 2;

    // 自定义lamda函数，m表示最小和最大的m个数，也就是m对，能否满足2倍条件。
    auto check = [&](int m) {
      for (int i = 0; i < m; i++) {
        if (nums[i] * 2 > nums[n - m + i]) {
          return false;
        }
      }
      return true;
    };

    while (l < r) {
      int m = l + r + 1 >> 1;
      if (check(m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l * 2;  // 有L对，所以是L * 2个数字
  }

  // 2. 排序 + 枚举
  int maxNumOfMarkedIndices_2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int m = n / 2;
    int res = 0;

    for (int i = 0, j = m; i < m && j < n; i++) {
      while (j < n && 2 * nums[i] > nums[j]) {
        j++;
      }

      if (j < n) {
        res += 2;
        j++;
      }
    }
    return res;
  }
};