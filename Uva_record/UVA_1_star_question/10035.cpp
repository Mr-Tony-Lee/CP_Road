#include<iostream>
#include<vector>
using namespace std;

int main(){
    while(1){
        long long int number1 , number2 ;
        cin >> number1 >> number2 ;
        if(number1 == number2 && number1 == 0 ){
            break;
        }
        int ans = 0 ;
        long long int carry = 0  ;
        while(number1 != 0 || number2 != 0 ){
            carry += number1 % 10 + number2 % 10 ;
            number1 /= 10 ;
            number2 /= 10 ;
            if(carry >= 10  ){
                carry = 1; 
                ans++ ;
            }
            else{
                carry = 0 ; 
            }
        }
        
        if(ans == 0 ){
            cout << "No carry operation." << endl;
        }
        else if (ans == 1 ){
            cout << "1 carry operation." << endl;
        }
        else{
            cout << ans << " carry operations." << endl;
        }
    }
    
}
//38ms, 312KB