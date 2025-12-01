#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 1; 
        long long sum_batteries = 0 ;
        for(int i = 0 ; i < batteries.size() ; i++ ){
            sum_batteries += batteries[i];
        }
        long long right = sum_batteries/n;

        while( left < right ){
            long long target = right - (right-left)/2;
            
            long long charge = 0 ;
            for(int i = 0 ; i < batteries.size() ; i++ ){
                charge += min((long long)batteries[i], target);
            }
            if((charge / n) >= target){
                left = target;
            }
            else{
                right = target-1;
            }
        }
        return left;
    }
};