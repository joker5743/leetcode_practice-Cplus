// 676. 实现一个魔法字典

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

// 方法二定义的字典树数据结构
struct Trie {
  bool is_finished;
  Trie *child[26];

  Trie() {
    is_finished = false;
    fill(begin(child), end(child), nullptr);
  }
};

class MagicDictionary {
 private:
  vector<string> words;
  Trie *root;

 public:
  // 1. 模拟
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) { words = dictionary; }

  bool search(string searchWord) {
    for (auto &&word : words) {
      if (word.size() != searchWord.size()) {
        continue;
      }

      int diff = 0;
      for (int i = 0; i < word.size(); i++) {
        if (word[i] != searchWord[i]) {
          ++diff;
        }
        if (diff > 1) {
          break;
        }
      }
      if (diff == 1) {
        return true;
      }
    }

    return false;
  }

  // 2. 用字典树优化
  MagicDictionary() { root = new Trie(); }

  void buildDict(vector<string> dictionary) {
    for (auto &&word : dictionary) {
      Trie *cur = root;
      // 构造一个单词的字典树
      for (char ch : word) {
        int idx = ch - 'a';
        if (!cur->child[idx]) {
          cur->child[idx] = new Trie();
        }
        cur = cur->child[idx];
      }
      cur->is_finished = true;
    }
  }

  bool search(string searchWord) {
    function<bool(Trie *, int, bool)> dfs = [&](Trie *node, int pos,
                                                bool modified) {
      if (pos == searchWord.size()) {
        return modified && node->is_finished;
      }
      int idx = searchWord[pos] - 'a';
      // 不执行修改，递归查询
      if (node->child[idx]) {
        if (dfs(node->child[idx], pos + 1, modified)) {
          return true;
        }
      }
      // 没有修改过，在这一层开始执行修改，并递归判断是否符合要求
      if (!modified) {
        for (int i = 0; i < 26; ++i) {
          // 被修改之后，存在于已有词典则返回true
          if (i != idx && node->child[i]) {
            if (dfs(node->child[i], pos + 1, true)) {
              return true;
            }
          }
        }
      }
      return false;
    };

    return dfs(root, 0, false);
  }
};