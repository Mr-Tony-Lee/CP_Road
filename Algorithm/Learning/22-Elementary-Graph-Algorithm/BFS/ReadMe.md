# Breadth-First Search (BFS)

這份文件記錄了廣度優先搜尋 (Breadth-First Search, BFS) 的實作細節，對應於 `BFS.cpp` 程式碼。

## 演算法簡介

BFS 是一種用於遍歷或搜尋樹或圖的演算法。它從樹的根（或圖的某個任意節點）開始，並在移動到下一層級的鄰居節點之前，先探索鄰居節點。

## 偽代碼與 C++ 實作對照

下表展示了教科書偽代碼 (Pseudocode) 與本專案 C++ 實作的對應關係：

| 偽代碼 (Pseudocode) | C++ 實作 (`BFS.cpp`) | 說明 |
| :--- | :--- | :--- |
| **Initialization** | | |
| `for each vertex u ∈ G.V - {s}` | `for (int u = 0; u < n; ++u)` | 初始化所有節點 |
| `u.color = WHITE` | `vertices[u].color = WHITE;` | 設定為未訪問 |
| `u.d = ∞` | `vertices[u].d = numeric_limits<int>::max();` | 距離設為無限大 |
| `u.pi = NIL` | `vertices[u].pi = -1;` | 前驅節點設為 -1 (NIL) |
| `s.color = GRAY` | `vertices[s].color = GRAY;` | 起始點設為待處理 |
| `s.d = 0` | `vertices[s].d = 0;` | 起始點距離為 0 |
| `Q = Ø` | `queue<int> Q;` | 初始化佇列 |
| `ENQUEUE(Q, s)` | `Q.push(s);` | 將起始點加入佇列 |
| **Main Loop** | | |
| `while Q ≠ Ø` | `while (!Q.empty())` | 當佇列不為空時持續執行 |
| `u = DEQUEUE(Q)` | `int u = Q.front(); Q.pop();` | 取出隊頭元素 |
| `for each v ∈ G.Adj[u]` | `for (int v : G[u])` | 遍歷所有鄰居 |
| `if v.color == WHITE` | `if (vertices[v].color == WHITE)` | 若鄰居未被訪問 |
| `v.color = GRAY` | `vertices[v].color = GRAY;` | 標記為待處理 (發現) |
| `v.d = u.d + 1` | `vertices[v].d = vertices[u].d + 1;` | 更新距離 |
| `v.pi = u` | `vertices[v].pi = u;` | 記錄父節點 |
| `ENQUEUE(Q, v)` | `Q.push(v);` | 加入佇列 |
| `u.color = BLACK` | `vertices[u].color = BLACK;` | 標記為已處理 (完成) |

## 程式碼結構

### 1. 顏色定義 (`enum Color`)
使用枚舉來表示節點的三種狀態：
- `WHITE`: 未訪問 (Unvisited)
- `GRAY`: 已發現但未處理完鄰居 (Discovered / Visiting)
- `BLACK`: 已完成 (Finished / Visited)

### 2. 節點屬性 (`struct VertexProps`)
儲存每個節點在 BFS 過程中的狀態：
- `color`: 顏色狀態
- `d`: 從起始點到該節點的距離
- `pi`: 前驅節點 (Parent)，用於重建路徑

### 3. 圖的表示
使用 **鄰接表 (Adjacency List)** `vector<vector<int>>` 來儲存圖結構。

## 執行範例

程式碼中內建了一個簡單的無向圖範例：

```text
    0 -- 1
    |    |
    2 -- 3 -- 4 -- 5
```

### 預期輸出

從節點 `0` 開始進行 BFS 的遍歷順序：

```text
BFS Traversal Order (starting from 0):
Visited 0 (Distance: 0)
Visited 1 (Distance: 1)
Visited 2 (Distance: 1)
Visited 3 (Distance: 2)
Visited 4 (Distance: 3)
Visited 5 (Distance: 4)
```

## 如何編譯與執行

```bash
# 編譯
g++ BFS.cpp -o BFS

# 執行
./BFS
```
