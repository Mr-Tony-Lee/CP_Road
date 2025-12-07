# LeetCode Biweekly Contest 171 Q4 - Minimum Inversions in a Sliding Window

## 題目思路 (Intuition)

這道題很明顯是一個滑動窗口 (Sliding Window) 的問題。
我們需要一個數據結構來維護窗口內的狀態，具體來說需要具備以下功能：

1.  **插入元素 (Expand)**: 將窗口向右擴展，加入一個新元素。
2.  **移除元素 (Shrink)**: 將窗口左端收縮，移除最舊的元素。
3.  **維護逆序對數量**: 在每次操作後，能夠快速更新窗口內的逆序對數量。

為了維護逆序對數量，我們可以觀察到：
*   當我們在窗口右端加入一個元素 `x` 時，逆序對的增加量等於窗口內 **大於 `x` 的元素個數**。
*   當我們從窗口左端移除一個元素 `x` 時，逆序對的減少量等於窗口內 **小於 `x` 的元素個數** (因為 `x` 原本在這些元素左邊且比它們大)。

---

## 暴力解法 (Brute Force)

為了視覺化這個過程，我們可以先寫出一個暴力解法的結構：

```cpp
struct SLIDING_WINDOW {
    long long inv_count = 0;
    deque<int> window;
    
    // 加入元素 x
    void expand(int x) {
        for(auto u : window) {
            if(u > x) {
                inv_count += 1;
            }
        }
        window.push_back(x);
    }
    
    // 移除最左邊的元素
    void shrink() {
        int x = window.front();
        window.pop_front();
        for(auto u : window) {
            if(x > u) {
                inv_count -= 1;
            }
        }
    }
};
```

使用方式如下：

```cpp
long long minInversionCount(vector<int>& nums, int k) {
    int n = (int)nums.size();
    SLIDING_WINDOW SW;
    // 初始化第一個窗口
    for(int i = 0; i < k; i ++) SW.expand(nums[i]);
    
    long long ans = SW.inv_count;
    // 滑動窗口
    for(int i = k; i < n; i ++){
        SW.shrink();
        SW.expand(nums[i]);
        ans = min(ans, SW.inv_count);
    }
    return ans;
}
```

**複雜度分析**:
*   `expand` 和 `shrink` 操作都需要遍歷當前窗口，複雜度為 $O(K)$。
*   總時間複雜度為 $O(N \cdot K)$。這在 $N, K$ 較大時會超時。

---

## 優化思路 (Optimization)

### STL 的限制
我們發現 `expand` 和 `shrink` 的本質是在計算結構內比 `x` 大或小的元素個數。
使用基本的 STL 容器 (如 `vector`, `deque`) 無法突破 $O(K)$ 的限制。即使使用 `multiset`，雖然插入刪除是 $O(\log K)$，但計算「比 x 大的元素個數」仍然需要 $O(K)$ (使用 `distance`) 或者需要使用非標準的 Policy Based Data Structure (Ordered Set)。

### 使用 Fenwick Tree (樹狀數組) 或 Segment Tree (線段樹)
為了在 $O(\log N)$ 的時間內完成插入、刪除和計數，我們可以使用 **Fenwick Tree (BIT)** 或 **Segment Tree**。

### 技巧 1：離散化 (Coordinate Compression)
如果數組中的數值很大 (例如 $10^9$)，直接開這麼大的 BIT 是不可能的。
但在這個問題中，數值的具體大小不重要，重要的是它們的 **相對大小關係**。
例如 `[300, 100, 200]` 和 `[3, 1, 2]` 的逆序對數量是一樣的。

因此，我們可以將數值映射到 $[1, m]$ 的範圍內，其中 $m$ 是不同數值的個數。

```cpp
set<int> S;
for(auto x : nums) S.insert(x); // 自動排序去重

int m = 1;
map<int, int> convert;
for(auto x : S) convert[x] = m++; // 建立映射

for(auto &x : nums) x = convert[x]; // 轉換原數組
```

### 如何利用前綴和計數 (Prefix Sums / BIT)
我們可以維護一個數組 (或 BIT)，其中第 `i` 個位置存儲數值 `i` 在當前窗口中出現的次數。
*   **查詢**: `sum(k)` 返回數值在 $[1, k]$ 範圍內的元素總數。
*   **更新**: `upd(k, v)` 將數值 `k` 的計數增加 `v`。

**結合滑動窗口**:
1.  **Expand(x)**:
    *   逆序對增加量 = (窗口內當前總元素個數) - (窗口內 $\le x$ 的元素個數)
    *   即 `B.sum(m) - B.sum(x)` (這裡 `m` 是最大值，`B.sum(m)` 等於窗口大小)
    *   更新 BIT: `B.upd(x, 1)`
2.  **Shrink**:
    *   設移除的元素為 `x`。
    *   逆序對減少量 = (窗口內 $< x$ 的元素個數)
    *   即 `B.sum(x - 1)`
    *   更新 BIT: `B.upd(x, -1)`

---

## 完整代碼 (Full Code)

```cpp
class Solution {
public:
    // 樹狀數組 (Binary Indexed Tree)
    struct BIT {
        int n;
        vector<int> bit;
        BIT() {}
        BIT(int _n) {
            n = _n;
            bit = vector<int>(n + 1, 0);
        }
        // 單點更新
        void upd(int k, int v) {
            while(k <= n) {
                bit[k] += v;
                k += k & -k;
            }
        }
        // 前綴和查詢
        int sum(int k) {
            int s = 0;
            while(k > 0) {
                s += bit[k];
                k -= k & -k;
            }
            return s;
        }
    };

    struct SLIDING_WINDOW {
        long long inv_count;
        deque<int> window;
        int m;
        BIT B;
        
        SLIDING_WINDOW(int _m) {
            inv_count = 0;
            m = _m;
            B = BIT(m);
        }
        
        void expand(int x) {
            // 增加逆序對：比 x 大的數的個數
            // = 當前總數 - 小於等於 x 的數的個數
            inv_count += B.sum(m) - B.sum(x);
            
            window.push_back(x);
            B.upd(x, +1);
        }
        
        void shrink() {
            int x = window.front();
            // 減少逆序對：比 x 小的數的個數
            // = 小於等於 x-1 的數的個數
            inv_count -= B.sum(x - 1);
            
            window.pop_front();
            B.upd(x, -1);
        }
    };

    long long minInversionCount(vector<int>& nums, int k) {
        int n = (int)nums.size();

        // 1. 離散化 (Coordinate Compression)
        set<int> S;
        for(auto x : nums) {
            S.insert(x);
        }
        int m = 1;
        map<int, int> convert;
        for(auto x : S) {
            convert[x] = m++;
        }
        for(auto &x : nums) {
            x = convert[x];
        }
        
        // 2. 滑動窗口 + BIT
        SLIDING_WINDOW SW(m);
        
        // 初始化第一個窗口
        for(int i = 0; i < k; i ++) SW.expand(nums[i]);
        
        long long ans = SW.inv_count;
        
        // 開始滑動
        for(int i = k; i < n; i ++){
            SW.shrink();
            SW.expand(nums[i]);
            ans = min(ans, SW.inv_count);
        }
        return ans;
    }
};
```

## 複雜度分析 (Complexity)

*   **時間複雜度**: $O(N \log N)$
    *   離散化需要 $O(N \log N)$。
    *   滑動窗口過程中，每個元素進出一次，每次 BIT 操作為 $O(\log N)$ (更準確說是 $O(\log m)$，其中 $m \le N$)。
*   **空間複雜度**: $O(N)$
    *   用於存儲離散化映射、BIT 和窗口。
