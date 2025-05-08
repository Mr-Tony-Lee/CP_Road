#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ;
    while(cin >> N ){
        if( N == 0 ){
            cout << -1 << endl;
            continue;
        }
        vector<int> arr ;
        double avg = 0 ; 
        for(int i = 0 ; i < N ; i++ ){
            int x ;
            cin >> x ;
            arr.push_back(x);
            avg += x ;
        }
        sort(arr.begin() , arr.end());
        double medium = (N & 1) ? arr[arr.size()/2]  : arr[arr.size()/2]+arr[arr.size()/2+1];
        cout << fixed << setprecision(2) << avg/N << " " << medium << endl;
        // Wrong 
    }   
}
// Output : Arnold的家座標 ( 停在每家時的最佳位置 ) Arnold的家座標 ( 不停留時的最佳位置 )

//  平均數 and 中位數 