# LeetCode 3432. Count Partitions with Even Sum Difference

## 1. 核心數學概念：奇偶性 (Parity)

我們的目標是計算有多少種分割方式，使得左側元素和 ($LeftSum$) 與右側元素和 ($RightSum$) 的差值為偶數。

$$
| LeftSum - RightSum | \pmod 2 = 0
$$

我們可以利用總和 ($TotalSum$) 來推導：
$$
RightSum = TotalSum - LeftSum
$$

代入差值公式：
$$
\begin{aligned}
Diff &= | LeftSum - (TotalSum - LeftSum) | \\
     &= | 2 \times LeftSum - TotalSum |
\end{aligned}
$$

由於 $2 \times LeftSum$ 必定是偶數，因此差值的奇偶性完全取決於 $TotalSum$：
$$
Diff \equiv TotalSum \pmod 2
$$

這意味著：
- 若 $TotalSum$ 為偶數，則任意分割的差值均為偶數。
- 若 $TotalSum$ 為奇數，則任意分割的差值均為奇數。

## 2. 解題策略：前綴和 (Prefix Sum)

雖然數學上可以直接判斷，但為了實作通用的檢查邏輯，我們可以使用前綴和來模擬分割過程。

### 演算法步驟

1. **計算總和**：先遍歷一次陣列計算 $TotalSum$。
2. **遍歷分割點**：
   - 陣列長度為 $n$，有 $n-1$ 個分割點（從索引 $0$ 到 $n-2$）。
   - 維護當前的 $LeftSum$（即前綴和）。
   - 計算 $RightSum = TotalSum - LeftSum$。
   - 檢查 $| LeftSum - RightSum |$ 是否為偶數。
3. **計數**：若符合條件，計數器加一。

### 複雜度分析
- **時間複雜度**：$O(N)$，需要遍歷陣列兩次（一次求和，一次檢查分割）。
- **空間複雜度**：$O(N)$ 或 $O(1)$，取決於是否儲存前綴和陣列（本題可優化為 $O(1)$）。
