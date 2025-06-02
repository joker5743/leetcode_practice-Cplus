// 3191. 使二进制数组全部等于 1 的最少操作次数 I

#include <vector>

using namespace std;

class MinOperationsV2 {
 public:
  //  贪心算法，直接模拟
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        if (i > n - 3) {
          return -1;
        }

        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        ans++;
      }
    }
    return ans;
  }
};