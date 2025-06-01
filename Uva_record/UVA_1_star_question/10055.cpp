#include<iostream>
using namespace std;

int main(){
    long long int number1 , number2 ;
    while(cin >> number1 >> number2){
        cout << abs(number1-number2) << endl;
    }
}
//5ms, 332KB

// 解題報告: 根據題意，輸出兩數相減的絕對值