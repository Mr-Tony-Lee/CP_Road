# 3766. Minimum Operations to Make Binary Palindrome

## 1. 核心概念：二進位回文 (Binary Palindrome)

我們的目標是針對陣列中的每個數字 `num`，找到一個最小的非負整數 $k$，使得 `num + k` 或 `num - k` 的二進位表示法是回文。

## 2. 解題策略：暴力搜尋 (Brute Force)

由於二進位回文數的分佈足夠密集，我們可以直接從 $k=0$ 開始遞增，檢查 $num \pm k$ 是否符合條件。

### 演算法流程

1. **定義回文檢查函式 `isPalindrome(n)`**：
   - 將整數 $n$ 轉換為二進位字串。
   - 使用雙指針法（Two Pointers）檢查字串是否為回文。

2. **搜尋最小距離**：
   - 對於每個輸入數字 `num`，初始化 $k=0$。
   - 檢查 `isPalindrome(num + k)` 或 `isPalindrome(num - k)`。
   - 一旦找到符合條件的數，則當前的 $k$ 即為最小操作次數。
   - 將 $k$ 加入結果陣列。

### 複雜度分析

- **時間複雜度**：$O(N \times D \times \log M)$
  - $N$ 是陣列長度。
  - $D$ 是找到最近回文數所需的平均距離（通常很小）。
  - $\log M$ 是數字轉二進位並檢查回文的時間（$M$ 為數值大小）。
- **空間複雜度**：$O(\log M)$，用於儲存二進位字串。
