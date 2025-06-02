// 3254. 长度为 K 的子数组的能量值 I
// 3255. 长度为 K 的子数组的能量值 II

#include <vector>

using namespace std;

class ResultsArrayV1 {
 public:
  //  1.直接遍历
  vector<int> resultsArray_1(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n - k + 1, -1);

    for (int i = 0; i <= n - k; i++) {
      bool valid = true;
      for (int j = 0; j < i + k; j++) {
        if (nums[j] - nums[j - 1] != 1) {
          valid = false;
          break;
        }
      }
      if (valid) {
        ans[i] = nums[i + k - 1];
      }
    }
    return ans;
  }

  // 2.利用逐步上升的特性，统计上升子串的长度
  vector<int> resultsArray_2(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    vector<int> ans(n - k + 1, -1);

    for (int i = 0; i < n; i++) {
      cnt = i == 0 || nums[i] - nums[i - 1] != 1 ? 1 : cnt + 1;
      if (cnt >= k) {
        ans[i - k + 1] = nums[i];
      }
    }
    return ans;
  }
};