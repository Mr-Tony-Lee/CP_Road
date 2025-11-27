# Edit Distance Solver using Dynamic Programming

這份程式碼實作了 **動態規劃 (Dynamic Programming, DP)** 來解決 **編輯距離 (Edit Distance / Levenshtein Distance)** 問題。

## 程式架構

程式主要由 `main.cpp` 組成，包含編輯距離演算法的實作。

### 1. 演算法概念

編輯距離是指將一個字串轉換成另一個字串所需的最少操作次數。允許的操作包括：
1.  **插入 (Insertion)**
2.  **刪除 (Deletion)**
3.  **替換 (Substitution)**

### 2. 核心函式

#### `EditDistance(const string& str1, const string& str2)`
*   **初始化**: 建立一個 `(n+1) x (m+1)` 的二維 DP 表格 `dp`。
    *   `dp[i][0] = i`: 將長度為 `i` 的字串轉換為空字串，需要 `i` 次刪除操作。
    *   `dp[0][j] = j`: 將空字串轉換為長度為 `j` 的字串，需要 `j` 次插入操作。
*   **狀態轉移**:
    *   遍歷兩個字串的每個字元。
    *   若 `str1[i-1] == str2[j-1]` (字元相同)：
        *   不需要操作，`dp[i][j] = dp[i-1][j-1]`。
    *   若字元不同，取以下三種操作的最小值加 1：
        *   **刪除**: `dp[i-1][j] + 1`
        *   **插入**: `dp[i][j-1] + 1`
        *   **替換**: `dp[i-1][j-1] + 1`
*   **輸出**: 印出 `dp[n][m]`，即為兩個字串間的最短編輯距離。

#### `main()`
*   定義兩個範例字串 `str1 = "intention"` 與 `str2 = "execution"`。
*   呼叫 `EditDistance` 計算並輸出結果。

## 使用方式

本專案包含 `Makefile`，可直接使用 `make` 指令編譯並執行。

```bash
make all
# 或者手動編譯與執行
# g++ -O3 main.cpp -o main
# ./main
```

程式執行後會輸出 "intention" 與 "execution" 之間的編輯距離。
