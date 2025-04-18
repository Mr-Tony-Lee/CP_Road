#include<iostream>
using namespace std;
using ll = long long ;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    while(n--){
        ll a , b ;
        cin >> a >> b ;
        if(((max(a,b) <= 2*min(a,b)) ) && (a+b) % 3 == 0 ){
            cout << "YES" << endl;
        }
        else{
            cout << "NO"<< endl;
        }
    }
}