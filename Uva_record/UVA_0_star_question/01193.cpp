#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(pair<double, double> a , pair<double, double> b ){
    return a.second < b.second;
}

int main(){
    int n , d ;
    int count = 0 ;
    while( cin >> n >> d ){
        count ++ ;
        if(n == 0 && d == 0 ) break;
        vector<pair<double,double>> interval ;
        bool flag = true;
        for(int i = 0 ; i < n ; i++ ){
            double x , y ;
            cin >> x >> y ;
            if( y > d ){
                flag = false ;
                continue;
            }
            double left = x - sqrt(d*d-y*y);
            double right = x + sqrt(d*d-y*y);
            interval.push_back(make_pair(left,right));
        }
        if(!flag){
            cout << "Case " << count <<  ": " << -1 << endl; 
            continue;
        } 
        sort(interval.begin() , interval.end() , cmp);
        int now_right = interval[0].second;
        int ans = 1 ;
        for(auto& iter: interval){
            if(iter.first > now_right ){
                now_right = iter.second;
                ans++ ;
            }
        }
        cout << "Case " << count <<  ": " << ans << endl; 
    }
}
//Accepted online judge