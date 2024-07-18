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
    int countPairs(TreeNode *root, int distance)
    {
        unordered_map<TreeNode *, vector<TreeNode *>> map;
        vector<TreeNode *> leaves;
        rootToleave(root, {}, leaves, map);
        int res = 0;
        for (int p = 0; p < leaves.size(); p++)
        {
            for (int q = p + 1; q < leaves.size(); q++)
            {
                vector<TreeNode *> &i = map[leaves[p]];
                vector<TreeNode *> &j = map[leaves[q]];
                for (int k = 0; k < min(i.size(), j.size()); k++)
                {
                    if (i[k] != j[k])
                    {
                        int dist = i.size() - k + j.size() - k;
                        if (dist <= distance)
                            res++;
                        break;
                    }
                }
            }
        }
        return res;
    }

private:
    void rootToleave(TreeNode *node, vector<TreeNode *> trail, vector<TreeNode *> &leaves, unordered_map<TreeNode *, vector<TreeNode *>> &map)
    {
        if (!node)
            return;
        vector<TreeNode *> tmp(trail);
        tmp.push_back(node);
        if (!node->left && !node->right)
        {
            map[node] = tmp;
            leaves.push_back(node);
            return;
        }
        rootToleave(node->left, tmp, leaves, map);
        rootToleave(node->right, tmp, leaves, map);
    }
};