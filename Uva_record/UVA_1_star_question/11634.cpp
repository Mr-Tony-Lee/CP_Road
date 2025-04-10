#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long solve(long long a0 ){
    long long pow = a0*a0 ; 
    vector<int> number ;
    while( pow != 0 ){
        number.push_back(pow%10);
        pow /= 10 ;
    }
    while((int)number.size() != 8 ){
        number.push_back(0);
    }
    long long ans = 0 ; 
    for(int i = 5 ; i >= 2 ; i-- ){
        ans = ans*10 + number[i];
    }
    return ans ;
}

int main(){
    long long a0;
    while(cin >> a0 && a0 ){
        int ans = 1; 
        long long an = solve(a0) ;
        vector<long long > all ;
        all.push_back(a0);
        while( find(all.begin() , all.end() , an ) == all.end()){
            all.push_back(an);
            an = solve(an);
            ans++;
        }
        cout << ans << endl;
    }
}