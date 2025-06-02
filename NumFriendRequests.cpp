// 825. 适龄的朋友

#include <algorithm>
#include <vector>

using namespace std;

class NumFriendRequests {
 public:
  //  1. 排序+双指针
  int numFriendRequests_1(vector<int>& ages) {
    int n = ages.size();
    sort(ages.begin(), ages.end());
    int left = 0, right = 0, ans = 0;  // 已经排序过了，所以可以不用写到循环内。
    for (auto& age : ages) {
      if (age < 15) continue;

      while (ages[left] <= 0.5 * age + 7) {
        left++;
      }

      while (right + 1 < n && ages[right + 1] <= age) {
        right++;
      }
      ans += right - left;
    }
    return ans;
  }

  // 2. 前缀和
  int numFriendRequests_2(vector<int>& ages) {
    // 统计各个年龄段的人数
    vector<int> cnt(121);
    for (auto& age : ages) {
      ++cnt[age];
    }

    // 前缀和数组，所有小于X岁的人数
    vector<int> pre(121);
    for (int i = 1; i <= 120; i++) {
      pre[i] = pre[i - 1] + cnt[i];
    }

    int ans = 0;
    // 根据题目要求推导得出最小年龄需要大于14
    for (int i = 15; i <= 120; ++i) {
      if (cnt[i]) {
        int bound = i * 0.5 + 8;
        ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
      }
    }
    return ans;
  }
};
