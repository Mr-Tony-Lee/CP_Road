# Knuth-Morris-Pratt (KMP) Algorithm

這份文件記錄了 KMP 字串匹配演算法的實作細節，對應於 `main.cpp` 程式碼。

## 演算法簡介

KMP 演算法是一種高效的字串匹配演算法，用於在文本串 $T$ 中尋找模式串 $P$ 的所有出現位置。

它的核心思想是利用已經匹配過的信息，當發生不匹配時，不需要回溯文本串的指針，而是將模式串向右移動到適當的位置繼續比較。這通過一個預先計算的 **前綴函數 (Prefix Function)** 或稱為 **$\pi$ 數組 (Pi Array)** 來實現。

時間複雜度：$O(n + m)$，其中 $n$ 是文本長度，$m$ 是模式長度。

## 偽代碼與 C++ 實作對照

由於教科書 (CLRS) 使用 1-based indexing (陣列從 1 開始)，而 C++ 使用 0-based indexing (陣列從 0 開始)，實作時需要進行相應的調整。

### COMPUTE-PREFIX-FUNCTION(P)

| 偽代碼 (1-based) | C++ 實作 (0-based) | 說明 |
| :--- | :--- | :--- |
| `m = P.length` | `int m = P.length();` | |
| `pi[1] = 0` | `pi[0] = 0;` | 第一個元素的前綴長度為 0 |
| `k = 0` | `int k = 0;` | $k$ 代表當前匹配的前綴長度 |
| `for q = 2 to m` | `for (int q = 1; q < m; ++q)` | 從第二個字符開始遍歷 |
| `while k > 0 and P[k+1] != P[q]` | `while (k > 0 && P[k] != P[q])` | **關鍵差異**: $P[k+1]$ 對應 `P[k]` |
| `k = pi[k]` | `k = pi[k - 1];` | **關鍵差異**: $\pi[k]$ 對應 `pi[k-1]` |
| `if P[k+1] == P[q]` | `if (P[k] == P[q])` | 檢查字符是否匹配 |
| `k = k + 1` | `k = k + 1;` | 增加匹配長度 |
| `pi[q] = k` | `pi[q] = k;` | 記錄當前位置的最長前綴長度 |

### KMP-MATCHER(T, P)

| 偽代碼 (1-based) | C++ 實作 (0-based) | 說明 |
| :--- | :--- | :--- |
| `n = T.length`, `m = P.length` | `int n = T.length(); int m = P.length();` | |
| `pi = COMPUTE-PREFIX-FUNCTION(P)` | `vector<int> pi = ComputePrefixFunction(P);` | |
| `q = 0` | `int q = 0;` | $q$ 代表當前已匹配的字符數 |
| `for i = 1 to n` | `for (int i = 0; i < n; ++i)` | 遍歷文本串 |
| `while q > 0 and P[q+1] != T[i]` | `while (q > 0 && P[q] != T[i])` | 若下一個字符不匹配，回退 $q$ |
| `q = pi[q]` | `q = pi[q - 1];` | 根據 $\pi$ 數組回退 |
| `if P[q+1] == T[i]` | `if (P[q] == T[i])` | 若字符匹配 |
| `q = q + 1` | `q = q + 1;` | 增加匹配長度 |
| `if q == m` | `if (q == m)` | 完全匹配 |
| `print "Pattern occurs with shift" i - m` | `cout << ... (i - m + 1)` | 輸出匹配位置 (0-based index) |
| `q = pi[q]` | `q = pi[q - 1];` | 尋找下一個可能的匹配 |

## 執行範例

### Test Case 1
- Text: `bacbababaabcbab`
- Pattern: `ababaca`
- Pi Array: `0 0 1 2 3 0 1`

### Test Case 2
- Text: `ABABDABACDABABCABAB`
- Pattern: `ABABCABAB`
- Pi Array: `0 0 1 2 0 1 2 3 4`
- Output: `Pattern occurs with shift 10 (Index: 10)`

## 如何編譯與執行

```bash
# 編譯
g++ main.cpp -o KMP

# 執行
./KMP
```
