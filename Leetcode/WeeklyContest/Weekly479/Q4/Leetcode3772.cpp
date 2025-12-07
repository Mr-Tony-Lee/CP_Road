#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;    // adjacency list
    vector<int> v;  // v[i] = 1 if values[i] == 1 else -1
    vector<int> dp; // dp[u] 代表以 u 為根，且僅包含其子樹節點的連通子圖最佳分數
    vector<int> ans; // ans[i] 即為包含節點 i 的任意連通子圖的最大可能分數

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& values) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        v.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i] = (values[i] == 1) ? 1 : -1;
        }

        dp.assign(n, 0);
        ans.assign(n, 0);

        dfsB(0, -1);
        ans[0] = dp[0];
        dfsT(0, -1);

        return ans;
    }
    // Bottom-up DFS to compute dp values
    void dfsB(int u, int p) {
        dp[u] = v[u];
        for (int neighbor : adj[u]) {   // traverse all neighbors
            if (neighbor != p) {    // avoid traversing back to parent
                dfsB(neighbor, u);  
                if (dp[neighbor] > 0) { // only add positive contributions
                    dp[u] += dp[neighbor];
                }
            }
        }
    }

    void dfsT(int u, int p) {
        for (int neighbor : adj[u]) {   // 對於每個子節點 v，計算當樹以 v 為 "根" 時的最佳分數
            if (neighbor != p) {
                // ans[u] 是包含 u 的最佳解
                // 我們要算給 neighbor 的貢獻，必須從 ans[u] 中扣除 neighbor 原本貢獻給 u 的部分
                // neighbor 原本貢獻給 u 的是 max(0, dp[neighbor])
                int contributionFromParent = ans[u] - max(0, dp[neighbor]);
                
                // dp[neighbor] 是 neighbor 自己的子樹最佳解
                // 加上父節點方向的貢獻（如果是正的）
                ans[neighbor] = dp[neighbor] + max(0, contributionFromParent);
                
                dfsT(neighbor, u);
            }
        }
    }
};
