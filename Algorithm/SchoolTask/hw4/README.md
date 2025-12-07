# TSP Solver using Ant Colony Optimization (ACO)

這份程式碼實作了 **蟻群演算法 (Ant Colony Optimization, ACO)** 來解決 **旅行推銷員問題 (Traveling Salesman Problem, TSP)**。

## 程式架構

程式主要由 `TSP` 類別與 `Ant` 結構組成。

### 1. 資料結構

*   **`struct Ant`**: 代表一隻螞蟻。
    *   `path`: 儲存螞蟻走過的路徑（城市順序）。
    *   `tour_length`: 該路徑的總長度。

*   **`class TSP`**: 核心類別，負責演算法的執行。
    *   **成員變數**:
        *   `filename`: 輸入檔案名稱。
        *   `arr`: 儲存所有城市的座標 `(x, y)`。
        *   `point_dis`: 城市間的距離矩陣 (Distance Matrix)。
        *   `phermone`: 費洛蒙矩陣 (Pheromone Matrix)，記錄路徑上的費洛蒙濃度。
        *   `heuristic`: 啟發式矩陣 (Heuristic Matrix)，通常為距離的倒數 ($1/d_{ij}$)。
        *   `heuristic_pow`: 預先計算好的啟發式矩陣次方值 (優化用)。
        *   `ants`: 螞蟻群體。
        *   **參數**:
            *   `alpha`: 費洛蒙重要性因子。
            *   `beta`: 啟發式資訊重要性因子。
            *   `rho`: 費洛蒙揮發率。
            *   `Q`: 費洛蒙常數。

### 2. 核心函式

#### `init()` - 初始化
*   讀取城市座標後，計算所有城市間的距離 `point_dis`。
*   計算啟發式資訊 `heuristic` ($1/distance$)。
*   **優化**: 預先計算 `heuristic_pow` ($heuristic^\beta$) 以加速後續計算。
*   初始化費洛蒙矩陣 `phermone` 為一個小的常數。
*   配置螞蟻群體的記憶體空間。

#### `Roulette_Wheel_Selection()` - 輪盤賭選擇
*   螞蟻在選擇下一個城市時，依據機率進行選擇。
*   機率公式：$P_{ij} = \frac{(\tau_{ij}^\alpha) \times (\eta_{ij}^\beta)}{\sum (\tau_{ik}^\alpha) \times (\eta_{ik}^\beta)}$
    *   $\tau_{ij}$: 費洛蒙濃度。
    *   $\eta_{ij}$: 啟發式資訊 (距離越短越好)。
*   函式計算所有未訪問城市的機率，並使用隨機數進行輪盤賭選擇。

#### `ConstructAntSolution()` - 建構解
*   每隻螞蟻從隨機城市出發。
*   依序使用 `Roulette_Wheel_Selection` 選擇下一個城市，直到走完所有城市。
*   最後回到起點，形成一個迴路，並計算總路徑長度。

#### `Update_pheromones()` - 更新費洛蒙
1.  **揮發 (Evaporation)**: 所有路徑上的費洛蒙乘以 $(1 - \rho)$，模擬費洛蒙隨時間消散。
2.  **堆積 (Deposit)**: 根據每隻螞蟻走過的路徑長度，在路徑上增加費洛蒙。路徑越短，增加的費洛蒙越多 ($\Delta \tau = Q / L$)。

#### `ApplyLocalSearch()` - 2-OPT 區域搜尋
*   在 ACO 找到最佳解後，使用 **2-OPT** 演算法進一步優化路徑。
*   檢查路徑上的每一對邊，若交換這兩條邊能縮短總路徑長度，則進行交換（反轉中間的路徑段）。
*   重複此過程直到無法再改善為止。

#### `solve_tsp()` - 主流程
1.  讀取檔案。
2.  執行多次演算法 (`run_times`) 以取平均結果。
3.  在每次執行中，進行多次迭代 (`iteration`)：
    *   讓所有螞蟻建構解 (`ConstructAntSolution`)。
    *   更新費洛蒙 (`Update_pheromones`)。
    *   **Early Stopping (優化)**: 若連續 50 次迭代最佳解未更新，則提早結束該次執行，節省時間。
4.  記錄最佳解與平均解。
5.  **後處理**: 對全域最佳解執行 `ApplyLocalSearch` 進行微調。
6.  輸出結果並繪製路徑圖 (`plot`)。

### 3. 優化策略

為了加快執行速度與提高解的品質，程式碼包含了以下優化：
*   **2-OPT Local Search**: 結合全域搜尋 (ACO) 與區域搜尋 (2-OPT)，在 ACO 收斂後進一步優化解。
*   **預計算 (Precomputation)**: 預先計算 `heuristic` 的 `beta` 次方，避免在迴圈中重複呼叫耗時的 `pow` 函式。
*   **記憶體重用**: 重複使用 `ants` 向量，避免頻繁的記憶體配置與釋放。
*   **提早停止 (Early Stopping)**: 當演算法收斂（最佳解不再改善）時，自動停止迭代。
*   **編譯優化**: 建議使用 `-O3` 進行編譯。

## 使用方式

```bash
make all
# 或者手動編譯與執行
# g++ -O3 final.cpp -o final
# ./final <dataset> <output_name> <run_times> <evaluation_max> <population_size> <alpha> <beta> <rho> <Q> 
```

程式會輸出每個測試資料的最佳路徑長度、平均路徑長度，並生成 `fig_filename.png` 的路徑視覺化圖檔。
