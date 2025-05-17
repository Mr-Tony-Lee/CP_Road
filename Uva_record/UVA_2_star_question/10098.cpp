#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n ){
        cin.ignore();
        for(int i = 0 ; i < n ; i++ ){
            string input ;
            getline(cin,input);
            sort(input.begin(),input.end());
            do{
                cout << input << endl;
            }while(next_permutation(input.begin(),input.end()));
            cout << endl;
        }
    }
}