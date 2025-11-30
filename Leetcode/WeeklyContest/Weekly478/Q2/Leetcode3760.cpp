// 3760. Maximum Substrings With Distinct Start©leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinct(string s) {
        set<char> d ; 
        for(int i = 0 ; i < s.size() ; i++ ){
            d.insert(s[i]);
        }
        return d.size();
    }
};
// 23ms, 25.38MB