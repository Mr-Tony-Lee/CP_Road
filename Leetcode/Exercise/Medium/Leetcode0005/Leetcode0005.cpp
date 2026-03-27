#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int start_index = 0 ;
    int max_Len = 0 ;
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ; i++ ){
            check(s, i, i);
            check(s, i, i+1); 
        }
        return s.substr(start_index, max_Len);
    }
    void check(const string& s, int left , int right){
        while( left >= 0 && right < s.size() && s[left] == s[right] ){
            left--, right++;
        }
        left++ , right--;
        if(right - left + 1 > max_Len ){
            start_index = left ;
            max_Len = right - left +1 ;
        }
        
    }
};
// 4ms, 9.18 MB