#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    ifstream file;
    file.open("data.txt");
    int count = 1 ; 
    string input ;
    while(getline(file,input)){
        stringstream ss;
        ss << input;
        int num1 , num2 ;
        ss >> num1 ;
        ss >> num2 ;
        cout << "Line " << count++ << ": Sum=" << num1 + num2 << ", Diff=" << num1-num2 << ", Prod=" << num1*num2 << ", Quot=" << num1/num2 << endl;
    } 
}