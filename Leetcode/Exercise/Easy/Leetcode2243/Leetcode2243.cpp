#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k ){
            string res = "";
            int n = s.size();
            for(int i = 0 ; i < n ; i += k){
                int sum = 0;
                for(int j = i ; j < min(i+k, n); j++){
                    sum += s[j] - '0';
                }
                res += to_string(sum);
            }
            s = res;
        }
        return s;
    }
};