#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int cnt = 0 ; 
        for(int i = 1 ; i <= n; i++ ){
            for(int j = 1 ; j <= n ; j++ ){
                int is = (int)sqrt(i*i+j*j);
                double ds = (double)sqrt(i*i+j*j);
                if( is == ds && is <= n ){
                    cnt ++ ;
                }
                if( is >= n ) break;
            }
        }
        return cnt ; 
    }
};