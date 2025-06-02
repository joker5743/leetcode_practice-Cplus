// 3208. 交替组 II

#include <vector>

using namespace std;

class NumberOfAlternatingGroups {
 public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    int res = 0, cnt = 1;  // cnt记录交替环的元素个数，默认为1
    for (
        int i = 2 - k; i < n;
        i++) {  // 需要考虑首位的问题，题目要求K>=3,所以初始值为-1考虑首位部分相连的部分
      if (colors[(i + n) % n] != colors[(i - 1 + n) % n]) {
        cnt++;
      } else {
        cnt = 1;
      }

      if (cnt >= k) {
        res++;
      }
    }
    return res;
  }
};