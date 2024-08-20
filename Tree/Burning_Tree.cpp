#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void solve(Node* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;

        if (root->left) {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);  
        }

        if (root->right) {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);  
        }

        solve(root->left, adj);
        solve(root->right, adj);
    }

    int minTime(Node* root, int target) {
        unordered_map<int, vector<int>> adj;
        solve(root, adj);

        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(target);
        visited[target] = true;

        int level = -1;

        while (!q.empty()) {
            int size = q.size(); 

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            
            level+=1;
        }

        return level;  
    }
};