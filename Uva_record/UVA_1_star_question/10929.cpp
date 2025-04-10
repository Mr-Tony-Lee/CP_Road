#include<iostream>
#include<string>
using namespace std;

int main(){
    while(1){
        string input ;
        cin >> input;
        if(input == "0"){
            break;
        }
        int a = 0  , b = 0 ; // a 奇數項， b 偶數項
        for(int i = 0; i < input.size(); i++ ){
            if(i % 2 == 0 ){
                a += (int)input[i] - (int)'0';
            }
            else{
                b += (int)input[i] - (int)'0';
            }
        }
        if(abs(a-b) % 11 == 0 ){
            cout << input << " is a multiple of 11." << endl;
        }
        else{
            cout << input << " is not a multiple of 11." << endl;
        }   
    }
}
//6ms, 308KB