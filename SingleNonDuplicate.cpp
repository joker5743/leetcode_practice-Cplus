// 540. 有序数组中的单一元素

#include <vector>

using namespace std;

class SingleNonDuplicate {
 public:
  int singleNonDuplicate_1(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == nums[mid ^ 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }

  int singleNonDuplicate_2(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      mid -= mid & 1;  // 寻找目标索引必定是偶数
      if (nums[mid] == nums[mid + 1]) {
        low = mid + 2;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};