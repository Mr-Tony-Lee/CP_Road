#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int number;
    while(cin >> number){
        map<string, int> dice ;
        dice["top"] = 1;
        dice["north"] = 2;
        dice["west"] = 3 ;
        dice["east"] = 4; 
        dice["south"] = 5;
        dice["bottom"] = 6 ;
        cin.ignore();   
        if(number == 0 ){
            break;
        }
        string input ;
        while(number--){
            getline(cin,input);
            if(input[0] == 'n'){
                int temp = dice["top"];
                dice["top"] = dice["south"];
                dice["south"] = dice["bottom"];
                dice["bottom"] = dice["north"];
                dice["north"] = temp;
            }
            else if (input[0] == 's'){
                int temp = dice["top"];
                dice["top"] = dice["north"];
                dice["north"] = dice["bottom"];
                dice["bottom"] = dice["south"];
                dice["south"] = temp;
            }
            else if (input[0] == 'e'){
                int temp = dice["top"];
                dice["top"] = dice["west"];
                dice["west"] = dice["bottom"];
                dice["bottom"] = dice["east"];
                dice["east"] = temp;
            }
            else{
                int temp = dice["top"];
                dice["top"] = dice["east"];
                dice["east"] = dice["bottom"];
                dice["bottom"] = dice["west"];
                dice["west"] = temp;
            }
        }
        cout << dice["top"] << endl;
    }   
}
//3ms, 324KB