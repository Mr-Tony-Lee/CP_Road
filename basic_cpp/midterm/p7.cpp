#include<iostream>
using namespace std;

int main(){
    int meal_price;
    bool is_rain , is_vip;
    cin >> meal_price >> is_rain >> is_vip ;

    int fee = 0 ;
    if(meal_price < 200 ){
        fee += 100;
    }
    else if ( meal_price < 500 ){
        fee += 50 ;
    }
    else{
        fee += 20 ;
    }
    if(is_rain){
        fee += 20 ;
    }
    if(is_vip){
        fee /= 2 ;
    }
    
    if(fee < 15 ){
        fee = 15 ;
    }
    cout << fee << endl;
}