#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7 ;
        int s = 0, p = 0 ; 
        long long ans= 0 ;
        for(int i = 0 ; i < corridor.size() ; ++i ){
            if(corridor[i] == 'S') s++;
            if(s % 2 == 0 && s != 0 ){
                if(corridor[i] == 'P') p++;
            }
            else{
                if( ans == 0 ) ans = p+1;
                else ans *= p+1;
                ans %= mod;
                p = 0 ;
            }
        } 
        if(s & 1 || s < 2) return 0 ;
        
        return ans ;
    }
};

// DP Solution
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initialize the array to store the result of each sub-problem
        int count[corridor.length() + 1][3];

        // Base cases
        count[corridor.length()][0] = 0;
        count[corridor.length()][1] = 0;
        count[corridor.length()][2] = 1;

        // Fill the array in a bottom-up fashion
        for (int index = corridor.length() - 1; index >= 0; index--) {
            if (corridor[index] == 'S') {
                count[index][0] = count[index + 1][1];
                count[index][1] = count[index + 1][2];
                count[index][2] = count[index + 1][1];
            } else {
                count[index][0] = count[index + 1][0];
                count[index][1] = count[index + 1][1];
                count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
            }
        }

        // Return the result
        return count[0][0];
    }
};