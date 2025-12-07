#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prime;
    void CreatePrimeTable(){
        vector<bool> arr(10000,0);
        for(int i = 2; i < 10000 ; i++ ){
            if(!arr[i]){
                prime.push_back(i);
                for(int j = 2*i ; j < 10000 ; j += i ){
                    arr[j] = true;
                }
            }
        }
    }
    bool isPrime(int num){
        if(num < 2 ) return false;
        for(auto& primes: prime){
            if(primes*primes > num ){
                break;
            }
            if(num % primes == 0 ){
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        CreatePrimeTable();
        int i = 1 ;
        string snum = to_string(num);
        while(i <= snum.size()){
            string pref = snum.substr(0,i);
            string suff = snum.substr(i);
            int p = stoi(pref);
            
            if(!isPrime(p)){
                return false;
            }
            if(!suff.empty()){
                int s = stoi(suff);
                if(!isPrime(s)){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};

// optimized version
class Solution {
public:
    bool isPrime(int n) {
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        int y = 0, z = 1, x = num;
        while(x > 0) {
            y = z * (x % 10) + y;
            if(y == 1 || isPrime(y) == false) return false;
            if(x == 1 || isPrime(x) == false) return false;
            x /= 10; 
            z *= 10;
        }   
        return true;
    }
};