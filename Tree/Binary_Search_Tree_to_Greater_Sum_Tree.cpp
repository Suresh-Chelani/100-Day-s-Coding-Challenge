#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // using simple iteration...

 class Solution
 {
 public:
     int sm = 0;
     void solve(TreeNode *root)
     {
         if (!root)
             return;

         solve(root->right);
         sm += root->val;
         root->val = sm;
         solve(root->left);
     }
     TreeNode *bstToGst(TreeNode *root)
     {
         solve(root);
         return root;
     }
};

// using the map...
/*
class Solution
{
public:
    unordered_map<int, int> mp;
    vector<int> vec;
    void solve(TreeNode *node)
    {
        if (!node)
            return;
        solve(node->left);
        mp[node->val] = node->val;
        vec.push_back(node->val);
        solve(node->right);
    }
    void modifyroot(TreeNode *root, unordered_map<int, int> &mp)
    {
        if (!root)
            return;

        modifyroot(root->left, mp);
        root->val = mp[root->val];
        modifyroot(root->right, mp);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        solve(root);
        int sm = 0;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            sm += vec[i];
            mp[vec[i]] = sm;
        }

        modifyroot(root, mp);
        return root;
    }
};

*/