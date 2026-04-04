#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if( rows == 1 || n == 0 ) return encodedText;
        int cols = n / rows;
        vector<vector<char>> mat(rows,vector<char>(cols)) ;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++ ){
                mat[i][j] = encodedText[i*cols+j];
            }
        }

        string ans ;
        int i = 0 , j = 0 ; 
        int first_j = 0 ; 
        while(ans.size() < cols*rows-(rows*rows-rows)/2 ){
            ans.push_back(mat[i++][j++]);
            if( i == rows || j == cols){
                i = 0 ;
                j = ++first_j;
            }
        }
        for(int i = ans.size()-1 ; i >= 0; i-- ){
            if(ans[i] != ' '){
                break;
            }
            ans.pop_back();
        }
        return ans;
    }
};
// 40ms, 43.4 MB