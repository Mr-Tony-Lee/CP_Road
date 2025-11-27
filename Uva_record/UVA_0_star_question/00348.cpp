#include<bits/stdc++.h>
using namespace std;


// (A1 x (A2 x A3))
// ((A1 x A2) x A3)
// ((A1 x (A2 x A3)) x ((A4 x A5) x A6))
// 要放 x 到正確的位置
void print_optimal_parens(vector<vector<int>> &s, int i, int j, int n) {
    if(i == j){
        cout << "A" << i;
    }
    else{
        cout << "(";
        print_optimal_parens(s, i, s[i][j], n);
        cout << " x ";
        print_optimal_parens(s, s[i][j] + 1, j, n);
        cout << ")";
    }
}

int main(){
    int n ;
    int kase = 0 ;
    while(cin >> n , n ){
        vector<int> p(n+1);
        for(int i = 0 ; i < n ; i++ ){
            int r , c;
            cin >> r >> c;
            p[i] = r;
            if(i == n - 1){
                p[i+1] = c;
            }
        }
        // m[i][j] 儲存從矩陣 Ai 到 Aj 的最小乘法次數
        vector<vector<int>> m(n+1, vector<int>(n+1, 0));
        // s[i][j] 儲存從矩陣 Ai 到 Aj 的最佳分割點
        vector<vector<int>> s(n+1, vector<int>(n+1, 0));
        for(int l = 2 ; l <= n ; l++ ){ // l 是鏈長
            for(int i = 1 ; i <= n - l + 1 ; i++ ){
                int j = i + l - 1;
                m[i][j] = INT_MAX;
                for(int k = i ; k < j ; k++ ){
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if(q < m[i][j]){
                        m[i][j] = q;
                        s[i][j] = k; // 記錄最佳分割點
                    }
                }
            }
        }
        cout << "Case " << ++kase << ": ";
        print_optimal_parens(s,1, n, n);
        cout << endl;
    }
}
// Uva00348 - Matrix Chain Multiplication
// Accepted