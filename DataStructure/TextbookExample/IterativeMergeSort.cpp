#include <iostream>
#include <algorithm> // 引入 std::copy

using namespace std;

// 輔助函數：將 initList[i..m] 和 initList[m+1..r] 合併到 resultList
// 注意：陣列索引從 1 開始
template <class T>
void Merge(T *initList, T *resultList, const int i, const int m, const int r) {
    int j = m + 1; // 第二個子列表的起始索引
    int k = i;     // resultList 的寫入索引
    int p = i;     // 第一個子列表的當前索引
    
    // 合併兩個子列表
    while (p <= m && j <= r) {
        if (initList[p] <= initList[j]) {
            resultList[k++] = initList[p++];
        } else {
            resultList[k++] = initList[j++];
        }
    }

    // 複製剩餘的元素
    copy(initList + p, initList + m + 1, resultList + k); // 複製第一個子列表剩餘部分
    copy(initList + j, initList + r + 1, resultList + k + (m - p + 1)); // 複製第二個子列表剩餘部分
}

// 歸併排序的一趟操作 (子列表大小為 s)
template <class T>
void MergePass(T *initList, T *resultList, const int n, const int s) {
    int i; // 確保 i 在循環結束後仍然可用

    // 處理能組成完整 2s 大小的區段
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s) {
        // 合併 [i .. i+s-1] 和 [i+s .. i+2*s-1]
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    }
    
    // 處理剩餘的區段
    // 剩餘區段從 i 開始，長度可能不足 2s
    
    if (i + s - 1 < n) {
        // 剩餘部分包含兩個子列表，但第二個可能不滿 s 個元素
        // 合併 [i .. i+s-1] 和 [i+s .. n]
        Merge(initList, resultList, i, i + s - 1, n);
    } else {
        // 剩餘部分不足 s 個元素，直接複製
        // 複製 [i .. n]
        copy(initList + i, initList + n + 1, resultList + i);
    }
    
    // 輸出當前歸併過程
    cout << "\n  --- MergePass (s = " << s << ") ---";
    cout << "\n  Result List: ";
    for(int j = 1; j <= n; j++) {
        cout << resultList[j] << " ";
    }
}

// 自底向上非遞歸歸併排序
template <class T>
void MergeSort(T* a, const int n) {
    T* tempList = new T[n + 1]; // 臨時陣列
    bool useTemp = false; // 追蹤結果是在 a 還是 tempList 中

    // l 是當前子列表的大小，從 1, 2, 4, 8, ... 變化
    for (int l = 1; l < n; l *= 2) {
        if (useTemp) {
            // 上一趟結果在 tempList，這次合併到 a
            MergePass(tempList, a, n, l);
        } else {
            // 上一趟結果在 a，這次合併到 tempList
            MergePass(a, tempList, n, l);
        }
        useTemp = !useTemp; // 切換輸出目標
    }

    // 確保最終結果在 a 中
    if (useTemp) {
        // 如果最後一趟的結果在 tempList 中，則需要複製回 a
        copy(tempList + 1, tempList + n + 1, a + 1);
    }
    
    delete[] tempList;
}

int main() {
    const int n = 6;
    // 陣列索引從 1 開始，a[0] 不使用
    int a[n + 1] = {0, 26, 5, 77, 1, 61, 11};
    
    cout << "Original array (index 1 to " << n << "): ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n" << string(50, '=') << "\n";
    
    MergeSort(a, n);

    cout << "\n" << string(50, '=') << "\n";
    cout << "Final Sorted array (index 1 to " << n << "): ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}