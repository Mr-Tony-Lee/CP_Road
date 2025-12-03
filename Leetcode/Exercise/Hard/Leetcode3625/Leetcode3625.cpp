#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;  // 定義inf 給垂直的線

        unordered_map<double, vector<double>> slopeToIntercept;
        unordered_map<int, vector<double>> midToSlope;
        int ans = 0 ; 

        for(int i = 0 ; i < n ; ++i ){
            int x1 = points[i][0] , y1= points[i][1];
            for(int j = i+1 ; j < n ; ++j ){
                int x2 = points[j][0], y2 = points[j][1];
                double k , b ;  // k -> slope , b ->> y1 = ax1+b  
                int dx = x1 - x2;
                int dy = y1 - y2;
                if (x2 == x1) {
                    k = inf;
                    b = x1;     // 如果垂直就看 x 
                } 
                else {
                    k = (double)dy/dx;
                    // b = (double)y1 - k*x1;   -> 誤差太大
                    b = (double)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for(auto& [_, sti]:slopeToIntercept){
            if (sti.size() == 1) {
                continue;
            }
            map<double, int> cnt;
            for (double b : sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans += sum * count;
                sum += count;
            }
        }
        // 扣除平行四邊形數量 ( 共用中點 -> 兩條線交錯)
        for(auto& [_, mts]:midToSlope){
            if(mts.size() == 1 ){
                continue;
            }
            map<double, int> cnt ;
            for(auto k: mts ){
                cnt[k]++;
            }
            int sum = 0;
            for(auto& [_,count]:cnt){
                ans -= sum*count;
                sum += count;
            }
        }
        return ans ;
    }
    
};