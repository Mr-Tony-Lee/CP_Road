#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    string empty;
    getline(cin,empty); //三小爛系統，中間空一行，用cin.ignore會炸開，必須用getline
    map<string,int> ans ;
    while(times--){
        string input_string ;
        getline(cin, input_string);
        int index = 0 ; 
        for(int i = 0 ; i < (int)input_string.size() ; i++ ){
            if(input_string[i] == ' ') {
                index = i ; 
                break;
            }
        }
        string inside_country = input_string.substr(0,index);
        ans[inside_country]++;
    }
    for(auto it:ans ){
        cout << it.first << " " << it.second << endl;
    }
}
//10ms, 468KB