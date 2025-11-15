#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int type ;
    cin >> type ;
    int h, m , s ; 
    if(type == 1 ){
        cin >> s; 
        int aH, aM , aS ;
        aS = s % 60 ; 
        s /= 60 ; 
        aM = s % 60  ;
        s /= 60 ; 
        aH = s ;
        cout << setw(2) << setfill('0') << aH << ":" << setw(2) << setfill('0') << aM << ":" << setw(2) << setfill('0') << aS << endl;
    }
    else{
        cin >> h >> m >> s ;
        int totalS = h * 60*60 + m*60 + s ;
        cout << totalS << endl;
    }    
}