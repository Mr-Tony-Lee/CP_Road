#include<iostream>
#include<string>
#include<map>
using namespace std;

int matrix[16][10] = {
    {0,1,1,1,0,0,1,1,1,1},  //c
    {0,1,1,1,0,0,1,1,1,0},  //d
    {0,1,1,1,0,0,1,1,0,0},  //e
    {0,1,1,1,0,0,1,0,0,0},  //f
    {0,1,1,1,0,0,0,0,0,0},  //g
    {0,1,1,0,0,0,0,0,0,0},  //a
    {0,1,0,0,0,0,0,0,0,0},  //b
    {0,0,1,0,0,0,0,0,0,0},  //C
    {1,1,1,1,0,0,1,1,1,0},  //D
    {1,1,1,1,0,0,1,1,0,0},  //E
    {1,1,1,1,0,0,1,0,0,0},  //F
    {1,1,1,1,0,0,0,0,0,0},  //G
    {1,1,1,0,0,0,0,0,0,0},  //A
    {1,1,0,0,0,0,0,0,0,0},  //B
};

int main(){
    int times ;
    cin >> times ;
    cin.ignore();
    while(times--){
        int finger[10] = {0};
        string input ;
        getline(cin,input);
        int active[10] = {0};
        map<char,int> sing ; 
        sing['c'] = 0;
        sing['d'] = 1;
        sing['e'] = 2;
        sing['f'] = 3;
        sing['g'] = 4;
        sing['a'] = 5;
        sing['b'] = 6;
        sing['C'] = 7;
        sing['D'] = 8;
        sing['E'] = 9;
        sing['F'] = 10;
        sing['G'] = 11;
        sing['A'] = 12;
        sing['B'] = 13;
        for(int i = 0 ; i < (int)input.size() ; i++){
            for(int j = 0 ; j < 10 ; j++ ){
                if(matrix[sing[input[i]]][j] == 1 && active[j] == 0 ){
                    finger[j]++; 
                }
                active[j] = matrix[sing[input[i]]][j] ;
            }
        }
        for(int i = 0 ; i < 10 ; i++ ){
            cout << finger[i] << " " ;
        }
        cout << endl;
    }
}
//8ms, 316KB