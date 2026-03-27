#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        bool check = true;
        for(int i = 0 ; i < m ; ++i ){
            for(int j = 0 ; j < n ; ++j ){
                if(i & 1){
                    if(mat[i][(j+k)%n] != mat[i][j]){
                        check = false;
                        break;
                    }
                }
                else{
                    int after_index = j-k;
                    while(after_index < 0 ) after_index += n ;
                    if(mat[i][after_index % n] != mat[i][j]){
                        check = false;
                        break;
                    }
                }
            }
            if(!check) break;
        }
        return check ;
    }
};
// 0ms, 31.36 MB