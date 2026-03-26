#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        vector<int> pi(m, 0);
        int k = 0 ; // 最長的prefix 等於 P[0~q] 的suffix
        pi[0] = 0;
        for(int q = 1 ; q < m ; q++){
            while(k > 0 && s[k] != s[q]){
                k = pi[k-1];
            }
            if(s[k] == s[q]){
                k++;
            }
            pi[q] = k;
        }
        if(pi[m-1] != 0 && m % (m - pi[m-1]) == 0 ){
            return true;
        }
        return false;
    }
};