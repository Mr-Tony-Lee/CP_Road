#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int num){
        string s = "";
        while( num > 0 ){
            if(num & 1 ) s.push_back('1');
            else s.push_back('0');
            num >>= 1 ;
        }
        int l = 0 , r = s.size()-1;
        while( l < r ){
            if(s[l] != s[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for(auto& num : nums ){
            int k = 0 ;
            while(true){
                if(isPalindrome(num+k) || isPalindrome(num-k)){
                    ans.push_back(k);
                    break;
                }
                k++;
            }
        }
        return ans;
    }
};