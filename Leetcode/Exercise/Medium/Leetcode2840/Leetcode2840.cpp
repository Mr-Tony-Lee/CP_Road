#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        int r1[26] = {} , r2[26] = {};
        for(int i = 0 ; i < n ; i++ ){
            if(i & 1)
                r1[s1[i]-'a']++, r1[s2[i]-'a']--;            
            else
                r2[s1[i]-'a']++, r2[s2[i]-'a']--;
        }
        for(int i = 0 ; i < 26 ; i++ ){
            if(r1[i] != 0 || r2[i] != 0 ) return false;
        }
        return true;
    }
};
// 9ms, 19.8 MB