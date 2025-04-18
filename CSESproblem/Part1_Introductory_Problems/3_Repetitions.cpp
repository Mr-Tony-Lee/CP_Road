#include<iostream>
using namespace std;
using ll = long long ;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string input ;
    getline(cin,input);
    char now = '\\';
    ll ans = 0 ;
    ll temp = 1;
    for(int i = 0 ; i < (int)input.size() ; i++){
        if(input[i] != now ){
            ans = max(temp,ans);
            now = input[i];
            temp = 0 ; 
        }
        temp++;
    }
    ans = max(temp,ans);
    cout << ans << endl;
}