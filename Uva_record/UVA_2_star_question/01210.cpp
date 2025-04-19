#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> prime;
    vector<bool> table(10000,false);
    prime.insert(2);
    for(int i = 3 ; i <= 10000 ; i += 2){
        if(!table[i]){
            prime.insert(i);
            for(int j = 2*i ; j <= 10000 ; j += i ){
                table[j] = true;
            }
        }
    }
    int N ;
    while(cin >> N , N ){
        int ans = 0 ;
        int now = 0 ;
        int first = 0 ;
        if(N == 2 ){
            cout << 1 << endl;
            continue;
        } 
        for(auto& num:prime){
            if(num > N ) break;
            now += num ;
            if(now == N ){
                ans++;
            }
            while(now >= N ){
                now -= first;
                first = *(prime.upper_bound(first));
                if(now == N ){
                    ans ++ ;
                }
            }
            if(first == 0 ){
                first = num ; 
            }
            
        }
        cout << ans << endl;
    }
}