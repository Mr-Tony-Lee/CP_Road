# Leetcode 3759: Count Elements With at Least K Greater Values

## 題目要求
給定一個整數陣列 `nums` 和一個整數 `k`，計算有多少個元素 `nums[i]` 滿足：陣列中至少有 `k` 個元素嚴格大於 `nums[i]`。

## 解法解釋
1.  **排序**：首先將陣列 `nums` 進行排序。
2.  **遍歷與檢查**：
    - 遍歷排序後的陣列。
    - 對於每個元素 `nums[i]`，使用 `upper_bound` 找到第一個嚴格大於 `nums[i]` 的元素位置。
    - 計算大於 `nums[i]` 的元素個數。
    - 如果個數大於等於 `k`，則計數器 `ans` 加一。
3.  **回傳結果**：回傳最終的計數 `ans`。
