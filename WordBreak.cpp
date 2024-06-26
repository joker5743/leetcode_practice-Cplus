// 139. 单词拆分

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class WordBreak {
 private:
  /* data */
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordDictSet;
    wordDictSet.clear();
    for (const string &word : wordDict) {
      wordDictSet.insert(word);
    }

    auto dp = vector<bool>(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] &&
            wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};