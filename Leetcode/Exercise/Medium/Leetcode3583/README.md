# LeetCode 3583. Special Triplets

## 1. 題目理解

給定一個整數陣列 `nums`，我們需要找出滿足以下條件的三元組 $(i, j, k)$ 的數量：
1. $i < j < k$
2. $nums[i] == 2 \times nums[j]$
3. $nums[k] == 2 \times nums[j]$

簡單來說，對於每一個元素 `nums[j]` (作為中間元素)，我們需要計算它左邊有多少個數值是它的兩倍，以及右邊有多少個數值是它的兩倍，然後將這兩個數量相乘。

## 2. 解題策略：Hash Map + 枚舉中間元素

這是一個經典的「枚舉中間，計算兩邊」的計數問題。

### 核心思路

我們遍歷陣列中的每一個元素，將其視為三元組的中間項 `nums[j]`。對於每一個 `nums[j]`，我們需要知道：
1. **Lcnt**: 在索引 $j$ 左邊，數值為 $2 \times nums[j]$ 的元素個數。
2. **Rcnt**: 在索引 $j$ 右邊，數值為 $2 \times nums[j]$ 的元素個數。

根據乘法原理，以 `nums[j]` 為中間項的合法三元組數量為 $Lcnt \times Rcnt$。

### 實作細節 (Method 1)

為了在 $O(N)$ 時間內完成，我們可以使用兩個 Hash Map：
1. `totalCnt`: 記錄整個陣列中每個數字出現的總次數。
2. `leftCnt`: 在遍歷過程中，動態記錄當前位置左邊每個數字出現的次數。

**演算法步驟：**

1. **預處理**：遍歷一次 `nums`，填滿 `totalCnt`。
2. **計算答案**：再次遍歷 `nums`，對於每個元素 `num` (即 `nums[j]`)：
   - 計算目標值 `target = num * 2`。
   - 從 `leftCnt` 取得左邊的目標數量：`Lcnt = leftCnt[target]`。
   - 更新 `leftCnt`：`leftCnt[num]++` (將當前數字加入左邊計數，供後續使用)。
   - 計算右邊的目標數量：`Rcnt = totalCnt[target] - leftCnt[target]`。
     - 注意：這裡的 `leftCnt[target]` 已經包含了當前位置左邊的數量。如果 `target == num` (即 `num == 0`)，因為我們剛執行了 `leftCnt[num]++`，所以 `totalCnt - leftCnt` 正確地排除了當前位置及左邊的所有 `target`，只剩下右邊的。
   - 累加答案：`ans = (ans + Lcnt * Rcnt) % mod`。

### 複雜度分析

- **時間複雜度**：$O(N)$。我們遍歷陣列兩次，Hash Map 的操作平均為 $O(1)$。
- **空間複雜度**：$O(N)$。用於儲存 `totalCnt` 和 `leftCnt`。

## 3. 其他解法 (Method 2)

另一種思路是記錄每個數值出現的所有索引位置 (例如 `unordered_map<int, vector<int>>`)。
遍歷每個數作為中間項時，利用 Binary Search (`upper_bound`) 在其目標值 (`target`) 的索引列表中查找，快速算出小於當前索引 (左邊) 和大於當前索引 (右邊) 的個數。
雖然這也是可行的方法，但時間複雜度會帶有 $O(\log N)$ 因子 (取決於實作細節和數據分佈)，且空間開銷較大。
