#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 定義邊結構
struct Edge {
    int u, v, weight;
};

// 比較函數，用於排序邊
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) 結構，用於管理集合
struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // 2-3 lines: MAKE-SET(v) for each vertex v
        // 初始化每個節點為獨立的集合
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // FIND-SET(u) with path compression
    // 查找元素所屬的集合代表，並進行路徑壓縮優化
    int findSet(int u) {
        if (u != parent[u]) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }

    // UNION(u, v) with union by rank
    // 合併兩個集合，並根據秩(rank)進行優化
    void unionSets(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm 實現
vector<Edge> MST_Kruskal(int n, vector<Edge>& edges) {
    // 1 line: A = empty set
    vector<Edge> A;

    // 2-3 lines: MAKE-SET(v)
    // 在 DisjointSet 建構函數中完成
    DisjointSet dsu(n);

    // 4 line: sort the edges of G.E into nondecreasing order by weight w
    sort(edges.begin(), edges.end(), compareEdges);

    // 5 line: for each edge (u, v) in G.E, taken in nondecreasing order by weight
    for (const auto& edge : edges) {
        // 6 line: if FIND-SET(u) != FIND-SET(v)
        if (dsu.findSet(edge.u) != dsu.findSet(edge.v)) {
            // 7 line: A = A U {(u, v)}
            A.push_back(edge);
            // 8 line: UNION(u, v)
            dsu.unionSets(edge.u, edge.v);
        }
    }

    // 9 line: return A
    return A;
}

int main() {
    // 建立 CLRS Figure 23.4 的範例圖
    // 節點映射: a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8
    int num_vertices = 9;
    vector<Edge> edges = {
        {0, 1, 4},  // a-b
        {0, 7, 8},  // a-h
        {1, 2, 8},  // b-c
        {1, 7, 11}, // b-h
        {2, 3, 7},  // c-d
        {2, 5, 4},  // c-f
        {2, 8, 2},  // c-i
        {3, 4, 9},  // d-e
        {3, 5, 14}, // d-f
        {4, 5, 10}, // e-f
        {5, 6, 2},  // f-g
        {6, 7, 1},  // g-h
        {6, 8, 6},  // g-i
        {7, 8, 7}   // h-i
    };

    cout << "Running Kruskal's Algorithm..." << endl;
    vector<Edge> mst = MST_Kruskal(num_vertices, edges);

    cout << "Minimum Spanning Tree Edges:" << endl;
    int total_weight = 0;
    char nodes[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    
    for (const auto& edge : mst) {
        cout << nodes[edge.u] << " -- " << nodes[edge.v] << " (Weight: " << edge.weight << ")" << endl;
        total_weight += edge.weight;
    }
    cout << "Total Weight of MST: " << total_weight << endl;

    return 0;
}
