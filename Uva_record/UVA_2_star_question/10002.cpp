#include<bits/stdc++.h>
using namespace std;
double cx = 0 , cy = 0 ;

typedef pair<int,int> P ;

double polygon_area(P a , P b ){
    return 1.0*(a.first * b.second - a.second * b.first) ;
}

double cmp (P a , P b ){
    double angle_a = atan2(a.second - cy, a.first - cx);
    double angle_b = atan2(b.second - cy, b.first - cx);
    return angle_a < angle_b;
}

int main(){
    int n ;
    while( cin >> n ){
        if( n < 3 ) break;
        double sx = 0 , sy = 0 ;
        double base = 0 ;
        cx = 0 , cy = 0 ;
        vector<P> point ; 
        for(int i = 0 ; i < n ; i++ ){
            int x  , y ;
            cin >> x >> y ;
            point.push_back({x,y});
            cx += x ;
            cy += y ;
        }
        cx /= n , cy /= n ;
        // 利用 arctangent 去求角度 c 跟 a 的向量跟 x 軸的角度，利用這個角度去排序 ! 保證點是有順序的排
        sort(point.begin(), point.end(), cmp);
        
        for(int i = 0 ; i < (int)point.size() ; i++ ){
            int j = (i+1) % point.size() ; 
            cout << "Point index : " << i << " " << j << endl;
            double area = polygon_area(point[i],point[j]);
            sx += (point[i].first + point[j].first) * area ;
            sy += (point[i].second + point[j].second) * area ;
            base += area ;
        }
        sx /= 3 * base ;
        sy /= 3 * base ;
        cout << fixed << setprecision(3) << sx << " " << sy << endl;
    }
}
// 參考資料 : 
/*
4 0 1 1 1 0 0 1 0
3 1 2 1 0 0 0
7
-4 -4 
-6 -3 
-4 -10
-7 -12
-9 -8 
-3 -6 
-8 -3
1
*/