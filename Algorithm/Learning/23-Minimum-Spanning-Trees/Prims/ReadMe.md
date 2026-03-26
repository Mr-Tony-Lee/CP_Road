# Prim's Algorithm for Minimum Spanning Tree

這份文件記錄了 Prim 演算法的實作細節，對應於 `main.cpp` 程式碼。

## 演算法簡介

Prim 演算法是一種用來尋找加權無向圖的 **最小生成樹 (Minimum Spanning Tree, MST)** 的貪婪演算法。

它的核心思想是：
1.  從一個起始點 $r$ 開始，將其加入 MST 集合。
2.  在所有連接「MST 集合內節點」與「MST 集合外節點」的邊中，選擇權重最小的一條邊 $(u, v)$。
3.  將該邊的另一端點 $v$ 加入 MST 集合。
4.  重複步驟 2 和 3，直到所有節點都被加入 MST。

Prim 演算法的過程類似於 Dijkstra 演算法，都是利用優先佇列 (Priority Queue) 來選取當前最優的節點。

## 偽代碼與 C++ 實作對照

下表展示了教科書偽代碼 (Pseudocode) 與本專案 C++ 實作的對應關係：

### MST-PRIM(G, w, r)

| 偽代碼 (Pseudocode) | C++ 實作 (`main.cpp`) | 說明 |
| :--- | :--- | :--- |
| `for each u ∈ G.V` | `for (int u = 0; u < n; ++u)` | 初始化 |
| `u.key = ∞` | `vertices[u].key = INF;` | 初始化 key 為無限大 |
| `u.pi = NIL` | `vertices[u].pi = -1;` | 初始化父節點為 NIL |
| `r.key = 0` | `vertices[r].key = 0;` | 起始點 key 設為 0 |
| `Q = G.V` | `priority_queue<...> Q;` | 使用 Min-Priority Queue |
| `while Q ≠ Ø` | `while (!Q.empty())` | 當 Q 不為空 |
| `u = EXTRACT-MIN(Q)` | `u = Q.top().second; Q.pop();` | 取出 key 最小的節點 |
| `for each v ∈ G.Adj[u]` | `for (const auto& edge : G[u])` | 遍歷鄰居 |
| `if v ∈ Q and w(u, v) < v.key` | `if (vertices[v].inQ && w < vertices[v].key)` | 檢查是否需要更新 key |
| `v.pi = u` | `vertices[v].pi = u;` | 更新父節點 |
| `v.key = w(u, v)` | `vertices[v].key = w; Q.push(...)` | 更新 key 並推入 PQ |

### 實作細節：Priority Queue 與 Decrease-Key

標準 C++ STL 的 `priority_queue` 並不支援 `DECREASE-KEY` 操作（即直接修改佇列中某個元素的優先級）。

為了解決這個問題，我們採用 **Lazy Deletion (延遲刪除)** 的策略：
1.  當我們發現一條更短的路徑到達 $v$ 時（即 `w(u, v) < v.key`），我們直接將新的 `{new_key, v}` 推入 Priority Queue。
2.  這樣 PQ 中可能會有同一個節點 $v$ 的多個版本（舊的 key 和新的 key）。
3.  當我們從 PQ 中 `pop` 出一個節點 $u$ 時，我們先檢查它是否已經被處理過（即是否已經加入了 MST）。如果是，則忽略這個舊的紀錄 (`continue`)。
4.  我們使用 `vertices[u].inQ` 標記來追蹤節點是否還在邏輯上的 $Q$ 中。

## 執行範例

程式碼中實作了教科書 Figure 23.4 的範例圖 (與 Kruskal 範例相同)。

### 預期輸出

演算法應該選擇以下邊（總權重應為 37）：

```text
Running Prim's Algorithm...
Minimum Spanning Tree Edges (Prim's Algorithm starting from node 0):
a -- b (Weight: 4)
b -- c (Weight: 8)
c -- i (Weight: 2)
c -- f (Weight: 4)
f -- g (Weight: 2)
g -- h (Weight: 1)
c -- d (Weight: 7)
d -- e (Weight: 9)
Total Weight of MST: 37
```
*(註：邊的列出順序取決於遍歷順序，但集合內容與總權重應與 Kruskal 相同)*

## 如何編譯與執行

```bash
# 編譯
g++ main.cpp -o Prims

# 執行
./Prims
```
