// 2073. 买票需要的时间

#include <vector>

using namespace std;

class TimeRequiredToBuy {
 public:
  // 1.
  // [k]前的人每人耗时不超过tickets[k],[k]后的人每人不超过ticket[k]-1,一次遍历即可
  int timeRequiredToBuy_1(vector<int> &tickets, int k) {
    int n = tickets.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (i <= k) {
        res += min(tickets[i], tickets[k]);
      } else {
        res += min(tickets[i], tickets[k] - 1);
      }
    }
  }

  // 2. 直接队列模拟
  int timeRequiredToBuy_2(vector<int> &tickets, int k) {
    int answer = 0, pos = 0;
    const int m = tickets.size();
    while (tickets[k]) {
      if (tickets[pos]-- > 0) answer++;
      pos = (pos + 1) % m;
    }
    return answer;
  }
};