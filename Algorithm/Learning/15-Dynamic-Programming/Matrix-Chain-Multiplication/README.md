# Matrix Chain Multiplication Solver using Dynamic Programming

這份程式碼實作了 **動態規劃 (Dynamic Programming, DP)** 來解決 **矩陣鏈乘積 (Matrix Chain Multiplication)** 問題。

## 程式架構

程式主要由 `main.cpp` 組成，包含矩陣鏈乘積的最佳化演算法實作。

### 1. 演算法概念

矩陣鏈乘積問題的目標是找到一組矩陣相乘的順序（加上括號），使得計算所需的純量乘法次數最少。
給定一個陣列 `p`，其中第 `i` 個矩陣 $A_i$ 的維度為 $p[i-1] \times p[i]$。

### 2. 資料結構

*   **`vector<int> p`**: 儲存矩陣維度的陣列。若有 `n` 個矩陣，陣列長度為 `n+1`。
*   **`vector<vector<int>> m`**: DP 表格，`m[i][j]` 儲存計算矩陣鏈 $A_i \dots A_j$ 所需的最少乘法次數。
*   **`vector<vector<int>> s`**: 分割點表格，`s[i][j]` 記錄了 $A_i \dots A_j$ 的最佳分割點 $k$，即 $(A_i \dots A_k)(A_{k+1} \dots A_j)$。

### 3. 核心函式

#### `matrix_chain_order(const vector<int>& p)`
*   **初始化**:
    *   `n` 為矩陣數量 (`p.size() - 1`)。
    *   初始化 `m` 和 `s` 表格。
    *   `m[i][i] = 0`，單一矩陣不需要乘法。
*   **狀態轉移**:
    *   `l` 代表鏈的長度，從 2 開始遞增到 `n`。
    *   `i` 為鏈的起始點，`j` 為鏈的終點 (`j = i + l - 1`)。
    *   遍歷所有可能的分割點 `k` (從 `i` 到 `j-1`)：
        *   計算成本 $q = m[i][k] + m[k+1][j] + p[i-1] \times p[k] \times p[j]$。
        *   若 $q$ 小於目前的 `m[i][j]`，則更新 `m[i][j]` 並記錄分割點 `s[i][j] = k`。
*   **輸出**: 印出最少乘法次數 `m[1][n]`。

#### `print_optimal_parens(int i, int j)`
*   利用 `s` 表格遞迴地印出最佳的括號方式。
*   若 `i == j`，印出矩陣名稱 `Ai`。
*   否則，印出 `(`，遞迴呼叫左半部 `(i, s[i][j])`，遞迴呼叫右半部 `(s[i][j]+1, j)`，最後印出 `)`。

#### `main()`
*   定義範例維度陣列 `p = {30, 35, 15, 5, 10, 20, 25}`。
    *   $A_1: 30 \times 35$
    *   $A_2: 35 \times 15$
    *   ...
*   呼叫 `matrix_chain_order` 計算並輸出結果。
*   呼叫 `print_optimal_parens` 輸出最佳括號組合。

## 使用方式

本專案包含 `Makefile`，可直接使用 `make` 指令編譯並執行。

```bash
make all
# 或者手動編譯與執行
# g++ -O3 main.cpp -o main
# ./main
```

程式執行後會輸出最少乘法次數以及最佳的括號順序。
