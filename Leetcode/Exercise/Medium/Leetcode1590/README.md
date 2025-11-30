#  LeetCode 1590. Make Sum Divisible by P 

## 1. 核心數學概念：同餘運算

我們的目標是找到一個最短的子陣列 $SubArray$，將其移除後，剩下的元素總和 $(TotalSum - SubSum)$ 可以被 $p$ 整除。

$$
(TotalSum - SubSum) \pmod p = 0
$$

根據同餘關係，這等價於：
$$
TotalSum \equiv SubSum \pmod p
$$

令 $target = TotalSum \pmod p$。

➡️ **關鍵目標：** 我們需要找到最短的子陣列，使得其總和 $SubSum$ 滿足：
$$
SubSum \pmod p = target
$$

> *如果 $target = 0$，表示原陣列總和已被 $p$ 整除，直接回傳 0。*

## 2. 解題策略：前綴和 + Hash Map

我們利用前綴和來快速計算子陣列的和，並使用 Hash Map 來記錄歷史的前綴和餘數，以達到 $O(N)$ 的時間複雜度。

### 數學推導

設 $PrefixSum[j]$ 為到索引 $j$ 的累積和。
子陣列的和 $SubSum$ 可以表示為：
$$
SubSum = PrefixSum[j] - PrefixSum[i-1]
$$

代入目標條件並考慮餘數：
$$
(PrefixSum[j] - PrefixSum[i-1]) \pmod p = target
$$

我們想知道 $PrefixSum[i-1]$ 的餘數是多少，才能滿足條件。
$$
PrefixSum[i-1] \pmod p = (PrefixSum[j] - target) \pmod p
$$

### Hash Map 記錄

我們使用 Hash Map 記錄 `{餘數 : 該餘數最近一次出現的索引}`。

## 3. 演算法步驟

1.  **計算 Target**：計算 $TotalSum \pmod p$ 作為 `target`。
2.  **初始化**：
    * `min_len` 設為陣列長度 $N$ (代表初始的無限大)。
    * `mod_map = {0: -1}`。索引 -1 代表在陣列開始前的虛擬位置，用於處理子陣列從索引 0 開始的情況。
3.  **遍歷**：從索引 $i=0$ 遍歷到 $N-1$，計算當前的累積餘數 `current_sum`。
4.  **計算 Needed**：計算我們需要的歷史餘數 `needed`：
    $$
    needed = (current\_sum - target + p) \pmod p
    $$
    *(加 $p$ 是為了確保在某些程式語言中，結果不會是負數。)*
5.  **查找**：若 `needed` 存在於 `mod_map` 中，表示我們找到了符合條件的子陣列。
    * 子陣列的長度 $L = i - mod\_map[needed]$。
    * 更新 `min_len = min(min_len, L)`。
6.  **更新 Map**：將當前的餘數 `current_sum` 和索引 $i$ 存入或更新到 `mod_map[current_sum] = i`。
7.  **回傳結果**：如果 `min_len` 等於 $N$ (表示找不到符合條件的子陣列，或找到的子陣列長度就是 $N$)，則回傳 -1，否則回傳 `min_len`。
