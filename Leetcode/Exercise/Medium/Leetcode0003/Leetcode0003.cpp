#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        vector<int> char_index(128,-1);
        int max_len = 0 ;
        int left = 0 ; 
       
        for(int right = 0 ; right < n ; right++){
            char cur_char = s[right];
            if(char_index[cur_char] >= left ){  // if repeat 
                left = char_index[cur_char]+1;  // update left pointer 
            }
            char_index[cur_char] = right;   // update char_index;
            max_len = max(max_len, right - left+1);
        }
        return max_len;
    }
};
// 3ms, 10.92 MB