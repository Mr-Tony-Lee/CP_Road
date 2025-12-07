# TSP Solver using Elastic Net Algorithm

這份程式碼實作了 **彈性網路演算法 (Elastic Net Algorithm)** 來解決 **旅行推銷員問題 (Traveling Salesman Problem, TSP)**。此方法由 Durbin 和 Willshaw 於 1987 年提出。

## 程式架構

程式主要由 `TSP` 類別與 `Node` 結構組成。

### 1. 資料結構

*   **`struct Node`**: 代表彈性網路中的一個節點（神經元）。
    *   `x`, `y`: 節點的座標。

*   **`class TSP`**: 核心類別，負責演算法的執行。
    *   **成員變數**:
        *   `filename`: 輸入檔案名稱。
        *   `arr`: 儲存所有城市（資料點）的座標 `(x, y)`。
        *   `N`: 城市的總數量。
        *   `best_distance`: 所有執行中找到的最佳路徑長度。
        *   `average_distance`: 30 次獨立執行的平均最佳路徑長度。
        *   `ans_point`: 儲存最佳路徑的城市順序。
        *   **參數**:
            *   `M`: 網路上節點的數量（通常設為城市數量的 2.5 倍）。
            *   `K`: 溫度參數，控制城市對節點的影響範圍。
            *   `alpha`: 吸引力參數 (Attraction parameter)。
            *   `beta`: 彈性力參數 (Elasticity parameter)。

### 2. 核心函式

#### `solve_tsp()` - 主流程
1.  **初始化**:
    *   計算所有城市的中心點。
    *   在中心點周圍建立一個圓形的彈性網路，包含 `M` 個節點。
    *   為了滿足「獨立執行」的要求，每次初始化時會加入微小的隨機擾動。
2.  **迭代更新 (Iterative Update)**:
    *   執行 `max_iter` 次迭代（例如 1000 次）。
    *   **計算權重 (Weights)**: 計算每個城市對每個節點的影響力 $w_{ij}$。這是一個基於距離的高斯函數 $\phi(d, K) = \exp(-d^2 / 2K^2)$。
    *   **移動節點**: 根據兩個主要力量更新節點位置：
        *   **吸引力 (Attraction Force)**: 城市將節點拉向自己 ($\alpha \sum w_{ij} (X_{city} - Y_{node})$)。
        *   **彈性力 (Elastic Force)**: 相鄰節點彼此拉近，試圖縮短路徑長度 ($\beta K (Y_{next} - 2Y_{curr} + Y_{prev})$)。
    *   **退火 (Annealing)**: 每次迭代後降低溫度 `K`，使網路從全域搜尋逐漸轉向局部精細化。
3.  **提取路徑 (Get Tour)**:
    *   迭代結束後，將每個城市指派給網路上距離最近的節點。
    *   根據節點在環上的順序，決定城市的拜訪順序。
4.  **統計與輸出**:
    *   執行 30 次獨立運算，記錄最佳解與平均解。
    *   輸出結果至檔案，並繪製路徑圖與 GIF 動畫。

#### `dist_sq()` - 距離計算
*   計算節點與城市之間的歐幾里得距離平方，用於權重計算。

#### `create_gif()` - 動畫製作
*   記錄最佳執行過程中的網路狀態（每 100 次迭代一次）。
*   使用 `gnuplot` 將這些狀態繪製成 GIF 動畫，顯示彈性網路如何逐漸變形並擬合城市分佈。

### 3. 演算法特性

*   **類比方法 (Analogue Approach)**: 不同於離散的組合優化，Elastic Net 是一種連續空間的幾何方法。
*   **競爭與合作**: 節點之間競爭對城市的代表權，同時通過彈性力合作保持路徑的連貫性。
*   **漸進收斂**: 透過 `K` 值的逐漸降低，演算法能有效避免陷入早期的局部最佳解。

## 使用方式

### 編譯
```bash
g++ -O3 -o submit submit.cpp
```

### 執行
執行程式並提供一個或多個座標檔案：
```bash
./submit <dataset> <output_name> <run_times> <max_iteration> <M> <K> <alpha> <beta>
```

### 輸出
程式會產生以下檔案：
*   `output_filename.txt`: 包含最佳距離、平均距離與路徑順序。
*   `fig_filename.png`: 最佳路徑的靜態圖。
*   `evolution_filename.gif`: 演算法收斂過程的動畫。

## 相依性
*   **Gnuplot**: 系統需安裝 Gnuplot 以產生 PNG 和 GIF 圖像。
