// 661. 图片平滑器

#include <vector>

using namespace std;

class ImageSmoother {
 public:
  //  逐个遍历，类似于卷积计算
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int num = 0, sum = 0;
        for (int x = i - 1; x <= i + 1; x++) {
          for (int y = j - 1; y < j + 1; y++) {
            if (x >= 0 && x < m && y >= 0 && y < n) {
              num++;
              sum += img[x][y];
            }
          }
        }
        ret[i][j] = sum / num;
      }
    }
    return ret;
  }

  // 基于前缀和求解
  vector<vector<int>> imageSmoother_PreSum(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));

    // 前缀和，s[i][j]表示从[0,0]到[i-1,j-1]这块儿二维区域里的元素之和
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        s[i][j] =
            s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + img[i - 1][j - 1];
      }
    }

    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int left = max(0, j - 1);
        int right = min(n - 1, j + 1);
        int top = max(0, i - 1);
        int down = min(m - 1, i + 1);
        // 参与平滑的元素个数
        int cnt = (right - left + 1) * (down - top + 1);
        int val = s[down + 1][right + 1] - s[top][right + 1] -
                  s[down + 1][left] + s[top][left];
        ret[i][j] = val / cnt;
      }
    }
    return ret;
  }
};