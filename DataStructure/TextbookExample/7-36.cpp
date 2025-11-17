#include<bits/stdc++.h>
using namespace std;

template<typename T>
int ListMerge(T* a, int* link, const int start1, const int start2){
  int iResult = 0; 
  int i1 = start1, i2 = start2;
  for (; i1 && i2; ){
    if (a[i1] <= a[i2]) {
        link[iResult] = i1;
        iResult = i1; i1 = link[i1];  
    }
    else {
        link[iResult] = i2;
        iResult = i2; i2 = link[i2];  
    }
}
  if (i1 == 0) link[iResult] = i2;
  else link[iResult] = i1;
  return link[0];
}
template<typename T>
int rMergeSort(T* a, int* link, const int left, const int right){
  if (left >= right) return left; 
  int mid = (left + right) /2;
  
  return ListMerge(a, link,rMergeSort(a, link, left, mid), rMergeSort(a, link, mid + 1, right));	
}


int main(){
    const int n = 6;
    int a[n+1] = {0, 26, 5, 77, 1, 61, 11}; // index 0 is dummy
    int link[n+1];
    
    cout << "Original array (index 1 to " << n << "): ";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
        link[i] = 0; // initialize link
    }
    cout << "\n\n";
    rMergeSort(a, link, 1, n);
    cout << "Link array after sorting:\n";
    for(int i = 0; i <= n; i++) 
        cout << "link[" << i << "] = " << link[i] << endl;
    cout << endl;

    cout << "Link array and original array: " << endl;
    for(int i = 0 ; link[i] != 0 ; i = link[i])
        cout << "link[" << i << "] = " << link[i] << " -> a" << "[" << link[i] << "] = " << a[link[i]] << endl;
    
    return 0;
}