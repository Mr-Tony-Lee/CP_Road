# LeetCode 3606. Coupon Code Validator

## 1. 題目重述
給定三個等長陣列 `code`, `businessLine`, `isActive`，描述 n 張 coupon 的屬性：

- `code[i]`：字串，coupon 的識別碼。
- `businessLine[i]`：字串，coupon 所屬的商業類別。
- `isActive[i]`：布林，表示 coupon 是否為啟用狀態。

一張 coupon 若同時滿足下列條件即為合法：

1. `code[i]` 非空，且只包含英數字（a-z, A-Z, 0-9）與底線 `_`。
2. `businessLine[i]` 屬於下列四種之一：`"electronics"`, `"grocery"`, `"pharmacy"`, `"restaurant"`。
3. `isActive[i]` 為 `true`。

回傳所有合法 coupon 的 `code`，排序規則為先依 `businessLine` 的優先順序：
`"electronics"` -> `"grocery"` -> `"pharmacy"` -> `"restaurant"`，同一類別內再以 `code` 的字典序（lexicographical ascending）排序。

## 2. 核心概念
- 過濾 (Filtering)
- 字串驗證（使用正則或逐字元檢查是否為字母/數字/底線）
- 分類與排序（自定義類別優先順序 + 字典序）

## 3. 解題策略

步驟：

1. 定義合法的 business line 集合與優先順序對應表，例如：
	`{"electronics":0, "grocery":1, "pharmacy":2, "restaurant":3}`。
2. 走訪所有索引 i：
	- 若 `isActive[i]` 為 false，跳過。
	- 若 `code[i]` 長度為 0，跳過。
	- 驗證 `code[i]` 的每個字元是否為字母或數字或 `_`，若有其他字元則跳過。
	- 若 `businessLine[i]` 不在允許集合內，跳過。
	- 若通過上述檢查，將 `(businessLine[i], code[i])` 加入候選列表。
3. 對候選列表按照 `(priority[businessLine], code)` 排序。
4. 回傳排序後的 `code` 清單。

此題主要是資料過濾與排序，依題意直接實作即可。

### 範例（來自題目）

Example 1:

Input:

```
code = ["SAVE20","","PHARMA5","SAVE@20"]
businessLine = ["restaurant","grocery","pharmacy","restaurant"]
isActive = [true,true,true,true]
```

Output: `["PHARMA5","SAVE20"]`

說明：第二個 coupon code 為空（不合法），第四個包含特殊字元 `@`（不合法），因此只剩第一與第三，依 businessLine 與 code 排序後為 `PHARMA5`（pharmacy）再是 `SAVE20`（restaurant）。

Example 2:

Input:

```
code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"]
businessLine = ["grocery","electronics","invalid"]
isActive = [false,true,true]
```

Output: `["ELECTRONICS_50"]`

說明：第一個 coupon 為 inactive（不合法），第三個 businessLine 非法，僅中間一個合法。

## 4. 複雜度分析
- 時間複雜度：O(n log n)，其中 n 為輸入長度（最多 100）。過濾為 O(n)，排序為 O(m log m)（m 為候選數，m ≤ n）。
- 空間複雜度：O(n)，用於暫存候選 coupon。

## 5. 參考實作（C++）
- 程式檔：`Leetcode3606.cpp`（同資料夾）

## 6. 注意與邊界情況
- `code` 與 `businessLine` 可能為空字串。
- `code` 中僅允許英數字與 `_`，其他可列印字元皆視為不合法。
- `businessLine` 必須完全匹配允許集合（區分大小寫）。


