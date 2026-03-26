#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 定義顏色枚舉，對應偽代碼中的 WHITE, GRAY, BLACK
enum Color { WHITE, GRAY, BLACK };

// 定義頂點屬性
struct VertexProps {
    Color color;
    int d;      // distance (距離)
    int pi;     // parent/predecessor (父節點/前驅), -1 代表 NIL
};

// BFS 函數實現
// G: 圖的鄰接表 (Adjacency List)
// s: 起始節點 (Source vertex)
void BFS(const vector<vector<int>>& G, int s) {
    int n = G.size(); // 頂點數量
    vector<VertexProps> vertices(n);

    // 1-4 lines: 初始化除 s 以外的所有頂點
    // for each vertex u in G.V - {s}
    for (int u = 0; u < n; ++u) {
        if (u == s) continue;
        vertices[u].color = WHITE;
        vertices[u].d = numeric_limits<int>::max(); // infinity
        vertices[u].pi = -1; // NIL
    }

    // 5-7 lines: 初始化起始節點 s
    vertices[s].color = GRAY;
    vertices[s].d = 0;
    vertices[s].pi = -1; // NIL

    // 8 line: Q = empty
    queue<int> Q;

    // 9 line: ENQUEUE(Q, s)
    Q.push(s);

    cout << "BFS Traversal Order (starting from " << s << "):" << endl;

    // 10 line: while Q is not empty
    while (!Q.empty()) {
        // 11 line: u = DEQUEUE(Q)
        int u = Q.front();
        Q.pop();

        // 這裡可以打印訪問順序
        cout << "Visited " << u << " (Distance: " << vertices[u].d << ")" << endl;

        // 12 line: for each v in G.Adj[u]
        for (int v : G[u]) {
            // 13 line: if v.color == WHITE
            if (vertices[v].color == WHITE) {
                // 14 line: v.color = GRAY
                vertices[v].color = GRAY;
                // 15 line: v.d = u.d + 1
                vertices[v].d = vertices[u].d + 1;
                // 16 line: v.pi = u
                vertices[v].pi = u;
                // 17 line: ENQUEUE(Q, v)
                Q.push(v);
            }
        }
        // 18 line: u.color = BLACK
        vertices[u].color = BLACK;
    }
}

int main() {
    // 建立一個範例圖來測試
    // 假設有 6 個節點 (0 到 5)
    int num_vertices = 6;
    vector<vector<int>> adj(num_vertices);

    // 添加邊 (無向圖範例)
    // 0 -- 1
    // |    |
    // 2 -- 3 -- 4 -- 5
    
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);

    // 執行 BFS
    BFS(adj, 0);

    return 0;
}
