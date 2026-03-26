# Depth-First Search (DFS)

這份文件記錄了深度優先搜尋 (Depth-First Search, DFS) 的實作細節，對應於 `DFS.cpp` 程式碼。

## 演算法簡介

DFS 是一種用於遍歷或搜尋樹或圖的演算法。這個演算法會盡可能深地搜索樹的分支。當節點 `v` 的所在邊都已被探尋過，搜索將回溯到發現節點 `v` 的那條邊的始節點。這個過程一直進行到已發現從源節點可達的所有節點為止。如果還存在未被發現的節點，則選擇其中一個作為源節點並重複以上過程，整個進程反覆進行直到所有節點都被訪問為止。

## 偽代碼與 C++ 實作對照

下表展示了教科書偽代碼 (Pseudocode) 與本專案 C++ 實作的對應關係：

### DFS(G)

| 偽代碼 (Pseudocode) | C++ 實作 (`DFS.cpp`) | 說明 |
| :--- | :--- | :--- |
| **Initialization** | | |
| `for each vertex u ∈ G.V` | `for (int u = 0; u < n; ++u)` | 遍歷所有節點 |
| `u.color = WHITE` | `vertices[u].color = WHITE;` | 初始化顏色為未訪問 |
| `u.pi = NIL` | `vertices[u].pi = -1;` | 初始化前驅為 NIL |
| `time = 0` | `time_counter = 0;` | 初始化全局時間計數器 |
| **Main Loop** | | |
| `for each vertex u ∈ G.V` | `for (int u = 0; u < n; ++u)` | 再次遍歷所有節點，確保非連通圖也能完全訪問 |
| `if u.color == WHITE` | `if (vertices[u].color == WHITE)` | 若節點未被訪問 |
| `DFS-VISIT(G, u)` | `DFS_VISIT(G, u, vertices);` | 對該節點進行深度優先訪問 |

### DFS-VISIT(G, u)

| 偽代碼 (Pseudocode) | C++ 實作 (`DFS.cpp`) | 說明 |
| :--- | :--- | :--- |
| `time = time + 1` | `time_counter = time_counter + 1;` | 時間推進 |
| `u.d = time` | `vertices[u].d = time_counter;` | 記錄發現時間 (Discovery time) |
| `u.color = GRAY` | `vertices[u].color = GRAY;` | 標記為正在訪問 (Gray) |
| `for each v ∈ G.Adj[u]` | `for (int v : G[u])` | 遍歷鄰居節點 |
| `if v.color == WHITE` | `if (vertices[v].color == WHITE)` | 若鄰居未被訪問 (Tree Edge) |
| `v.pi = u` | `vertices[v].pi = u;` | 記錄父節點 |
| `DFS-VISIT(G, v)` | `DFS_VISIT(G, v, vertices);` | 遞迴訪問鄰居 |
| `u.color = BLACK` | `vertices[u].color = BLACK;` | 標記為已完成 (Black) |
| `time = time + 1` | `time_counter = time_counter + 1;` | 時間推進 |
| `u.f = time` | `vertices[u].f = time_counter;` | 記錄完成時間 (Finish time) |

## 程式碼結構

### 1. 顏色定義 (`enum Color`)
- `WHITE`: 未訪問
- `GRAY`: 已發現 (Discovered)，正在探索其鄰居
- `BLACK`: 已完成 (Finished)，其所有鄰居都已探索完畢

### 2. 節點屬性 (`struct VertexProps`)
- `color`: 節點顏色
- `d`: 發現時間 (Discovery time)，節點第一次由白變灰的時間
- `f`: 完成時間 (Finish time)，節點由灰變黑的時間
- `pi`: 前驅節點 (Parent)

### 3. 全局變數
- `time_counter`: 用於記錄 DFS 過程中的邏輯時間步。

## 執行範例

程式碼中內建了一個有向圖範例：

```text
0 -> 1, 3
1 -> 4
2 -> 4, 5
3 -> 1
4 -> 3
5 -> 5
```

### 預期輸出

```text
Starting DFS...
Discovering 0 at time 1
Discovering 1 at time 2
Discovering 4 at time 3
Discovering 3 at time 4
Finished 3 at time 5
Finished 4 at time 6
Finished 1 at time 7
Finished 0 at time 8
Discovering 2 at time 9
Finished 2 at time 10
Discovering 5 at time 11
Finished 5 at time 12

Final Result:
Vertex | Discovery (d) | Finish (f) | Parent (pi)
-------|---------------|------------|------------
     0 |             1 |          8 |         -1
     1 |             2 |          7 |          0
     2 |             9 |         10 |         -1
     3 |             4 |          5 |          4
     4 |             3 |          6 |          1
     5 |            11 |         12 |         -1
```

## 如何編譯與執行

```bash
# 編譯
g++ DFS.cpp -o DFS

# 執行
./DFS
```
