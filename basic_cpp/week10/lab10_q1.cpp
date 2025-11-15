#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
    ifstream in;
    in.open("10_1.csv");
    string input ;
    int sum = 0 ;
    while(getline(in, input)){
        int money = 0 ; 
        for(int i = 0 ; i < input.size() ; i++ ){
            if(input[i] == ','){
                money = stoi(input.substr(i+1,input.size()-i-1));
                break;
            }              
        }
        sum += money ;
    }
    cout << "Final Balance: " << sum << endl;
}