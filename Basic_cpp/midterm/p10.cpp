#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    int k;
    cin >> k;
    int g ;
    string ans = "";
    int maxG = 0 ;
    while(cin >> g , g ){
        cin.ignore();
        string input ;
        getline(cin,input);
        if(g > maxG && (g % k == 0) ){
            maxG = g ;
            ans = input;
        }
    }
    if(maxG == 0 ){
        cout << "None" << endl;
    }
    else{
        cout << ans << endl;
    }
}