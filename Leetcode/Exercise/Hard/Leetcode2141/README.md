# Leetcode 2141 - Maximum Running Time of N Computers

## 題目描述
給定 `n` 台電腦和一個電池陣列 `batteries`，其中 `batteries[i]` 代表第 `i` 個電池的電量（運行時間）。
你需要找出這 `n` 台電腦可以同時運行的最大時間。
你可以隨意切換電池給不同的電腦使用，但同一時間一台電腦只能使用一個電池。

## 解題思路 (Binary Search)

這道題目要求我們找出一個「最大」的運行時間，這類求最大值或最小值的問題，通常可以考慮使用 **二分搜尋法 (Binary Search)** 對答案進行搜尋。

### 核心觀念
假設我們想要檢查是否能讓 `n` 台電腦同時運行 `T` 分鐘：
1.  **總需求電量**：`n` 台電腦運行 `T` 分鐘，總共需要的電量為 `n * T`。
2.  **電池貢獻限制**：對於每一顆電池 `batteries[i]`：
    *   如果 `batteries[i] <= T`，這顆電池的所有電量都可以被完全使用。
    *   如果 `batteries[i] > T`，這顆電池最多只能貢獻 `T` 分鐘的電量。
    *   **為什麼？** 因為一台電腦在 `T` 分鐘內最多只能消耗 `T` 的電量。即使電池還有剩餘電量，也無法在 `T` 時間內被「同時」使用（因為每台電腦都已經配有電源在跑了，且一顆電池同一時間只能供一台電腦使用）。
3.  **判斷條件**：因此，對於目標時間 `T`，所有電池能提供的最大有效總電量為 $\sum \min(\text{batteries}[i], T)$。
    *   如果 $\sum \min(\text{batteries}[i], T) \ge n \times T$，則表示可以運行 `T` 分鐘。

### 演算法步驟
1.  **定義搜尋範圍**：
    *   下界 (`left`)：`1`。
    *   上界 (`right`)：所有電池總電量除以 `n` (`sum(batteries) / n`)。這是理論上平均分配的最大值。
2.  **二分搜尋**：
    *   使用 `while(left < right)` 進行迴圈。
    *   計算中間值 `target = right - (right - left) / 2`。
        > **注意**：這裡使用 `right - ...` 的方式是為了取**右中位數**（向上取整），配合後面的 `left = target` 寫法，避免在 `left` 和 `right` 相鄰時陷入無窮迴圈。
    *   檢查 `target` 是否可行。
    *   如果可行 (`(charge / n) >= target`)，表示 `target` 可能是答案，且我們想嘗試更大的值，但 `target` 本身也是候選，所以更新 `left = target`。
    *   如果不可行，表示 `target` 太大了，縮小範圍 `right = target - 1`。
3.  **Check 邏輯**：
    *   計算所有電池針對 `target` 的有效總和：`charge = 0`。
    *   遍歷 `batteries`，`charge += min((long long)batteries[i], target)`。
    *   判斷條件：檢查 `charge / n >= target`。

### 複雜度分析
*   **時間複雜度**: $O(M \log K)$，其中 $M$ 是電池數量，$K$ 是搜尋範圍的大小（總電量）。每次 check 需要遍歷所有電池。
*   **空間複雜度**: $O(1)$，只需要常數空間。

---
參考來源: [LeetCode Solutions](https://leetcode.com/problems/maximum-running-time-of-n-computers/solutions/3421584/maximum-running-time-of-n-computers-by-l-zptc)