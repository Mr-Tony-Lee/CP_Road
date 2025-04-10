#include<iostream>
using namespace std;

int main(){
    int number ;
    while( cin >> number ){
        int empty = 0;
        int sum = number ;
        int number_copy = number ;
        while(number > 0 ){
            empty += number % 3 ;
            number = number/3;
            if(empty / 3 >= 1  ){
                number ++;
                empty -= 3;
            }
            sum += number ;
        }
        int sum_2 = number_copy;
        int empty_2 = 1 ;
        bool flag = false ;
        while(number_copy > 0 ){
            empty_2 += number_copy % 3;
            number_copy = number_copy / 3;
            while((empty_2 / 3) >= 1  ){
                number_copy ++;
                empty_2 -= 3;
            }
            if(number_copy == 1 ){
                flag = true;
            }
            sum_2 += number_copy ;  
        }
        if(flag){
            cout << max(sum_2,sum) << endl;    
        }
        else{
            cout << sum << endl;
        }
    }
}
//2ms, 304KB