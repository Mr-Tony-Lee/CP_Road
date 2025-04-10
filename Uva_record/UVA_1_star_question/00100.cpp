#include<iostream>
using namespace std;

int solve(int n){
    int sum = 1 ;
    while(n != 1 ){
        if(n % 2 == 1 ){
            n = 3*n+1;
        }
        else{
            n = n/2;
        }
        sum++;
    }
    return sum ;
}

int main(){
    int number1 , number2 ; 
    while(cin >> number1 >> number2 ){
        int ans = 0 ; 
        if( number1 > number2 ){
            swap(number1 , number2) ; 
            for(int i = number1 ; i <= number2 ; i++ ){
                int every_ans = solve(i);
                ans = max(ans,every_ans);
            }
            cout << number2 << " " << number1 << " " << ans << endl;    
            continue;
        }
        for(int i = number1 ; i <= number2 ; i++ ){
            int every_ans = solve(i);
            ans = max(ans,every_ans);
        }
        cout << number1 << " " << number2 << " " << ans << endl;
    }
}
//16ms, 316KB