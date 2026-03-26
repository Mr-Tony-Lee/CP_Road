# Topological Sort (拓撲排序)

這份文件記錄了拓撲排序 (Topological Sort) 的實作細節，對應於 `main.cpp` 程式碼。

## 演算法簡介

拓撲排序是針對 **有向無環圖 (Directed Acyclic Graph, DAG)** 的一種排序方式。它會產生一個節點的線性序列，使得對於圖中的每一條有向邊 $(u, v)$，節點 $u$ 在序列中都出現在節點 $v$ 之前。

如果圖中包含環 (Cycle)，則無法進行拓撲排序。

在現實生活中，拓撲排序常用於排程問題，例如：
- 課程擋修機制（先修完 A 才能修 B）
- 程式編譯依賴（先編譯 library A 才能編譯 library B）
- 穿衣服順序（先穿襪子才能穿鞋子）

## 偽代碼與 C++ 實作對照

根據教科書 (CLRS) 的定義，拓撲排序可以簡單地通過 DFS 來實現。

### TOPOLOGICAL-SORT(G)

| 偽代碼 (Pseudocode) | C++ 實作 (`main.cpp`) | 說明 |
| :--- | :--- | :--- |
| `call DFS(G) to compute finishing times v.f` | `DFS_VISIT(...)` | 呼叫 DFS 遍歷圖 |
| `as each vertex is finished, insert it onto the front of a linked list` | `topo_list.push_front(u);` | 當節點變黑 (Finished) 時，插入鏈結串列前端 |
| `return the linked list of vertices` | `return topo_list;` | 返回排序後的列表 |

### 核心概念

為什麼按「完成時間 (Finish Time)」的**反向**順序就是拓撲排序？

- 當 DFS 完成一個節點 $u$ 時 (即 $u$ 變為黑色)，代表 $u$ 的所有鄰居（以及鄰居的鄰居...）都已經被訪問並完成了。
- 換句話說，所有從 $u$ 出發能到達的節點，都已經被放入了鏈結串列中。
- 因此，將 $u$ 放在這些節點的**前面** (`push_front`)，就能保證 $u$ 排在它所有後繼節點的前面，符合拓撲排序的定義。

## 執行範例：Bumstead 教授的穿衣順序

程式碼中實作了教科書 Figure 22.7 的範例。

### 圖結構 (DAG)

- **undershorts** -> pants, shoes
- **pants** -> belt, shoes
- **belt** -> jacket
- **shirt** -> belt, tie
- **tie** -> jacket
- **socks** -> shoes
- **watch** (無依賴)

### 預期輸出 (其中一種可能的合法順序)

由於 DFS 的訪問順序可能不同（取決於遍歷鄰居的順序或選擇起始點的順序），拓撲排序的結果可能不唯一，但都必須滿足依賴關係。

程式碼執行結果範例：
```text
Topological Sort Result (Order of dressing):
1. socks
2. shirt
3. tie
4. watch
5. undershorts
6. pants
7. shoes
8. belt
9. jacket
```
*(註：這只是其中一種合法的拓撲排序，例如 `watch` 可以在任何位置，只要不違反其他依賴)*

## 如何編譯與執行

```bash
# 編譯
g++ main.cpp -o TopologicalSort

# 執行
./TopologicalSort
```
