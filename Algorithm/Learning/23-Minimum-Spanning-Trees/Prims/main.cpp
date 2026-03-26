#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// 邊結構 (用於鄰接表)
struct Edge {
    int to;
    int weight;
};

// 頂點屬性
struct VertexProps {
    int key;    // 到 MST 的最小權重
    int pi;     // parent in MST
    bool inQ;   // 是否還在優先佇列 Q 中 (尚未加入 MST)
};

// Prim's Algorithm
void MST_Prim(const vector<vector<Edge>>& G, int r) {
    int n = G.size();
    vector<VertexProps> vertices(n);

    // 1-3 lines: Initialization
    for (int u = 0; u < n; ++u) {
        vertices[u].key = INF;
        vertices[u].pi = -1; // NIL
        vertices[u].inQ = true; // 初始時所有點都在 Q 中
    }

    // 4 line: r.key = 0
    vertices[r].key = 0;

    // 5 line: Q = G.V
    // 使用 min-priority queue 模擬 Q
    // 存儲 pair<key, vertex>，以便快速取出 key 最小的頂點
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    
    // 將起始點加入 PQ
    Q.push({0, r});

    // 由於 C++ STL priority_queue 不支援 decrease-key 操作
    // 我們使用 "lazy deletion" 策略：
    // 當更新 key 時，直接 push 新的 pair 進去。
    // 取出時檢查該頂點是否已經被處理過 (不在 Q 中了)。
    // 這裡的 vertices[u].inQ 邏輯上對應偽代碼的 "v in Q"

    // 6 line: while Q != empty
    while (!Q.empty()) {
        // 7 line: u = EXTRACT-MIN(Q)
        int u = Q.top().second;
        Q.pop();

        // 如果 u 已經被處理過 (即已經從 Q 中正式移除了)，則跳過
        // 這是因為 lazy deletion 會導致 PQ 中有多個同一個頂點的紀錄
        if (!vertices[u].inQ) {
            continue;
        }

        // 標記 u 已離開 Q (加入 MST)
        vertices[u].inQ = false;

        // 8 line: for each v in G.Adj[u]
        for (const auto& edge : G[u]) {
            int v = edge.to;
            int w = edge.weight;

            // 9 line: if v in Q and w(u, v) < v.key
            if (vertices[v].inQ && w < vertices[v].key) {
                // 10 line: v.pi = u
                vertices[v].pi = u;
                // 11 line: v.key = w(u, v)
                vertices[v].key = w;
                
                // 更新 PQ (push 新的值進去)
                Q.push({vertices[v].key, v});
            }
        }
    }

    // 輸出結果
    cout << "Minimum Spanning Tree Edges (Prim's Algorithm starting from node " << r << "):" << endl;
    int total_weight = 0;
    // 節點名稱映射 (假設是 a-i)
    char nodes[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    for (int i = 0; i < n; ++i) {
        if (vertices[i].pi != -1) {
            cout << nodes[vertices[i].pi] << " -- " << nodes[i] 
                 << " (Weight: " << vertices[i].key << ")" << endl;
            total_weight += vertices[i].key;
        }
    }
    cout << "Total Weight of MST: " << total_weight << endl;
}

int main() {
    // 建立 CLRS Figure 23.4 的範例圖
    // 節點映射: a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8
    int num_vertices = 9;
    vector<vector<Edge>> adj(num_vertices);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 4);  // a-b
    addEdge(0, 7, 8);  // a-h
    addEdge(1, 2, 8);  // b-c
    addEdge(1, 7, 11); // b-h
    addEdge(2, 3, 7);  // c-d
    addEdge(2, 5, 4);  // c-f
    addEdge(2, 8, 2);  // c-i
    addEdge(3, 4, 9);  // d-e
    addEdge(3, 5, 14); // d-f
    addEdge(4, 5, 10); // e-f
    addEdge(5, 6, 2);  // f-g
    addEdge(6, 7, 1);  // g-h
    addEdge(6, 8, 6);  // g-i
    addEdge(7, 8, 7);  // h-i

    cout << "Running Prim's Algorithm..." << endl;
    // 從節點 'a' (0) 開始
    MST_Prim(adj, 0);

    return 0;
}
