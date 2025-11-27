# Longest Palindromic Subsequence Solver using Dynamic Programming

這份程式碼實作了 **動態規劃 (Dynamic Programming, DP)** 來解決 **最長回文子序列 (Longest Palindromic Subsequence, LPS)** 問題。

## 程式架構

程式主要由 `main.cpp` 組成，包含 LPS 演算法的實作。

### 1. 演算法概念

最長回文子序列是指在一個序列中，找出一個最長的子序列，使得該子序列從前往後讀和從後往前讀是一樣的。
例如：字串 `"intention"` 的最長回文子序列可能是 `"ntn"` 或 `"ini"` 等，長度為 3。
*(註：範例程式碼中的 "intention" 輸出的結果會是 3)*

### 2. 核心函式

#### `solve(string str1)`
*   **初始化**: 建立一個 `n x n` 的二維 DP 表格 `dp`，並初始化為 0。
    *   `dp[i][j]` 代表字串 `str1` 從索引 `i` 到索引 `j` 的子字串 (`str1[i...j]`) 中的最長回文子序列長度。
*   **狀態轉移**:
    *   外層迴圈 `i` 從 `n-1` 遞減到 `0` (左邊界)。
    *   內層迴圈 `j` 從 `i+1` 遞增到 `n-1` (右邊界)。
    *   **Base Case**: `dp[i][i] = 1`，單個字元本身就是長度為 1 的回文。
    *   若 `str1[i] == str1[j]` (頭尾字元相同)：
        *   這兩個字元可以作為回文的頭尾，長度加 2。
        *   `dp[i][j] = dp[i+1][j-1] + 2`
    *   若 `str1[i] != str1[j]` (頭尾字元不同)：
        *   LCS 長度取決於「捨棄左邊界字元」或「捨棄右邊界字元」兩者中的最大值。
        *   `dp[i][j] = max(dp[i+1][j], dp[i][j-1])`
*   **輸出**: 印出 `dp[0][n-1]`，即為整個字串的最長回文子序列長度。

#### `main()`
*   定義範例字串 `str1 = "intention"`。
*   呼叫 `solve(str1)` 進行計算並輸出結果。

## 使用方式

本專案包含 `Makefile`，可直接使用 `make` 指令編譯並執行。

```bash
make all
# 或者手動編譯與執行
# g++ -O3 main.cpp -o main
# ./main
```

程式執行後會輸出 "intention" 的最長回文子序列長度。
