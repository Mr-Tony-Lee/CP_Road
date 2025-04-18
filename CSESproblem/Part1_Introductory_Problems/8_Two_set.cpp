#include<iostream>
#include<vector>
using namespace std;
using ll = long long ;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n ;
    ll sum_1 = 0 ;
    ll sum_2 = 0 ;
    vector<ll> push_1;
    vector<ll> push_2;
    for(int i = n ; i >= 1 ; i-- ){
        if(sum_1 >= sum_2){
            sum_2 += i ;
            push_2.push_back(i);
        }
        else{
            sum_1 += i ;
            push_1.push_back(i);
        }
    }
    if(sum_1 == sum_2){
        cout << "YES" << endl;
        cout << push_1.size() << endl;
        for(int i = (int)push_1.size()-1 ; i >= 0 ; i--){
            cout << push_1[i] << " " ;
        }
        cout << endl;
        cout << push_2.size() << endl;
        for(int i = (int)push_2.size()-1 ; i >= 0 ; i--){
            cout << push_2[i] << " " ;
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}