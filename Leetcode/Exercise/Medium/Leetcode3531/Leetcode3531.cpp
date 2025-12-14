#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minX(n+1,n+1);
        vector<int> maxX(n+1, 0);
        vector<int> minY(n+1, n+1);
        vector<int> maxY(n+1, 0 );
        for(auto& p:buildings ){
            int x = p[0], y = p[1];
            minX[y] = min(minX[y],x);
            maxX[y] = max(maxX[y],x);
            minY[x] = min(minY[x],y);
            maxY[x] = max(maxY[x],y);
        }
        int ans = 0 ;
        for(auto& p:buildings){
            int x = p[0], y = p[1];
            if(minX[y] < x && x < maxX[y] && minY[x] < y && y <  maxY[x] ){
                ans ++;
            }
        }
        return ans;
    }
};