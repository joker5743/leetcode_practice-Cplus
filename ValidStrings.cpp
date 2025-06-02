// 3211. 生成不含相邻零的二进制字符串

#include <functional>
#include <string>
#include <vector>

using namespace std;

class ValidStrings {
 public:
  // 基于回溯思路，得到所有的可能解
  vector<string> validStrings(int n) {
    vector<string> ans;
    string str;

    function<void(string &)> dfs = [&](string &str) {
      // auto dfs = [&](string &str){
      // //由于有递归调用，需要显示指定函数参数与返回值类型，可能C++14以上的编译版本可行，但是C++11待定
      if (str.size() == n) {
        ans.push_back(str);
        return;
      }

      if (str.empty() || str.back() == '1') {
        str.push_back('0');
        dfs(str);
        str.pop_back();
      }

      str.push_back('1');
      dfs(str);
      str.pop_back();
    };

    dfs(str);
    return ans;
  }
};