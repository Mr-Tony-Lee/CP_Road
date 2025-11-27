#include<bits/stdc++.h>
using namespace std;

int n ;
vector<vector<int>> m; 
vector<vector<int>> s;


void matrix_chain_order(const vector<int>& p) {
    n = p.size() - 1; // 矩陣數量
    m.assign(n+1, vector<int>(n+1, 0));
    s.assign(n+1, vector<int>(n+1, 0));
    for(int i = 1 ; i <= n ; i++ ){
        m[i][i] = 0; // 單個矩陣的計算成本為0
    }
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
    cout << "Minimum number of multiplications is: " << m[1][n] << endl;
}
void print_optimal_parens(int i, int j) {
    if(i == j){
        cout << "A" << i;
    }
    else{
        cout << "(";
        print_optimal_parens(i, s[i][j]);
        cout << " x ";
        print_optimal_parens(s[i][j] + 1, j);
        cout << ")";
    }
}

int main(){
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    matrix_chain_order(p);
    print_optimal_parens(1, n);
    cout << endl;
}