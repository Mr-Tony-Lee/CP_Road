#include<bits/stdc++.h>
using namespace std;

bool cmp(const vector<int>& a , const vector<int>& b ){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int end_last = points[0][1];
        int ans = 1 ;
        for(int i = 1 ; i < points.size() ; i++ ){
            if(points[i][0] > end_last){
                end_last = points[i][1];
                ans++;
            }
        }
        return ans ; 
    }
};