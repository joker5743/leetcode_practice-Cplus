// 3192. 使二进制数组全部等于 1 的最少操作次数 II

#include <vector>

using namespace std;

class MinOperationsV2 {
 public:
  //  1. 找规律
  int minOperations_1(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
      if (nums[i] == (ans) % 2) {
        ans++;
      }
    }
    return ans;
  }

  // 2. 动态规划
  int minOperations_2(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (size_t i = n - 2; i >= 0; i--) {
      if (nums[i] != nums[i + 1]) {
        ans++;
      }
    }
    return nums[0] == 1 ? ans : ans + 1;
  }
};