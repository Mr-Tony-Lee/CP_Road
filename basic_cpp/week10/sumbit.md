第一題:

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


第二題:

#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<utility>
using namespace std;

bool cmp(pair<int,char> a , pair<int,char> b ){
    if(a.first != b.first){
        return a.first > b.first ;
    }
    else{
        return a.second < b.second ;
    }
}

int main(){
    ifstream in;
    in.open("10_2.txt");
    string input;
    vector<int> count_map(26,0);
    vector<pair<int,char>> ans ;

    while(getline(in,input)){
        for(int i = 0 ; i < input.size(); i++ ){
            if(isalpha(input[i])){
                count_map[toupper(input[i])-'A']++;
            }
        }
    }
    for(int i = 0 ; i < 26 ; i++ ){
        ans.push_back({count_map[i], i+'A'});
    }
    sort(ans.begin(), ans.end() , cmp );
    for(int i = 0 ; i < 5 ; i++ ){
        cout << "Top " << i+1 << ": " << ans[i].second << "(" << ans[i].first << ")" << endl;
    }
    
}