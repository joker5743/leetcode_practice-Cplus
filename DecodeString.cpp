// 394. 字符串解码

#include <algorithm>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class DecodeString {
 private:
  /* data */
 public:
  string decodeString_1(string s) {
    stack<pair<string, int>> stk;
    string res = "";
    int mul = 0;

    for (char c : s) {
      if (c == '[') {
        stk.emplace(res, mul);
        res = "";
        mul = 0;
      } else if (c == ']') {
        auto [last_res, cur_mul] = stk.top();
        stk.pop();
        string temp = last_res;
        for (int i = 0; i < cur_mul; i++) {
          temp += res;
        }
        res = temp;
      } else if ('0' <= c && c <= '9') {
        mul = mul * 10 + (c - '0');
      } else {
        res += c;  // c是一般英文字符
      }
    }
    return res;
  }

  string decodeString_2(string s) {
    vector<string> stk;
    size_t ptr = 0;

    while (ptr < s.size()) {
      char c = s[ptr];
      if (isdigit(c)) {
        string digits = getDigits(s, ptr);
        stk.push_back(digits);
      } else if (isalpha(c) || c == '[') {
        stk.push_back(string(1, s[ptr++]));
      } else {
        ++ptr;  // 检测到位]，右括号直接跳过，开始合并处理。
        vector<string> sub;
        while (stk.back() != "[") {
          sub.push_back(stk.back());
          stk.pop_back();
        }
        reverse(sub.begin(), sub.end());
        stk.pop_back();  // 弹出左括号，左括号之前必定是一个大于1的数字字符
        int rep_time = stoi(stk.back());
        stk.pop_back();
        string t;
        string o = getString(sub);
        while (rep_time--) {
          t += o;
        }
        stk.push_back(t);
      }
    }
    return getString(stk);
  }

  string getDigits(string &s, size_t &ptr) {
    string res = "";
    while (isdigit(s[ptr])) {
      res.push_back(s[ptr++]);
    }
    return res;
  }

  string getString(vector<string> &s) {
    string res;
    for (const string v : s) {
      res += v;
    }
    return res;
  }
};