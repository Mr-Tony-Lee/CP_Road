# Leetcode 3760: Maximum Substrings With Distinct Start

## 題目要求
計算字串 `s` 中有多少個字元開頭的子字串。

## 解法解釋
1.  **使用集合 (Set)**：利用 `std::set` 的特性來儲存不重複的元素。
2.  **遍歷字串**：遍歷字串 `s` 的每一個字元，將其插入 `set` 中。
3.  **回傳大小**：最後回傳 `set` 的大小，即為不同字元的數量。
