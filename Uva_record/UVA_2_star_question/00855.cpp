#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int s , a , f ;
        cin >> s >> a >> f ;

        int x , y ;
        vector<int> sx , sy ; 
        for(int i = 0 ; i < f ; i++ ){
            cin >> x >> y ;
            sx.push_back(x);
            sy.push_back(y);
        }
        sort(sx.begin() , sx.end());
        sort(sy.begin() , sy.end());
        // 中位數， sigma(|x-xi|) 的 min 就是 xi 中的中位數 
        // sigma(|y-yi|) 的 min 就是 yi 中的中位數
        cout << "(Street: " << sx[((f-1)/2)] << ", Avenue: " << sy[(f-1)/2] << ")"  << endl;  
    }
}
/*
2
2 2 2
1 1
2 2
7 7 11
1 2
1 7
2 2
2 3
2 5
3 4
4 2
4 5
4 6
5 3
6 5
*/