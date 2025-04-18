#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
using ll = long long ;
vector<string> generGC(int n ){
    if(n == 1 ){
        return {"0","1"};
    }
    vector<string> pre = generGC(n-1);
    ll bound = pow(2,n);
    vector<string> now(bound,"");
    ll index = 0 ;
    while(index < bound/2 ){
        now[index] = "0" + pre[index];
        now[bound-index-1] = "1"+pre[index];
        index++;
    }
    return now ;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    vector<string> GrayCode = generGC(n);
    int count = 0 ;
    for(auto& iter : GrayCode ){
        cout << iter << " " << count++ << endl;
    }
}