#include <bits/stdc++.h>
using namespace std;

vector<int> adj, cnt, visited;

int dfs(int node) {
    if (visited[node]) return 0;  // 已經訪問過，返回 0 避免重複計算
    visited[node] = 1;  // 標記訪問
    int nextNode = adj[node];
    if (nextNode && !visited[nextNode]) {
        cnt[node] = 1 + dfs(nextNode);
    }
    return cnt[node];
}

int main() {
    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n;
        cin >> n;
        
        adj.assign(n + 1, 0);
        cnt.assign(n + 1, -1);
        visited.assign(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u] = v;  // 單向邊
        }
        
        int maxNode = 0, maxReach = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == -1) {  // 這個節點還沒有計算過
                fill(visited.begin(), visited.end(), 0);  // 重置訪問標記
                cnt[i] = dfs(i);  // 計算可到達節點數
            }
            if (cnt[i] > maxReach) {
                maxReach = cnt[i];
                maxNode = i;
            }
        }
        
        cout << "Case " << caseNum << ": " << maxNode << endl;
    }
    return 0;
}
