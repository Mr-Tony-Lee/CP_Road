# 01-Knapsack Solver using Dynamic Programming

這份程式碼實作了 **動態規劃 (Dynamic Programming, DP)** 來解決 **0/1 背包問題 (0/1 Knapsack Problem)**。

## 程式架構

程式主要由 `main.cpp` 組成，包含資料讀取與 DP 演算法實作。

### 1. 資料結構

*   **`vector<pair<int,int>> arr`**: 儲存物品的列表。
    *   每個元素為 `pair<int, int>`，分別代表物品的 **價值 (Value)** 與 **重量 (Weight)**。
    *   為了配合 DP 狀態轉移 (1-based indexing)，會在陣列開頭插入一個 `{0, 0}` 的虛擬物品。
*   **`vector<vector<int>> dp`**: 二維 DP 表格。
    *   `dp[i][j]` 代表在前 `i` 個物品中，背包容量限制為 `j` 時，所能獲得的最大價值。

### 2. 核心函式

#### `cmp()` - 排序比較函式
*   用來對物品進行排序。
*   排序規則：優先依據 **重量 (Weight)** 由小到大排序；若重量相同，則依據 **價值 (Value)** 由小到大排序。
*   *註：標準的 0/1 背包 DP 演算法其實不需要排序，但此程式碼中包含了排序步驟。*

#### `solve()` - DP 演算法主體
*   **排序**: 首先呼叫 `sort` 對物品進行排序。
*   **初始化**: 建立大小為 `(N+1) x (capacity+1)` 的 DP 表格，並初始化為 0。
*   **狀態轉移**:
    *   遍歷每個物品 `i` (從 1 到 N) 與每個容量 `j` (從 0 到 capacity)。
    *   若背包容量 `j` 足以裝下第 `i` 個物品 (`j >= weight[i]`)：
        *   `dp[i][j] = max(不選第 i 個物品, 選第 i 個物品)`
        *   `dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i])`
    *   若背包容量不足：
        *   `dp[i][j] = dp[i-1][j]` (只能選擇不裝)
*   **輸出**: 印出 `dp[N][capacity]` 即為最大價值。

#### `main()` - 主程式
1.  開啟 `input.txt` 讀取輸入資料。
2.  讀取背包總容量 `capacity`。
3.  讀取每個物品的價值 `v` 與重量 `w`，並存入 `arr`。
4.  呼叫 `solve()` 進行計算。

## 輸入格式 (input.txt)

```text
<Capacity>
<Value_1> <Weight_1>
<Value_2> <Weight_2>
...
```
*   第一行：背包總容量。
*   後續每一行：物品的價值與重量。

## 使用方式

本專案包含 `Makefile`，可直接使用 `make` 指令編譯並執行。

```bash
make all
# 或者手動編譯與執行
# g++ -O3 main.cpp -o main
# ./main
```

程式執行後會讀取 `input.txt` 並輸出計算出的最大價值。
