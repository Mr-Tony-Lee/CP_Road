#include<iostream>
using namespace std;

int solve(unsigned long long int number){
    int ans = 0 ; 
    while(number > 0 ){
        ans += number % 10;
        number /= 10 ;
    }
    if(ans >= 10 ){
        return solve(ans);
    }
    else{
        return ans ;
    }
    
}
int main(){
    unsigned long long int n;
    while(cin >> n ){
        if(n == 0 ){
            break;
        }
        cout << solve(n) << endl;
    }
}
//32ms, 320KB