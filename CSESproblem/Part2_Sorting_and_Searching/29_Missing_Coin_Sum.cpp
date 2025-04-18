#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long ;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    vector<int> a;
    for(int i = 0 ; i < n ; i++ ){
        int x ;
        cin >> x ;
        a.push_back(x);
    }
    sort(a.begin() , a.end());
    
    // using greedy. 
    ll max = 1ll;   // initially , set max as 1 , if vector haven't 1 , ans is 1 
    for(int i = 0 ; i < n ; i++ ){
        if(a[i] > max ){    // if a[i] > max , means max can not be composed of by the element in vector
            break;  // break and output max 
        }
        max += a[i];    // every times , max += a[i] 
    }
    cout << max << endl;
}

// https://www.geeksforgeeks.org/cses-solutions-missing-coin-sum/