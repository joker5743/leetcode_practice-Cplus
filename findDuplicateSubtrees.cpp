// 652. 寻找重复的子树
#include"data_structure.cpp"
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class FindDuplicateSubtrees{
public:
    vector<TreeNode*> findDuplicateSubtrees_serial(TreeNode* root) {
        dfs_serial(root);
        return {repeat.begin(),repeat.end()};
    }

    string dfs_serial(TreeNode *root){
        if(!root)
            return "";

        string serial = to_string(root->val) + "(" + dfs_serial(root->left) + ")(" + dfs_serial(root->right) + ")";
        if(auto it = seen.find(serial); it != seen.end())
            repeat.insert(it->second);
        else
            seen[serial] = root;
            
        return serial;
    }

private:
     unordered_map<string, TreeNode*> seen;
     unordered_set<TreeNode*> repeat;
};