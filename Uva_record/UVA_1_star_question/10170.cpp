#include<iostream>
using namespace std;

int main(){
    unsigned long long int initial ;
    unsigned long long int search;
    while(cin >> initial >> search ){
        unsigned long long int sum = initial;
        while(sum < search ){
            initial++;
            sum += initial;
        }
        cout << initial << endl;
    }
}
//64ms, 304KB