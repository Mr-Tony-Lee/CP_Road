#include<bits/stdc++.h>
using namespace std;

template <class T>
void Adjust(T *a, const int root, const int n){
    cout << "  Adjust( root = " << root << ", n = " << n << " )\n";
    T e = a[root];
    int j;
    for (j = 2*root; j <= n; j *= 2) {
        if (j < n && a[j] < a[j+1]) {
            cout << "    Comparing a[" << j << "] = " << a[j] << " with a[" << j+1 << "] = " << a[j+1] << ", choose j = " << j+1 << "\n";
            j++;
        }
        if (e >= a[j]) {
            cout << "    e = " << e << " >= a[" << j << "] = " << a[j] << ", break\n";
            break;
        }
        cout << "    Move a[" << j << "] = " << a[j] << " to a[" << j/2 << "]\n";
        a[j / 2] = a[j]; 
    }
    cout << "    Place e = " << e << " at a[" << j/2 << "]\n";
    a[j / 2] = e;
}

template <class T>
void HeapSort(T *a, const int n){
    cout << "\n=== Building Max Heap ===\n";
    for (int i = n/2; i >= 1; i--) {
        cout << "Step " << (n/2 - i + 1) << ": ";
        Adjust(a, i, n);
        cout << "  Array: ";
        for(int k = 1; k <= n; k++) cout << a[k] << " ";
        cout << "\n";
    }
    
    cout << "\n=== Sorting Phase ===\n";
    for (int i = n-1; i >= 1; i--){
        cout << "\nStep " << (n - i) << ": Swap a[1] = " << a[1] << " with a[" << i+1 << "] = " << a[i+1] << "\n";
        swap(a[1], a[i+1]);	
        cout << "  After swap: ";
        for(int k = 1; k <= n; k++) cout << a[k] << " ";
        cout << "\n";
        Adjust(a, 1, i);
        cout << "  After adjust: ";
        for(int k = 1; k <= n; k++) cout << a[k] << " ";
        cout << "\n";
    }
}

int main(){
    const int n = 6;
    int a[n+1] = {0, 26, 5, 77, 1, 61, 11};
    
    cout << "================================\n";
    cout << "   Heap Sort Demonstration\n";
    cout << "================================\n";

    cout << "\nOriginal array (index 1 to " << n << "): ";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    HeapSort(a, n);
    
    cout << "\n================================\n";
    cout << "Final sorted array: ";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n================================\n";
    
    return 0;
}