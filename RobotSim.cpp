// 874.模拟行走机器人

#include <unordered_set>
#include <vector>
using namespace std;

class RobotSim {
 public:
  int rebotSim(vector<int> commads, vector<vector<int> > obstacles) {
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int px = 0, py = 0, d = 1;
    unordered_set<int> mp;

    for (auto &obstacle : obstacles) {
      mp.emplace(obstacle[0] * 60001 + obstacle[1]);
    }

    int res = 0;
    for (auto &c : commads) {
      if (c < 0) {
        d += c == -1 ? 1 : -1;
        d %= 4;
        if (d < 4) d += 4;
      } else {
        for (int i = 0; i < c; i++) {
          if (mp.count((px + dir[d][0]) * 60001 + py + dir[d][1])) break;
          px += dir[d][0];
          py += dir[d][1];
          res = max(res, px * px + py * py);
        }
      }
    }
    return res;
  }
};