#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
using ll = long long ;

string trans(ll number ){
    string ans = "";
    while( number > 0 ){
        ans += (number % 2) + '0';
        number /= 2 ;
    }
    reverse(ans.begin() , ans.end());
    return ans ;
}

int main(){
    int times ;
    cin >> times;
    int count = 1 ;
    while(times--){
        ll input; 
        cin >> input ;
        if(input == 0 ){
            cout << "Case #" << count++ << ": " << 0 << endl;
            continue;
        }
        int array[50] = {0};
        int ans[100] = {0};
        ll abs_input = abs(input);
        int now = 0 ;
        while(abs_input){
            array[now] = abs_input % 2 ;
            abs_input /= 2 ;
            now++;
        }
        if(input < 0 ){
            for(int i = 0 ; i < now ; i++ ){
                if( i % 2 == 0 && array[i] == 1 ){   //需要組出來的
                    ans[i+1] ++ ;
                    ans[i] ++ ; 
                }
                else if (array[i] == 1 ) {
                    ans[i] ++ ;
                }
            }
        }
        else{
            for(int i = 0 ; i < now ; i++ ){
                if( i % 2 == 1 && array[i] == 1 ){   //需要組出來的
                    ans[i+1] ++ ; 
                    ans[i] ++ ; 
                }
                else if (array[i] == 1 ) {
                    ans[i]++;
                }
            }
        }
        for(int i = 0 ; i < 100 ; i++ ){
            if(ans[i] >= 2 ){
                ans[i+2] += ans[i] / 2 ;
                ans[i+1] += ans[i] / 2 ;
                ans[i] %= 2;
            }
        }
        cout << "Case #" << count++ << ": " ;
        bool flag = false;
        for(int i = 99 ; i >= 0 ; i--){
            if(ans[i] == 1 ){
                flag = true;
            }
            if(flag){
                cout << ans[i];
            }
        }
        cout << endl;
    }
}
// Accepted online judge