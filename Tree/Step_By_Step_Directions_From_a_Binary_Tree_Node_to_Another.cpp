#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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

// using without LCS only DFS (optimal approach)

class Solution
{
public:
    bool findPath(TreeNode *currentNode, int targetValue, string &path)
    {
        if (currentNode == NULL)
        {
            return false;
        }

        if (currentNode->val == targetValue)
        {
            return true;
        }

        path.push_back('L');
        if (findPath(currentNode->left, targetValue, path) == true)
        {
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if (findPath(currentNode->right, targetValue, path) == true)
        {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {

        string pathToStart = "";
        string pathToDest = "";

        findPath(root, startValue, pathToStart); // O(n)
        findPath(root, destValue, pathToDest);   // O(n)

        int commonPathLength = 0;
        while (commonPathLength < pathToStart.length() && commonPathLength < pathToDest.length() && pathToStart[commonPathLength] == pathToDest[commonPathLength])
        {
            commonPathLength++;
        }

        string result = "";
        // Add "U"
        for (int i = 0; i < pathToStart.length() - commonPathLength; i++)
        {
            result.push_back('U');
        }

        for (int i = commonPathLength; i < pathToDest.length(); i++)
        {
            result.push_back(pathToDest[i]);
        }

        return result;
    }
};

// using LCS with DFS

/*

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int startValue, int destValue) {
        if(!root)
            return NULL;

        if(root->val == startValue || root->val == destValue)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left,  startValue, destValue);
        TreeNode* right = lowestCommonAncestor(root->right, startValue, destValue);

        if(left && right)
            return root;

        return left ? left : right;
    }

    bool findPath(TreeNode* currentNode, int targetValue, string& path) {
        if(currentNode == NULL) {
            return false;
        }

        if(currentNode->val == targetValue) {
            return true;
        }

        path.push_back('L');
        if(findPath(currentNode->left, targetValue, path) == true) {
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(currentNode->right, targetValue, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lowestCommonAncestor(root, startValue, destValue);

        string pathToStart  = "";
        string pathToDest = "";

        findPath(lcaNode, startValue, pathToStart);
        findPath(lcaNode, destValue, pathToDest);

        string result = "";

        for(int i = 0; i < pathToStart.length(); i++) {
            result.push_back('U');
        }

        result += pathToDest;

        return result;
    }
};


*/

// using building the graph from tree or (add the path from child to parent)
/*

class Solution {
public:
    void build(unordered_map<int, vector<pair<int, char>>>& adj, set<int>& visited, TreeNode* node) {
        if(!node or visited.find(node -> val) != visited.end())
            return;
        visited.insert(node -> val);
        if(node -> left) {
            adj[node -> val].push_back({node -> left -> val, 'L'});
            adj[node -> left -> val].push_back({node -> val, 'U'});
            build(adj, visited, node -> left);
        }
        if(node -> right) {
            adj[node -> val].push_back({node -> right -> val, 'R'});
            adj[node -> right -> val].push_back({node -> val, 'U'});
            build(adj, visited, node -> right);
        }
    }
    string getDirections(TreeNode* root, int start, int dest) {
        unordered_map<int, vector<pair<int, char>>> adj;
        set<int> visited;
        build(adj, visited, root);
        queue<pair<int, string>> q;
        visited.clear();
        q.push({start, ""});
        visited.insert(start);
        while(!q.empty()) {
            int node = q.front().first;
            string s = q.front().second;
            q.pop();
            if(node == dest)
                return s;
            for(auto adjNode : adj[node]) {
                if(visited.find(adjNode.first) == visited.end()) {
                    q.push({adjNode.first, s + adjNode.second});
                    visited.insert(adjNode.first);
                }
            }
        }
        return "";
    }
};

*/