#include<bits/stdc++.h>
using namespace std;
const int maxN = 50000;
int prime[maxN];
vector<int> all_prime;
void reset(){
    all_prime.clear();
    memset(prime,true, sizeof(prime));
    all_prime.push_back(2);
    prime[1] = prime[0] = false;
    for(int i = 3 ; i < maxN ; i += 2 ){
        if(prime[i]){
            all_prime.push_back(i);
            for(int j = 2*i ; j < maxN ; j += i ){
                prime[j] = false;
            }
        }
    }
}
bool isprime( int n ){
    if( n != 2 && n % 2 == 0 ) return false;
    if( n < maxN )  return prime[n];
    for(auto iter = all_prime.begin() ; iter != all_prime.end() && *iter < n ; iter++){
        if(n % *(iter) == 0 ) return false;
    }
    return true;
}


int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int a , b ;
    reset();
    while(cin >> a >> b ){
        vector<int> range_prime;
        for(long long i = a ; i <= b ; i++ ){
            if(isprime(i)) range_prime.push_back(i);
        }
        pair<int,int> closet , distant;
        int low = 1000001 , high = 0 ;
        for(auto iter = lower_bound(range_prime.begin(),range_prime.end(),a) ; iter != range_prime.end() ; iter++ ){
            if( (iter+1) == range_prime.end() ) break;
            if( *(iter+1) > b ){
                break;
            }
            int dis = *(iter+1) - *(iter) ;
            if(dis < low ){
                closet = {*(iter),*(iter+1)};
                low = dis;
            }
            if(dis > high ){
                distant = {*(iter),*(iter+1)};
                high = dis;
            }
        }
        if(low == 1000001 && high == 0 ){
            cout << "There are no adjacent primes." << endl;
        }
        else{
            cout << closet.first << "," << closet.second << " are closest, " << distant.first << "," << distant.second << " are most distant." << endl;
        }
    }
    return 0 ; 
}