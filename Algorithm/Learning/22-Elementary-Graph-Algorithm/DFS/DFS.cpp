#include <iostream>
#include <vector>
#include <iomanip> // for setw

using namespace std;

// 定義顏色枚舉，對應偽代碼中的 WHITE, GRAY, BLACK
enum Color { WHITE, GRAY, BLACK };

// 定義頂點屬性
struct VertexProps {
    Color color;
    int d;      // discovery time (發現時間)
    int f;      // finish time (完成時間)
    int pi;     // parent/predecessor (父節點/前驅), -1 代表 NIL
};

// 全局時間變數 (對應偽代碼中的 time)
int time_counter = 0;

// DFS-VISIT 函數實現
// G: 圖的鄰接表
// u: 當前訪問的節點索引
// vertices: 儲存所有節點屬性的陣列 (傳引用)
void DFS_VISIT(const vector<vector<int>>& G, int u, vector<VertexProps>& vertices) {
    // 1 line: time = time + 1
    time_counter = time_counter + 1;
    
    // 2 line: u.d = time
    vertices[u].d = time_counter;
    
    // 3 line: u.color = GRAY
    vertices[u].color = GRAY;

    cout << "Discovering " << u << " at time " << vertices[u].d << endl;

    // 4 line: for each v in G.Adj[u]
    for (int v : G[u]) {
        // 5 line: if v.color == WHITE
        if (vertices[v].color == WHITE) {
            // 6 line: v.pi = u
            vertices[v].pi = u;
            // 7 line: DFS-VISIT(G, v)
            DFS_VISIT(G, v, vertices);
        }
    }

    // 8 line: u.color = BLACK
    vertices[u].color = BLACK;

    // 9 line: time = time + 1
    time_counter = time_counter + 1;

    // 10 line: u.f = time
    vertices[u].f = time_counter;

    cout << "Finished " << u << " at time " << vertices[u].f << endl;
}

// DFS 函數實現
// G: 圖的鄰接表
void DFS(const vector<vector<int>>& G) {
    int n = G.size(); // 頂點數量
    vector<VertexProps> vertices(n);

    // 1-3 lines: 初始化所有頂點
    // for each vertex u in G.V
    for (int u = 0; u < n; ++u) {
        vertices[u].color = WHITE;
        vertices[u].pi = -1; // NIL
    }

    // 4 line: time = 0
    time_counter = 0;

    // 5 line: for each vertex u in G.V
    for (int u = 0; u < n; ++u) {
        // 6 line: if u.color == WHITE
        if (vertices[u].color == WHITE) {
            // 7 line: DFS-VISIT(G, u)
            DFS_VISIT(G, u, vertices);
        }
    }

    // 輸出最終結果表格
    cout << "\nFinal Result:" << endl;
    cout << "Vertex | Discovery (d) | Finish (f) | Parent (pi)" << endl;
    cout << "-------|---------------|------------|------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(6) << i << " | " 
             << setw(13) << vertices[i].d << " | " 
             << setw(10) << vertices[i].f << " | " 
             << setw(10) << vertices[i].pi << endl;
    }
}

int main() {
    // 建立一個範例圖來測試 (有向圖範例，更能體現 DFS 特性)
    // 0 -> 1, 0 -> 3
    // 1 -> 4
    // 2 -> 4, 2 -> 5
    // 3 -> 1
    // 4 -> 3
    // 5 -> 5 (self loop)
    
    int num_vertices = 6;
    vector<vector<int>> adj(num_vertices);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
    };

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 1);
    addEdge(4, 3);
    addEdge(5, 5);

    cout << "Starting DFS..." << endl;
    DFS(adj);

    return 0;
}
