// 常用数据结构定义
#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE

#include <iostream>
#include <vector>
using namespace std;
// 二叉树
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

// 单链表
struct ListNode {
  int val;
  ListNode *next;
  ListNode();
  ListNode(int x);
  ListNode(int x, ListNode *next);
};

// 双向链表
struct ListNode_Doubleforward {
  int val;
  ListNode_Doubleforward *next;
  ListNode_Doubleforward *prev;
};

class Node {
 public:
  int val;
  Node *next;
  Node *random;
  Node(int _val);
};

struct DLinkedNode {
  int key, value;
  DLinkedNode *prev;
  DLinkedNode *next;
  DLinkedNode();
  DLinkedNode(int _key, int _value);
};

#endif  // DATA_STRUCTURE