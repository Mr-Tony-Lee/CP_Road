#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string input ;
    string t ; 
    set<string> arr ;
    while(getline(cin,input)){
        for(int i = 0 ; i < input.size() ; i++ ){
            if(isalpha(input[i])){
                t.push_back(tolower(input[i]));
            }
            else{
                if(!t.empty()) arr.insert(t);
                t.clear();
            }
        }
        if(!t.empty()) arr.insert(t);
        t.clear();
    }
    for(auto& iter:arr){
        cout << iter << endl;
    }
}