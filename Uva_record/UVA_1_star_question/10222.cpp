#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string origin = "ertyuiop[]\\dfghjkl;\'cvbnm,./234567890-=";
    string after =  "qwertyuiop[asdfghjklzxcvbnm,`1234567890";
    string input ;
    while(getline(cin,input)){
        string output ;
        for(int i = 0 ; i < (int)input.size(); i++){
            for(int j = 0 ; j < (int)origin.size(); j++ ){
                if(input[i] == origin[j]){
                    output.push_back(after[j]);
                }
            }
            if(input[i] == ' '){
                output.push_back(' ');
            }
        }
        cout << output << endl;
    }   
}
//2ms, 312KB