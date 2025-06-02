// 2332. 坐上公交的最晚时间

#include <algorithm>
#include <vector>

using namespace std;

class LatestTimeCatchTheBus {
 public:
  int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers,
                            int capacity) {
    // 按照时间排序
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int pos = 0;
    int space = 0;  // 最后一辆车发车时剩余的座位
    for (int bus_time : buses) {
      space = capacity;
      while (space > 0 && pos < passengers.size() &&
             passengers[pos] <= bus_time) {
        // 上车条件：1. 车上有空位；2.
        // 存在有效乘客（乘客存在且在发车时间前抵达车站）
        space--;
        pos++;
      }
    }

    pos--;  // pos定位到最后一位搭上车的乘客
    int lastCatchTime = space > 0 ? buses.back() : passengers[pos];
    /* 下面循环判断条件的第二项含义：
    当最后一辆车还有空位时，如果最后一位到达的乘客和汽车到达时间相同，按照题目所述由于“我”不能和其他乘客同时到达，所以需要回退至上一位乘客之后的空余时间。
    当最后一辆车没有空位的时候，回退至上一位乘客之后的空余时间。 */
    while (pos >= 0 && passengers[pos] == lastCatchTime) {
      pos--;
      lastCatchTime--;
    }
    return lastCatchTime;
  }
};