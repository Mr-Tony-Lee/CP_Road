# Kruskal's Algorithm for Minimum Spanning Tree

這份文件記錄了 Kruskal 演算法的實作細節，對應於 `main.cpp` 程式碼。

## 演算法簡介

Kruskal 演算法是一種用來尋找加權無向圖的 **最小生成樹 (Minimum Spanning Tree, MST)** 的貪婪演算法。

它的核心思想是：
1.  將所有邊按照權重從小到大排序。
2.  依序遍歷每條邊，如果這條邊連接的兩個節點屬於不同的連通分量（即不會形成環），則將這條邊加入 MST。
3.  重複直到選出了 $V-1$ 條邊或遍歷完所有邊。

為了高效地判斷兩個節點是否屬於同一個連通分量以及合併連通分量，我們使用了 **互斥集 (Disjoint Set Union, DSU)** 資料結構。

## 偽代碼與 C++ 實作對照

下表展示了教科書偽代碼 (Pseudocode) 與本專案 C++ 實作的對應關係：

### MST-KRUSKAL(G, w)

| 偽代碼 (Pseudocode) | C++ 實作 (`main.cpp`) | 說明 |
| :--- | :--- | :--- |
| `A = Ø` | `vector<Edge> A;` | 初始化 MST 邊集合為空 |
| `for each vertex v ∈ G.V` | `DisjointSet dsu(n);` | 初始化 DSU |
| `MAKE-SET(v)` | `parent[i] = i;` | 每個節點初始為獨立集合 |
| `sort the edges of G.E ...` | `sort(edges.begin(), ...)` | 將邊按權重排序 |
| `for each edge (u, v) ∈ G.E ...` | `for (const auto& edge : edges)` | 遍歷排序後的邊 |
| `if FIND-SET(u) ≠ FIND-SET(v)` | `if (dsu.findSet(edge.u) != dsu.findSet(edge.v))` | 檢查是否形成環 |
| `A = A ∪ {(u, v)}` | `A.push_back(edge);` | 加入 MST |
| `UNION(u, v)` | `dsu.unionSets(edge.u, edge.v);` | 合併兩個集合 |
| `return A` | `return A;` | 返回結果 |

## 資料結構：Disjoint Set Union (DSU)

為了達到高效的執行速度，DSU 實作了兩個優化：
1.  **路徑壓縮 (Path Compression)**: 在 `findSet` 時，將路徑上的所有節點直接指向根節點，降低樹的高度。
2.  **按秩合併 (Union by Rank)**: 在 `unionSets` 時，將較矮的樹合併到較高的樹下，避免樹變得過深。

## 執行範例

程式碼中實作了教科書 Figure 23.4 的範例圖。

### 預期輸出

演算法應該選擇以下邊（順序可能因排序穩定性略有不同，但總權重應為 37）：

```text
Running Kruskal's Algorithm...
Minimum Spanning Tree Edges:
g -- h (Weight: 1)
c -- i (Weight: 2)
f -- g (Weight: 2)
a -- b (Weight: 4)
c -- f (Weight: 4)
c -- d (Weight: 7)
a -- h (Weight: 8)
d -- e (Weight: 9)
Total Weight of MST: 37
```

## 如何編譯與執行

```bash
# 編譯
g++ main.cpp -o Kruskal

# 執行
./Kruskal
```
