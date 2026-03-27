#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || numRows >= n ) return s ;
        
        vector<string> row_s(numRows,""); 
        
        bool dir_down = true ;
        int now_row = 0 ; 
        
        for(int i = 0 ; i < n ; i++ ){
            row_s[now_row] += s[i];
            
            now_row += (dir_down ? 1 : -1) ;
            
            if(now_row == 0 || now_row == numRows-1){
                dir_down = !dir_down;
            }
            
        }
       
        string ans ;
        for(auto& iter:row_s){
            ans += iter;
        }
        return ans;
    }
};
