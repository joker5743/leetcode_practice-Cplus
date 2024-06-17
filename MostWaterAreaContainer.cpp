// 11. 盛最多水的容器

#include <vector>
using namespace std;

class MostWaterAreaContainer {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      int area = min(height[l], height[r]) * (r - l);
      ans = max(ans, area);
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return ans;
  }
};