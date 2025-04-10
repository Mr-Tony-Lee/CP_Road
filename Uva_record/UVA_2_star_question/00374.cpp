#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int B,P,M;
    while(cin >> B >> P >> M ){
        if (P == 0 && B == P ){
            cout << 1 << endl;
            continue;
        }
        int ans = 1 ; 
        int temp = B % M ; 
        while(P && ans ){
            if(P & 1){
                ans *= temp;
                ans %= M;
            }
            temp *= temp;
            temp %= M ;
            P >>= 1 ;
        }
        cout << ans << endl;
    }
}