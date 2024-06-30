#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &graph,
             int &sz, int &curedges)
    {
        vis[node] = 1;
        sz++;
        curedges += graph[node].size();
        for (auto &g : graph[node])
        {
            if (!vis[g])
            {
                dfs(g, vis, graph, sz, curedges);
            }
        }
    }

    bool checkPossible(vector<vector<int>> &graph)
    {
        int n = graph.size() - 1;
        vector<int> vis(n + 1, 0);
        int sz = 0, curedges = 0;
        dfs(1, vis, graph, sz, curedges);
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n + 1), alice(n + 1), bob(n + 1);
        int total = edges.size(), type3 = 0;
        for (auto &e : edges)
        {
            if (e[0] == 3)
            {
                graph[e[1]].push_back(e[2]);
                graph[e[2]].push_back(e[1]);
                alice[e[1]].push_back(e[2]);
                alice[e[2]].push_back(e[1]);
                bob[e[1]].push_back(e[2]);
                bob[e[2]].push_back(e[1]);
                type3++;
            }
            if (e[0] == 1)
            {
                alice[e[1]].push_back(e[2]);
                alice[e[2]].push_back(e[1]);
            }
            if (e[0] == 2)
            {
                bob[e[1]].push_back(e[2]);
                bob[e[2]].push_back(e[1]);
            }
        }
        if (!checkPossible(alice))
            return -1;
        if (!checkPossible(bob))
            return -1;
        total = total - type3;
        int components = 0, ans = 0;
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                components++;
                int sz = 0, curedges = 0;
                dfs(i, vis, graph, sz, curedges);
                curedges /= 2;
                ans += curedges - (sz - 1);
            }
        }
        total -= 2 * (components - 1);
        ans += total;
        return ans;
    }
};