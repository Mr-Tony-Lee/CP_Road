# Strongly Connected Components (SCC)

這份文件記錄了強連通分量 (Strongly Connected Components, SCC) 的實作細節，對應於 `main.cpp` 程式碼。

## 演算法簡介

在有向圖 $G=(V, E)$ 中，強連通分量是一個最大的頂點集合 $C \subseteq V$，使得對於 $C$ 中的任意一對頂點 $u$ 和 $v$，都存在從 $u$ 到 $v$ 的路徑以及從 $v$ 到 $u$ 的路徑。換句話說，SCC 內部的所有節點都是互相可達的。

本實作採用 **Kosaraju's Algorithm**，它利用兩次 DFS 來找出所有的 SCC。

## 偽代碼與 C++ 實作對照

下表展示了教科書偽代碼 (Pseudocode) 與本專案 C++ 實作的對應關係：

### STRONGLY-CONNECTED-COMPONENTS(G)

| 偽代碼 (Pseudocode) | C++ 實作 (`main.cpp`) | 說明 |
| :--- | :--- | :--- |
| `call DFS(G) to compute finishing times u.f` | `DFS_FirstPass(...)` | 第一次 DFS，計算完成時間 |
| `compute G^T` | `GetTranspose(G)` | 計算轉置圖 (反轉所有邊) |
| `call DFS(G^T), but in the main loop...` | `DFS_SecondPass(...)` | 第二次 DFS，在轉置圖上進行 |
| `consider vertices in order of decreasing u.f` | `while (!finishStack.empty())` | 利用 Stack 的 LIFO 特性，先取完成時間最晚的節點 |
| `output the vertices of each tree...` | `cout << "SCC #" << ...` | 輸出找到的每個 SCC |

## 演算法步驟詳解

1.  **第一次 DFS**:
    *   對原圖 $G$ 進行 DFS。
    *   當一個節點完成訪問 (變黑) 時，將其推入一個堆疊 (Stack)。
    *   堆疊頂部的節點就是完成時間 ($f$) 最晚的節點。

2.  **計算轉置圖 $G^T$**:
    *   將圖中所有邊的方向反轉。即若原圖有 $u \to v$，則 $G^T$ 有 $v \to u$。

3.  **第二次 DFS**:
    *   從堆疊中依序取出節點（即按照完成時間由大到小的順序）。
    *   若取出的節點在第二次 DFS 中尚未被訪問，則以該節點為起點，在 $G^T$ 上進行 DFS。
    *   這一次 DFS 遍歷到的所有節點，就構成了一個強連通分量 (SCC)。

## 執行範例

程式碼中實作了教科書 Figure 22.9 的範例圖。

### 圖結構
- 節點: a, b, c, d, e, f, g, h
- 邊:
  - (a, b)
  - (b, c), (b, e), (b, f)
  - (c, d), (c, g)
  - (d, c), (d, h)
  - (e, a), (e, f)
  - (f, g)
  - (g, f), (g, h)
  - (h, h)

### 預期輸出

演算法應該找出以下 SCC：
1.  **{a, b, e}**: 互相可達
2.  **{c, d}**: 互相可達
3.  **{f, g}**: 互相可達
4.  **{h}**: 自環

*(註：SCC 內部的節點順序可能不同，SCC 被發現的順序也可能不同，取決於第一次 DFS 的遍歷順序)*

```text
Strongly Connected Components:
SCC #1: { 0 4 1 }  (對應 a, e, b)
SCC #2: { 2 3 }    (對應 c, d)
SCC #3: { 5 6 }    (對應 f, g)
SCC #4: { 7 }      (對應 h)
```

## 如何編譯與執行

```bash
# 編譯
g++ main.cpp -o SCC

# 執行
./SCC
```
