# Leetcode 3771. Total Score of Dungeon Runs

## 1. 核心概念：前綴和 (Prefix Sum) + 二分搜尋 (Binary Search)

這題的目標是計算一個總分，對於每一個物品（或位置）$i$，我們需要找出有多少個合法的連續區間以 $i$ 結尾，且該區間內的傷害總和不超過剩餘的血量上限。

具體來說，對於每一個 $i$，我們要找出有多少個起始位置 $j$ ($0 \le j < i$)，使得：
$$ \sum_{k=j}^{i-1} \text{damage}[k] \le \text{hp} - \text{requirement}[i-1] $$

## 2. 解題策略

我們可以利用 **前綴和 (Prefix Sum)** 來快速計算區間和。令 `pref[x]` 為 `damage` 陣列前 $x$ 個元素的和。
則區間和可以表示為：
$$ \text{pref}[i] - \text{pref}[j] \le \text{hp} - \text{requirement}[i-1] $$

將不等式移項，我們想要找到滿足以下條件的 $j$：
$$ \text{pref}[j] \ge \text{pref}[i] - (\text{hp} - \text{requirement}[i-1]) $$

令目標值 $T = \text{pref}[i] - \text{hp} + \text{requirement}[i-1]$。
問題轉化為：在 $0$ 到 $i-1$ 的範圍內，有多少個 $j$ 滿足 $\text{pref}[j] \ge T$。

由於 `damage` 元素皆為非負數（假設），`pref` 陣列是單調遞增的。因此，我們可以使用 **二分搜尋 (Binary Search)** 來找到第一個滿足 $\text{pref}[mid] \ge T$ 的位置 $l$。

- 如果找到這樣的 $l$，且 $l \le i-1$，那麼從 $l$ 到 $i-1$ 的所有索引都符合條件（因為 `pref` 是遞增的，若 `pref[l] >= T`，則對於所有 $k > l$，`pref[k] >= T` 也成立）。
- 符合條件的 $j$ 的數量即為 $(i-1) - l + 1 = i - l$。

### 演算法步驟：
1.  計算 `damage` 的前綴和陣列 `pref`。
2.  初始化 `ans = 0`。
3.  遍歷每一個位置 $i$ (從 1 到 $N$)：
    - 計算閾值 $T = \text{requirement}[i-1] - \text{hp} + \text{pref}[i]$。
    - 使用二分搜尋在範圍 $[0, N]$ 中找到第一個滿足 $\text{pref}[mid] \ge T$ 的索引 $l$。
    - 如果 $l \le i-1$，則將 $i - l$ 加到 `ans`。
4.  回傳 `ans`。

## 3. 複雜度分析
- **時間複雜度**：$O(N \log N)$
    - 計算前綴和需要 $O(N)$。
    - 對於每個位置 $i$，我們執行一次二分搜尋，花費 $O(\log N)$。總共有 $N$ 個位置，故為 $O(N \log N)$。
- **空間複雜度**：$O(N)$
    - 需要一個大小為 $N+1$ 的陣列來儲存前綴和。
