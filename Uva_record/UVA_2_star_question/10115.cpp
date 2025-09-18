#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n , n ){
        cin.ignore();
        vector<pair<string,string>> cmp;
        for(int i = 0 ; i < n ; i++ ){
            string a , b ; 
            getline(cin,a);
            getline(cin,b);
            cmp.push_back(make_pair(a,b));
        }
        string input;
        getline(cin, input);
        for(int i = 0; i < cmp.size(); i++ ){
            int index = 0 ;
            while(index != input.size()){
                if(input.substr(index,cmp[i].first.size()) == cmp[i].first){
                    input.replace(index,cmp[i].first.size(),cmp[i].second);
                    index = 0 ; 
                    continue;
                }
                index++;
            }
        }
        cout << input << endl;
    
    }
}