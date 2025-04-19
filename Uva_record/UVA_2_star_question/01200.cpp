#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t;
    cin.ignore();
    while(t--){
        string input ;
        getline(cin,input);
        int x_coe = 0 , value = 0;
        bool rightside = false;
        int n = 0 ; 
        bool neg = false;
        
        for(int i = 0 ; i < (int)input.size() ; i++ ){
            if( input[i] >= '0' && input[i] <= '9'){
                n = n*10 + input[i]-'0';
            }
            else if ( input[i] == 'x'){
                if(input[i-1] != '0' && n == 0){
                    n = 1;
                }
                if( neg ) n *= -1;
                if(rightside){
                    x_coe -= n;
                }
                else{
                    x_coe += n ; 
                }
                n = 0 ;
                continue;
            }
            else{
                if(neg) n *= -1 ;
                if(!rightside){
                    value -= n ;
                }
                else{
                    value += n ;
                }
                n = 0 ;
            }
            if(input[i] == '='){
                rightside = true;
                neg = false;
                continue;
            }
            if (input[i] == '-'){
                neg = true;
            }       
            if (input[i] == '+'){
                neg = false;
            }
        }
        if(input[(int)input.size()-1] != 'x'){
            if(neg) n *= -1 ;
            if(!rightside){
                value -= n ;
            }
            else{
                value += n ;
            }   
        }
        if(x_coe == 0){
            if( value == 0 ){
                cout << "IDENTITY" << endl;
            }
            else {
                cout << "IMPOSSIBLE" << endl;
            }
        }
        else {
            double ans = 1.0*value / x_coe;
            if(ans >= 0 ){
                cout << (int)ans << endl;
            }
            else{
                if(ans == (int)ans ){
                    cout << (int) ans << endl;
                }
                else{
                    cout << (int)ans-1 << endl;
                }
            }
        }
    }
}
/*
2
2x-4+5x+300=98x
x+2=2+x
*/