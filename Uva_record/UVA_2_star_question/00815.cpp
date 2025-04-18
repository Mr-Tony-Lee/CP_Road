#include<bits/stdc++.h>
using namespace std;

int main(){
    int m , n ;
    int kase = 0 ;
    while(cin >> m >> n && (m || n)){
        map<int,int> record;
        
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                int x ; 
                cin >> x ;
                record[x]++;
            }
        }
        double total ;
        cin >> total;
        double ans = 0 ; 
        while(total > 0 ){
            if(record.size() == 1 ){
                ans = 1.0*total/(record.begin()->second*100) + record.begin()->first;
                break;
            }
            auto iter = record.begin();
            iter++;
            int distance = iter->first - record.begin()->first ;
            if(total > distance * record.begin()->second * 100 ) {
                total -= distance * record.begin()->second * 100;
                iter->second += record.begin()->second;
                record.erase(record.begin());
                ans = iter->first;
            }
            else{
                ans = 1.0*total/(record.begin()->second*100) + record.begin()->first;
                total = 0 ;
            }
            // cout << "now total : " << total << " " << record.size() << "--------------------------"<< endl;
            // for(auto& it:record){
            //     cout << it.first << " " << it.second << endl;
            // }
            // cout << endl;
        }
        cout << "Region " << ++kase << endl;
        cout << "Water level is " << fixed << setprecision(2) << ans << " meters." << endl;
        cout << fixed << setprecision(2) << 100.0*record.begin()->second / (m*n) << " percent of the region is under water." << endl;
        cout << endl;
    }
}
/*
3 3
25 37 45
51 12 34
94 83 27
35000
0 0
*/