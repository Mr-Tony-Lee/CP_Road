#include<bits/stdc++.h>
using namespace std;
double a1 , a0 , an1; 
int n ;

// 2ai = ai-1 + ai+1 - 2ci
// 2a1 = a0 + a2 - 2c1 
// 2a2 = a1 + a3 - 2c2 
// a1 = 2a2 - a3 + 2c2 
// a1 = a0 - a2 + a3 - 2c1 - 2c2 
// 2a3 = a2 + a4 - 2c3 
// a1 = a0 - a3 + a4 - 2c1 - 2c2 - 2c3 
// a1 = a0 - an + an1 - 2c1 -.... <0>
// an = a0 - a1 + an+1 - 2c1 - ...
// n 從 1 ~ n 都帶入
// 可以消掉 a2 ~ an 
// 最後變成 
// (n+1)*a[1] = n*a[0] + a[n+1] - 2*[n*c[1] + (n-1)*c[2] + ... + 1*c[n]]

int main(){
    int t;
    cin >> t ;
    while(t--){
        cin >> n ;
        cin.ignore();
        string sa0 , san1;
        getline(cin,sa0);
        //output same format as input 
        int point = 0 ;
        for(int i = 0 ; i < (int)sa0.size() ; i++ ){
            if(sa0[i] == '.'){
                point = sa0.size()-i-1;
                break;
            }
        }
        getline(cin,san1);
        a0 = stof(sa0);
        an1 = stof(san1);
        double sum = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            double x ;
            cin >> x; 
            sum += 2*(n-i)*x;
        }
        double ans = n*a0 + an1 - sum;
        cout << fixed << setprecision(point) <<ans/(n+1) << endl;
        
        if(t) cout << endl;
    }
}
