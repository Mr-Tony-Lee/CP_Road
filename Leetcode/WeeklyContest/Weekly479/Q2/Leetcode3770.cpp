#include<bits/stdc++.h>
using namespace std;

// my version
class Solution {
public:
    vector<int> primes;
    void CreatePrimeTable(){
        vector<bool> check(100000,0);
        primes.push_back(2);
        for(int i = 3 ; i < 100000 ; i+=2 ){
            if(!check[i]){
                primes.push_back(i);
                for(int j = 2 * i ; j < 100000 ; j += i ){
                    check[j] = true;
                }
            }
        }
    }
    bool isPrime(int num ){
        if( num == 2 ) return true;
        if( num % 2 == 0 ) return false;
        for(auto& prime : primes ){
            if(prime * prime > num ){
                break;
            }
            if(num % prime == 0 ) return false;
        }
        return true;
    }
    int largestPrime(int n) {
        if(n == 1 ) return 0 ;
        CreatePrimeTable();
        int ans = 0 ; 
        long long  pref = 0 ; 
        for(auto prime:primes){
            pref += prime ;
            if(pref > n ){
               break;
            }
            if(isPrime(pref)){
                ans = pref ;
            }
            
        }
        return ans ;
    }
};


// optimized version
int primes[500001] = {};
set<int> st;

bool init = []() {
    int sum = 0;
    for (int i = 2; sum <= 500000; i++) {
        if (primes[i] == -1) continue;
        sum += i;
        primes[i] = sum;
        st.insert(sum);
        for (int j = 2 * i; j <= 500000; j += i) {
            primes[j] = -1;
        }
    }
    
    return true;
}();

class Solution {
public:
    int largestPrime(int n) {
        auto it = st.upper_bound(n);
        while (it != st.begin()) {
            it--;
            if (primes[*it] != -1) return *it;
        }
        return 0;
    }
};
