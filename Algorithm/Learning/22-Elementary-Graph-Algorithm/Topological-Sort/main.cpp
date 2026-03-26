#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

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

// DFS-VISIT 函數
// G: 圖的鄰接表
// u: 當前節點
// vertices: 節點屬性
// topo_list: 用於存儲拓撲排序結果的鏈結串列
void DFS_VISIT(const vector<vector<int>>& G, int u, vector<VertexProps>& vertices, list<int>& topo_list) {
    time_counter++;
    vertices[u].d = time_counter;
    vertices[u].color = GRAY;

    for (int v : G[u]) {
        if (vertices[v].color == WHITE) {
            vertices[v].pi = u;
            DFS_VISIT(G, v, vertices, topo_list);
        }
    }

    vertices[u].color = BLACK;
    time_counter++;
    vertices[u].f = time_counter;

    // 關鍵步驟：當節點完成時，將其插入到鏈結串列的前端
    // "as each vertex is finished, insert it onto the front of a linked list"
    topo_list.push_front(u);
}

// Topological Sort 函數
// 實際上就是執行 DFS，並在節點完成時收集結果
list<int> TopologicalSort(const vector<vector<int>>& G) {
    int n = G.size();
    vector<VertexProps> vertices(n);
    list<int> topo_list;

    // 初始化
    for (int u = 0; u < n; ++u) {
        vertices[u].color = WHITE;
        vertices[u].pi = -1;
    }
    time_counter = 0;

    // 對每個節點執行 DFS
    for (int u = 0; u < n; ++u) {
        if (vertices[u].color == WHITE) {
            DFS_VISIT(G, u, vertices, topo_list);
        }
    }

    return topo_list;
}

int main() {
    // 建立教科書 Figure 22.7 的範例 (Professor Bumstead's clothing)
    // 映射名稱到索引
    map<string, int> name_to_id = {
        {"undershorts", 0}, {"pants", 1}, {"belt", 2},
        {"shirt", 3},       {"tie", 4},   {"jacket", 5},
        {"socks", 6},       {"shoes", 7}, {"watch", 8}
    };
    
    // 映射索引回名稱以便輸出
    vector<string> id_to_name(9);
    for (auto const& [name, id] : name_to_id) {
        id_to_name[id] = name;
    }

    int num_vertices = 9;
    vector<vector<int>> adj(num_vertices);

    auto addEdge = [&](string u_name, string v_name) {
        adj[name_to_id[u_name]].push_back(name_to_id[v_name]);
    };

    // 根據 Figure 22.7 (a) 添加邊
    addEdge("undershorts", "pants");
    addEdge("undershorts", "shoes");
    addEdge("pants", "belt");
    addEdge("pants", "shoes");
    addEdge("belt", "jacket");
    addEdge("shirt", "belt");
    addEdge("shirt", "tie");
    addEdge("tie", "jacket");
    addEdge("socks", "shoes");
    // watch 是獨立的，沒有出邊

    cout << "Performing Topological Sort on Professor Bumstead's clothing graph..." << endl;

    list<int> sorted_order = TopologicalSort(adj);

    cout << "\nTopological Sort Result (Order of dressing):" << endl;
    int count = 0;
    for (int id : sorted_order) {
        cout << ++count << ". " << id_to_name[id] << endl;
    }

    return 0;
}
