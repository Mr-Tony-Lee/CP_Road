#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 定義顏色枚舉
enum Color { WHITE, GRAY, BLACK };

// 定義頂點屬性
struct VertexProps {
    Color color;
    int d;      // discovery time
    int f;      // finish time
    int pi;     // parent
};

int time_counter = 0;

// 第一次 DFS: 計算完成時間並將節點推入堆疊 (模擬完成時間排序)
void DFS_FirstPass(const vector<vector<int>>& G, int u, vector<VertexProps>& vertices, stack<int>& finishStack) {
    time_counter++;
    vertices[u].d = time_counter;
    vertices[u].color = GRAY;

    for (int v : G[u]) {
        if (vertices[v].color == WHITE) {
            vertices[v].pi = u;
            DFS_FirstPass(G, v, vertices, finishStack);
        }
    }

    vertices[u].color = BLACK;
    time_counter++;
    vertices[u].f = time_counter;
    
    // 將完成的節點推入堆疊，這樣堆疊頂部就是完成時間最晚的節點
    finishStack.push(u);
}

// 第二次 DFS: 在轉置圖上尋找 SCC
void DFS_SecondPass(const vector<vector<int>>& GT, int u, vector<VertexProps>& vertices, vector<int>& currentSCC) {
    vertices[u].color = GRAY; // 標記為已訪問 (在第二次 DFS 中，我們只關心是否訪問過)
    currentSCC.push_back(u);  // 將節點加入當前 SCC

    for (int v : GT[u]) {
        if (vertices[v].color == WHITE) {
            DFS_SecondPass(GT, v, vertices, currentSCC);
        }
    }
    vertices[u].color = BLACK;
}

// 計算轉置圖 G^T
vector<vector<int>> GetTranspose(const vector<vector<int>>& G) {
    int n = G.size();
    vector<vector<int>> GT(n);
    for (int u = 0; u < n; ++u) {
        for (int v : G[u]) {
            GT[v].push_back(u); // 反轉邊的方向: u->v 變成 v->u
        }
    }
    return GT;
}

// Strongly Connected Components 算法 (Kosaraju's Algorithm)
void StronglyConnectedComponents(const vector<vector<int>>& G) {
    int n = G.size();
    vector<VertexProps> vertices(n);
    stack<int> finishStack;

    // 1. Call DFS(G) to compute finishing times u.f
    for (int u = 0; u < n; ++u) {
        vertices[u].color = WHITE;
        vertices[u].pi = -1;
    }
    time_counter = 0;

    for (int u = 0; u < n; ++u) {
        if (vertices[u].color == WHITE) {
            DFS_FirstPass(G, u, vertices, finishStack);
        }
    }

    // 2. Compute G^T
    vector<vector<int>> GT = GetTranspose(G);

    // 3. Call DFS(G^T), but in the main loop of DFS, consider the vertices 
    //    in order of decreasing u.f (using the stack)
    
    // 重置頂點屬性以進行第二次 DFS
    for (int u = 0; u < n; ++u) {
        vertices[u].color = WHITE;
        vertices[u].pi = -1;
    }

    cout << "Strongly Connected Components:" << endl;
    int sccCount = 0;

    while (!finishStack.empty()) {
        int u = finishStack.top();
        finishStack.pop();

        if (vertices[u].color == WHITE) {
            sccCount++;
            vector<int> currentSCC;
            // 4. Output the vertices of each tree in the depth-first forest formed in line 3
            DFS_SecondPass(GT, u, vertices, currentSCC);
            
            cout << "SCC #" << sccCount << ": { ";
            for (int v : currentSCC) {
                cout << v << " ";
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    // 建立教科書 Figure 22.9 的範例圖
    // 節點: a(0), b(1), c(2), d(3), e(4), f(5), g(6), h(7)
    int num_vertices = 8;
    vector<vector<int>> adj(num_vertices);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
    };

    // 邊的定義
    addEdge(0, 1); // a -> b
    addEdge(1, 2); // b -> c
    addEdge(1, 4); // b -> e
    addEdge(1, 5); // b -> f
    addEdge(2, 3); // c -> d
    addEdge(2, 6); // c -> g
    addEdge(3, 2); // d -> c
    addEdge(3, 7); // d -> h
    addEdge(4, 0); // e -> a
    addEdge(4, 5); // e -> f
    addEdge(5, 6); // f -> g
    addEdge(6, 5); // g -> f
    addEdge(6, 7); // g -> h
    addEdge(7, 7); // h -> h (self loop)

    // 節點名稱映射 (為了輸出好看)
    vector<char> names = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    
    cout << "Graph Structure (Figure 22.9):" << endl;
    cout << "a(0), b(1), c(2), d(3), e(4), f(5), g(6), h(7)" << endl << endl;

    StronglyConnectedComponents(adj);

    return 0;
}
