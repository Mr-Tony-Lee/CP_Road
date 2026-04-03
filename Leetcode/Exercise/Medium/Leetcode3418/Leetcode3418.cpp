class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> ans (m, vector<vector<int>>(n, vector<int>(3,0)));
        ans[0][0][0] = coins[0][0];
        for(int i = 1 ; i < m ; i++ ){
            int max0 = ans[i-1][0][0];
            int max1 = ans[i-1][0][1];
            int max2 = ans[i-1][0][2];
            ans[i][0][0] = max0 + coins[i][0];
            ans[i][0][1] = ( coins[i][0] < 0 ) ? max(max0, max1+coins[i][0]) : max1+coins[i][0];
            ans[i][0][2] = ( coins[i][0] < 0 ) ? max(max1, max2+coins[i][0]) : max2+coins[i][0];
        }
        for(int j = 1 ; j < n ; j++ ){
            int max0 = ans[0][j-1][0];
            int max1 = ans[0][j-1][1];
            int max2 = ans[0][j-1][2];
            ans[0][j][0] = max0 + coins[0][j];
            ans[0][j][1] = ( coins[0][j] < 0 ) ? max(max0, max1+coins[0][j]) : max1+coins[0][j];
            ans[0][j][2] = ( coins[0][j] < 0 ) ? max(max1, max2+coins[0][j]) : max2+coins[0][j];
        }
        for(int i = 1 ; i < m ; i++ ){
            for(int j = 1 ; j < n ; j++ ){
                int max0 = max(ans[i-1][j][0] , ans[i][j-1][0]);
                int max1 = max(ans[i-1][j][1] , ans[i][j-1][1]);
                int max2 = max(ans[i-1][j][2] , ans[i][j-1][2]);
                ans[i][j][0] = max0 + coins[i][j];
                ans[i][j][1] = ( coins[i][j] < 0 ) ? max(max0, max1+coins[i][j]) : max1+coins[i][j];
                ans[i][j][2] = ( coins[i][j] < 0 ) ? max(max1, max2+coins[i][j]) : max2+coins[i][j];
            }
        }
        return max({ans[m-1][n-1][0], ans[m-1][n-1][1], ans[m-1][n-1][2]});
    }
};
// 453ms , 276.04 MB