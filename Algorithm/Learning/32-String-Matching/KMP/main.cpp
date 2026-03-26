#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 計算 Prefix Function (pi array)
// 對應偽代碼 COMPUTE-PREFIX-FUNCTION(P)
// 注意：偽代碼是 1-based indexing，這裡是 0-based indexing
vector<int> ComputePrefixFunction(const string& P) {
    int m = P.length();
    vector<int> pi(m);

    // 3 line: pi[1] = 0 (對應 C++ pi[0] = 0)
    pi[0] = 0;
    
    // 4 line: k = 0
    int k = 0;

    // 5 line: for q = 2 to m (對應 C++ q = 1 to m-1)
    for (int q = 1; q < m; ++q) {
        // 6 line: while k > 0 and P[k+1] != P[q] (對應 C++ P[k] != P[q])
        // P[k] 是下一個要匹配的字符 (因為 k 是長度，也是下一個 index)
        while (k > 0 && P[k] != P[q]) {
            // 7 line: k = pi[k] (對應 C++ pi[k-1])
            k = pi[k - 1];
        }

        // 8 line: if P[k+1] == P[q] (對應 C++ P[k] == P[q])
        if (P[k] == P[q]) {
            // 9 line: k = k + 1
            k = k + 1;
        }

        // 10 line: pi[q] = k
        pi[q] = k;
    }

    return pi;
}

// KMP Matcher
// 對應偽代碼 KMP-MATCHER(T, P)
void KMP_Matcher(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();

    if (m == 0) return;

    // 3 line: pi = COMPUTE-PREFIX-FUNCTION(P)
    vector<int> pi = ComputePrefixFunction(P);

    // 4 line: q = 0 (number of characters matched)
    int q = 0;

    cout << "Text: " << T << endl;
    cout << "Pattern: " << P << endl;
    cout << "Prefix Function (pi): ";
    for (int val : pi) cout << val << " ";
    cout << endl << endl;

    // 5 line: for i = 1 to n (對應 C++ i = 0 to n-1)
    for (int i = 0; i < n; ++i) {
        // 6 line: while q > 0 and P[q+1] != T[i] (對應 C++ P[q] != T[i])
        while (q > 0 && P[q] != T[i]) {
            // 7 line: q = pi[q] (對應 C++ pi[q-1])
            q = pi[q - 1];
        }

        // 8 line: if P[q+1] == T[i] (對應 C++ P[q] == T[i])
        if (P[q] == T[i]) {
            // 9 line: q = q + 1
            q = q + 1;
        }

        // 10 line: if q == m
        if (q == m) {
            // 11 line: print "Pattern occurs with shift" i - m
            // 在 0-based indexing 中，匹配的起始位置是 i - m + 1
            cout << "Pattern occurs with shift " << (i - m + 1) << " (Index: " << (i - m + 1) << ")" << endl;
            
            // 12 line: q = pi[q] (對應 C++ pi[q-1])
            // 尋找下一個可能的匹配
            q = pi[q - 1];
        }
    }
}

int main() {
    // 測試範例
    string text = "bacbababaabcbab";
    string pattern = "ababaca";

    // 為了演示 pi array 的效果，我們使用一個更有趣的 pattern
    // 例如 CLRS 書中的例子 P = "ababaca"
    // T 可以隨意設定
    
    // 測試 1
    cout << "--- Test Case 1 ---" << endl;
    KMP_Matcher("bacbababaabcbab", "ababaca");

    // 測試 2: 簡單重複
    cout << "\n--- Test Case 2 ---" << endl;
    KMP_Matcher("ABABDABACDABABCABAB", "ABABCABAB");

    return 0;
}
