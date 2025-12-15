#include<bits/stdc++.h>
using namespace std;

int main(){
    char names[50][31];
    int N , M ;
    cin >> N >> M ;
    cin.ignore();
    for(int i = 0 ; i < N ; i++ ){
        memset(names[i],'\0',31);
        string name;
        cin >> name ;
        for(int j = 0 ; j < name.size() && j < M ; j++ ){
            names[i][j] = tolower(name[j]);
        }
    }
    string keyword;
    cin >> keyword;
    char key[31];
    memset(key,'\0',31);
    for(int i = 0 ; i < keyword.size() ; i++ ){
        key[i] = tolower(keyword[i]);
    }
    bool find = false;
    for(int i = 0 ; i < N ; i++ ){
        if(strstr(names[i],key) != nullptr){
            cout << i << endl;
            find = true;
            break;
        }
    }
    if(!find) cout << -1 << endl;
    
     
}