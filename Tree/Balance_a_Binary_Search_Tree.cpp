#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
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
    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        vector<TreeNode *> inorderTraversal;
        inorder(root, inorderTraversal);
        return solve(inorderTraversal, 0, inorderTraversal.size() - 1);
    }

private:
    void inorder(TreeNode *root, vector<TreeNode *> &nodes)
    {
        if (root == nullptr)
            return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    TreeNode *solve(const vector<TreeNode *> &nodes, int start, int end)
    {
        if (end < start)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *root = nodes[mid];
        root->left = solve(nodes, start, mid - 1);
        root->right = solve(nodes, mid + 1, end);
        return root;
    }
};