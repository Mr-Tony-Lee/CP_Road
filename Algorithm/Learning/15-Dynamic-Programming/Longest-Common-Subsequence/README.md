# Longest Common Subsequence Solver using Dynamic Programming

這份程式碼實作了 **動態規劃 (Dynamic Programming, DP)** 來解決 **最長共同子序列 (Longest Common Subsequence, LCS)** 問題。

## 程式架構

程式主要由 `main.cpp` 組成，包含 LCS 演算法的實作。

### 1. 演算法概念

最長共同子序列 (LCS) 是指在兩個序列中，以相同順序出現（但不一定連續）的最長子序列。
例如：`"intention"` 與 `"execution"` 的 LCS 為 `"etion"` 或 `"ntion"` 等，長度為 5。

### 2. 核心函式

#### `LCS(const string & str1, const string & str2)`
*   **初始化**: 建立一個 `(n+1) x (m+1)` 的二維 DP 表格 `dp`，並初始化為 0。
    *   `dp[i][j]` 代表 `str1` 前 `i` 個字元與 `str2` 前 `j` 個字元的 LCS 長度。
*   **狀態轉移**:
    *   遍歷兩個字串的每個字元。
    *   若 `str1[i-1] == str2[j-1]` (字元相同)：
        *   該字元可以成為 LCS 的一部分，長度加 1。
        *   `dp[i][j] = dp[i-1][j-1] + 1`
    *   若 `str1[i-1] != str2[j-1]` (字元不同)：
        *   LCS 長度取決於「捨棄 str1 當前字元」或「捨棄 str2 當前字元」兩者中的最大值。
        *   `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
*   **輸出**: 印出 `dp[n][m]`，即為兩個字串的最長共同子序列長度。

#### `main()`
*   定義兩個範例字串 `str1` 與 `str2`。
*   *(註：目前的 main 函式尚未呼叫 LCS 函式，需自行加入 `LCS(str1, str2);` 以執行計算)*

## 使用方式

本專案包含 `Makefile`，可直接使用 `make` 指令編譯並執行。

```bash
make all
# 或者手動編譯與執行
# g++ -O3 main.cpp -o main
# ./main
```
