# LeetCode 3577. Count the Number of Computer Unlocking Permutations

## 1. 核心概念：排列組合 (Combinatorics)

這道題目要求我們計算符合特定條件的排列數量。題目的核心限制在於 `complexity[0]` 必須是所有元素中的**嚴格最小值**。

如果 `complexity[0]` 是嚴格最小值，那麼我們固定第一個元素為 `complexity[0]`，剩下的 $n-1$ 個元素可以任意排列。
如果 `complexity[0]` 不是嚴格最小值（即存在某個 `complexity[i]`使得 `complexity[i] <= complexity[0]`），則無法滿足條件，答案為 0。

## 2. 解題策略

1. **檢查條件**：
   遍歷陣列中除了第一個元素以外的所有元素 `complexity[i]` (其中 $i > 0$)。
   檢查是否所有的 `complexity[i]` 都嚴格大於 `complexity[0]`。
   - 如果發現任何 `complexity[i] <= complexity[0]`，則直接回傳 `0`。

2. **計算排列數**：
   如果上述條件滿足，則剩下的 $n-1$ 個元素可以任意排列。
   排列數為 $(n-1)!$。
   我們需要計算 $(n-1)! \pmod{10^9 + 7}$。

## 3. 數學推導

設陣列長度為 $n$。
我們固定第一個位置為 `complexity[0]`。
剩下的位置有 $n-1$ 個。
剩下的元素有 $n-1$ 個。
在滿足 `complexity[0]` 為嚴格最小值的條件下，剩下的 $n-1$ 個元素可以填入剩下的 $n-1$ 個位置，共有 $(n-1)!$ 種方法。

$$
Ans = \begin{cases} 
0 & \text{if } \exists i > 0, complexity[i] \le complexity[0] \\
(n-1)! \pmod{10^9 + 7} & \text{otherwise}
\end{cases}
$$

## 4. 複雜度分析

- **時間複雜度**：$O(N)$。我們需要遍歷一次陣列來檢查條件並計算階乘。
- **空間複雜度**：$O(1)$。只需要常數空間來儲存變數。
