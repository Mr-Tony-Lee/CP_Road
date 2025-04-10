#include<iostream>
#include<string>
using namespace std;

int main(){
    string input ;
    int count = 0 ; 
    while(getline(cin , input)){
        string output = "";
        for(int i = 0; i < (int)input.size() ; i++ ){
            if(input[i] == '"'){
                count++;
                if(count % 2 == 0){
                    output.push_back('\'');
                    output.push_back('\'');
                }
                else{
                    output.push_back('`');
                    output.push_back('`');
                }
            }
            else{
                output.push_back(input[i]);
            }
        }
        cout << output << endl;
    }
}
//7ms, 312KB