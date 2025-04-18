#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string input ;
    cin >> input ;
    int ascii[26] = {0};
    for(int i = 0 ; i < (int)input.size() ; i++ ){
        ascii[input[i]-'A']++;
    }
    int single = 0 ;
    char sing ;
    for(int i = 0 ; i < 26 ; i++ ){
        if(ascii[i] & 1 ) {
            single++;
            sing = i+'A';
        }
    }
    if(single > 1 ){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    for(int i = 0 ; i < 26 ; i++ ){
        if(ascii[i] % 2 == 0 && ascii[i]){
            for(int j = 0 ; j < ascii[i]/2 ; j++ ){
                char out = i+'A';
                cout << out ;
            }
        }
    }
    if(single) {
        for(int i = 0 ; i < ascii[sing-'A'] ; i++ ){
            cout << sing;
        }
    }
    for(int i = 25 ; i >= 0 ; i-- ){
        if(ascii[i] % 2 == 0 && ascii[i]){
            for(int j = 0 ; j < ascii[i]/2 ; j++ ){
                char out = i+'A';
                cout << out ;
            }
        }
    }
    cout << endl;
}