#include<iostream>
using namespace std;

int main(){
    string input[100] ; 
    int count = 0 ;
    int largest_length = 0 ; 
    while(getline(cin,input[count++])){
        largest_length = max((int)input[count-1].size() , largest_length);
    }
    for(int i = 0; i < largest_length ; i++ ){
        for(int j = count-2 ; j >= 0 ; j--  ){
            
            if( (int)input[j].size() <= i  ){
                cout << ' ' ;
            }
            else{
                cout << input[j][i] ;
            }
        }
        cout << endl;
    }
}
//3ms, 340KB