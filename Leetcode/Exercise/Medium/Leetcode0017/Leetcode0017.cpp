#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> arr = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    void recur(vector<string>& ans , const string& digits , int index , string& now){
        if(now.size() == digits.size()){
            ans.push_back(now);
            return ;
        }
        for(int i = 0  ; i < arr[digits[index]-'2'].size(); i++ ){
            now.push_back(arr[digits[index]-'2'][i]);
            recur(ans,digits, index+1 , now);
            now.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {        
        vector<string> ans ;
        string now = "";
        recur(ans , digits, 0, now);
        return ans;
    }
};
// 0ms , 9.23MB