#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> nodeMap;
        unordered_set<int> children;

        for (const auto &desc : descriptions)
        {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            if (nodeMap.find(parentVal) == nodeMap.end())
            {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }

            if (nodeMap.find(childVal) == nodeMap.end())
            {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            if (isLeft)
            {
                nodeMap[parentVal]->left = nodeMap[childVal];
            }
            else
            {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            children.insert(childVal);
        }

        TreeNode *root = nullptr;
        for (const auto &node : nodeMap)
        {
            if (children.find(node.first) == children.end())
            {
                root = node.second;
                break;
            }
        }

        return root;
    }
};
