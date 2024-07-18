#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *dfs(TreeNode *root, unordered_map<int, bool> &mp, vector<TreeNode *> &ans)
    {
        if (!root)
            return root;

        root->left = dfs(root->left, mp, ans);
        root->right = dfs(root->right, mp, ans);

        if (mp[root->val])
        {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            return nullptr;
        }

        return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_map<int, bool> mp;
        vector<TreeNode *> ans;
        for (int val : to_delete)
            mp[val] = true;
        root = dfs(root, mp, ans);
        if (root)
            ans.push_back(root);
        return ans;
    }
};