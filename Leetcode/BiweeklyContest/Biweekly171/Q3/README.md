# LeetCode 3767. Maximize Points After Choosing K Tasks
<!-- 註：由於無法確知題目名稱，這裡暫時以 LeetCode 3767 代表。根據程式碼邏輯推測題目為「在限制至少選 k 個 technique1 的情況下最大化總分」。 -->

## 1. 核心概念：貪婪演算法 (Greedy) + 排序 (Sorting)

題目要求我們在兩個陣列 `technique1` 和 `technique2` 中選擇元素，並且必須選擇至少 $k$ 個來自 `technique1` 的元素，目標是最大化總和。

為了滿足「至少選 $k$ 個 `technique1`」的限制，且讓總分最大，我們應該優先在那些「選 `technique1` 比選 `technique2` 更划算」的位置選擇 `technique1`。

定義「划算程度」為差值：
$$
diff = technique1[i] - technique2[i]
$$

- 如果 $diff$ 很大，表示選 `technique1` 比 `technique2` 多很多分（或少扣很多分）。
- 如果 $diff$ 很小（甚至是負的），表示選 `technique1` 相對不划算。

## 2. 解題策略

1.  **配對與排序**：
    將每一組數值 $(technique1[i], technique2[i])$ 綁定，並根據 $technique1[i] - technique2[i]$ 由大到小排序。
    這樣排序後，前段的元素是選 `technique1` 相對優勢最大的。

2.  **強制選擇前 $k$ 個**：
    為了滿足限制，我們直接選取排序後前 $k$ 個元素的 `technique1` 值。這是因為這些位置是「為了湊滿 $k$ 個名額，犧牲最小（或獲利最大）」的選擇。

3.  **剩餘元素自由選擇**：
    對於剩下的 $N - k$ 個元素，我們已經滿足了 $k$ 個 `technique1` 的限制。因此，對於這些位置，我們只需要貪婪地選擇較大的那個值即可，即 $\max(technique1[i], technique2[i])$。

## 3. 演算法流程

1.  建立一個包含 `(technique1[i], technique2[i])` 的陣列。
2.  自定義排序函式 `cmp`，依據 `a.first - a.second > b.first - b.second` 進行降冪排序。
3.  初始化 `ans = 0`。
4.  遍歷排序後的陣列：
    - 前 $k$ 個元素：`ans += arr[i].first`。
    - 之後的元素：`ans += max(arr[i].first, arr[i].second)`。
5.  回傳 `ans`。

## 4. 複雜度分析

- **時間複雜度**：$O(N \log N)$
  - 主要消耗在排序上。
  - 遍歷陣列計算總和為 $O(N)$。
- **空間複雜度**：$O(N)$
  - 需要額外的空間來儲存配對後的陣列 `arr`。
