#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,vector<string>> tmp;
        
        set<string> cat = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i = 0 ; i < code.size(); i++ ){
            if(isActive[i] && code[i].size() > 0 ){
                bool flag = true;
                for(int j = 0 ; j < code[i].size() ; j++ ){
                    if(!(isalnum(code[i][j]) || code[i][j] == '_')){
                        flag = false;
                        break;
                    }
                }
                if(!cat.count(businessLine[i]) ){
                    flag = false;
                }
                if(flag){
                    tmp[businessLine[i]].push_back(code[i]);
                }
            }
        }
        vector<string> ans ;
        for(auto& [_,v]:tmp){
            sort(v.begin(), v.end());
            for(auto& s:v){
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};