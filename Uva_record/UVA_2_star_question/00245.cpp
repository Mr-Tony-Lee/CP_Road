#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string input ;
    vector<string> record;
    while(getline(cin,input)&& input != "0"){
        string word = "" ;
        int num = 0;
        input +="\n";
        for(int i = 0 ; i < (int)input.size() ; i++ ){
            if( ('A' <= input[i] && input[i] <= 'Z') || ('a' <= input[i] && input[i] <= 'z')){
                word += input[i];
            }
            else if ('0' <= input[i] && input[i] <= '9'){
                num *= 10;
                num += input[i] - '0';
            }
            else{
                if(num){
                    auto it = record.end()-num;
                    auto temp = *it;
                    cout << *it;
                    record.erase(it);
                    record.push_back(temp);    
                    num = 0 ;
                }
                else{
                    if(word != "" && find(record.begin() , record.end() , word) == record.end()){
                        record.push_back(word);
                    }
                }
                cout << word << input[i];
                word = "";
            }
        }
    }
}