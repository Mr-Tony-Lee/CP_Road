# TSP Solver using Dynamic Programming (Held-Karp Algorithm)

這份程式碼實作了 **動態規劃 (Dynamic Programming)** 來解決 **旅行推銷員問題 (Traveling Salesman Problem, TSP)**。具體來說，它使用了 **Held-Karp 演算法**，這是一種能在 $O(n^2 2^n)$ 時間複雜度內找到 TSP **精確解 (Exact Solution)** 的演算法。

## 程式架構

程式主要由 `TSP` 類別組成，封裝了所有與 TSP 相關的資料與操作。

### 1. 資料結構 (`class TSP`)

*   **成員變數**:
    *   `filename`: 輸入檔案名稱。
    *   `arr`: 儲存所有城市的座標 `(x, y)`。
    *   `point_dis`: 城市間的距離矩陣 (Distance Matrix)。
    *   `N`: 城市總數。
    *   `final_distance`: 計算出的最短路徑長度。
    *   `ans_point`: 儲存最短路徑的城市順序。

### 2. 核心函式

#### `init()` / `file_in()` - 初始化與讀檔
*   讀取城市座標。
*   計算所有城市間的歐幾里得距離，建立 `point_dis` 矩陣。

#### `solve_tsp()` - 主流程 (Held-Karp 演算法)
這是程式的核心，利用動態規劃求解 TSP。

*   **DP 狀態定義**:
    *   `ans[i][mask]`: 從城市 `i` 出發，經過集合 `mask` 中的所有城市，最後回到起點 (城市 1) 的最短距離。
    *   `mask`: 一個整數，其二進位表示法代表一個城市集合。例如，若第 `j` 個 bit 為 1，表示城市 `j+1` 在集合中。
    *   `ans_map[i][mask]`: 記錄路徑來源，用於最後回溯重建路徑。

*   **演算法步驟**:
    1.  **初始化**: 設定從任意城市 `i` 直接回到起點 1 的距離 (`ans[i][0] = point_dis[i][1]`)。
    2.  **填表 (Bottom-Up)**:
        *   外層迴圈 `k`: 遍歷集合大小 (從 1 到 N-2)。
        *   中層迴圈 `i`: 遍歷起點城市 (不包含 1)。
        *   內層迴圈 `j`: 遍歷所有可能的集合 `mask`。
        *   **狀態轉移**: 對於集合 `mask` 中的每個城市 `m`，嘗試更新最小值：
            $$ans[i][mask] = \min_{m \in mask} \{ dist(i, m) + ans[m][mask \setminus \{m\}] \}$$
    3.  **最終計算**: 計算從起點 1 出發，經過所有其他城市，最後回到起點的最短距離。
        $$ans[1][all\_others] = \min_{j \in all\_others} \{ dist(1, j) + ans[j][all\_others \setminus \{j\}] \}$$

*   **路徑重建**:
    *   利用 `ans_map` 記錄的資訊，從起點開始，一步步回溯找出完整的路徑順序，存入 `ans_point`。

#### `plot()` - 繪圖
*   使用 `gnuplot` 將計算出的最佳路徑繪製成 PNG 圖片 (`fig_filename.png`)。

### 3. 複雜度分析

*   **時間複雜度**: $O(n^2 2^n)$。
    *   狀態總數為 $n \cdot 2^n$。
    *   每個狀態需要 $O(n)$ 的時間來轉移。
    *   這比暴力列舉的 $O(n!)$ 快得多，但對於 $N > 20$ 的情況仍然會非常慢。
*   **空間複雜度**: $O(n 2^n)$。
    *   需要儲存 DP 表 `ans` 和路徑記錄表 `ans_map`。

## 使用方式

```bash
g++ -o submit class_version.cpp
./submit point1.txt point2.txt ...
```

程式會輸出每個測試資料的最短路徑長度，並生成路徑圖。

## 注意事項

*   由於使用了位元遮罩 (Bitmask) `1 << N`，此程式限制 $N$ 不能太大 (通常 $N \le 20$ 左右)，否則記憶體會不足且執行時間過長。
*   輸入檔案格式需為：`編號 X座標 Y座標`。
