#include<bits/stdc++.h>
using namespace std;

void print_cut_rod_solution(vector<int>& s, int n) {
    while(n > 0){
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}
void CutRod(vector<int>& p, int n ) {
    vector<int> r(n + 1, 0); // r[i] 儲存長度為 i 的桿子的最大收益
    vector<int> s(n + 1, 0); // s[i] 儲存長度為 i 的桿子的最佳切割點
    for(int j = 1 ; j <= n ; j++ ){
        int q = INT_MIN;
        for(int i = 1 ; i <= j ; i++ ){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i; // 記錄最佳切割點
            }
        }
        r[j] = q;
    }
    cout << "Maximum revenue for rod of length " << n << " is: " << r[n] << endl;
    cout << "Cutting solution: ";
    print_cut_rod_solution(s, n);
}

int main(){
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 7; // 長度為 n 的桿子
    CutRod(p, n);
}