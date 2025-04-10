#include<bits/stdc++.h>
using namespace std; 
vector<vector<char>> table(12,(vector<char>(12,' ')));
void init(){
    for(int i = 0 ; i < 12 ; i ++ ){
        if(i == 0 || i == 11 ) {
            table[0][i] = '+';
            table[11][i] = '+';
        }
        else{
            table[0][i] = '-';
            table[11][i] = '-';
        }
    }
    for(int j = 1 ; j < 11 ; j++ ){
        table[j][0] = '|';
        table[j][11] = '|';
    }
}
void clear(){
    for(int i = 1 ; i < 11 ; i++ ){
        for(int j = 1 ; j < 11 ; j++ ){
            table[i][j] = ' ';
        }
    }
}
void print(){
    for(int i = 0 ; i < 12 ; i++ ){
        for(int j = 0 ; j < 12 ; j++ ){
            cout << table[i][j];
        }
        cout << endl;
    }
}
int main(){
    init();
    int n ;
    int kase = 0 ;
    while(cin >> n , n ){
        cin.ignore();
        clear();
        string input ;
        int cursor_x = 1 , cursor_y = 1 ; 
        bool insert_mode = false;
        bool overwrite_mode = true; 
        for(int j = 0 ; j < n ; j++ ){
            getline(cin,input);
            for(int i = 0 ; i < input.size() ; i++ ){
                if(input[i] == '^'){
                    i++;
                    if(isalpha(input[i])){
                        if(input[i] == 'b'){
                            cursor_y = 1 ; 
                        }
                        else if (input[i] == 'c'){
                            clear();
                        }
                        else if (input[i] == 'd'){
                            cursor_x = min(10,cursor_x+1);
                        }
                        else if (input[i] == 'e'){
                            for(int k = cursor_y ; k <= 10 ; k++ ){
                                table[cursor_x][k] = ' ';
                            }
                        }
                        else if (input[i] == 'h'){
                            cursor_x = 1 ;
                            cursor_y = 1 ;
                        }
                        else if (input[i] == 'i'){
                            insert_mode = true;
                            overwrite_mode = false;
                        }
                        else if (input[i] == 'l'){
                            cursor_y = max(1,cursor_y-1);
                        }
                        else if (input[i] == 'o'){
                            overwrite_mode = true;
                            insert_mode = false;
                        }
                        else if (input[i] == 'r'){
                            cursor_y = min(10,cursor_y+1);
                        }
                        else if (input[i] == 'u'){
                            cursor_x = max(1,cursor_x-1);
                        }
                    }
                    else if (input[i] == '^'){
                        if(overwrite_mode) {
                            table[cursor_x][cursor_y] = '^';
                        }
                        else if(insert_mode){
                            for(int k = 10 ; k > cursor_y ; k-- ){
                                table[cursor_x][k] = table[cursor_x][k-1];
                            }
                            table[cursor_x][cursor_y] = '^';
                        }
                        cursor_y = min(10,cursor_y+1);
                    }
                    else if ( input[i] >= '0' && input[i] <= '9' && input[i+1] >= '0' && input[i+1] <= '9' ){
                        cursor_x = input[i] -'0' + 1;
                        cursor_y = input[i+1] - '0' + 1;
                        i++;
                    }
                }
                else{
                    if(overwrite_mode) {
                        table[cursor_x][cursor_y] = input[i];
                    }
                    else if(insert_mode){
                        for(int k = 10 ; k > cursor_y ; k-- ){
                            table[cursor_x][k] = table[cursor_x][k-1];
                        }
                        table[cursor_x][cursor_y] = input[i];
                    }
                    cursor_y = min(10,cursor_y+1);
                }
            }
        }
        cout << "Case " << ++kase << endl;
        print();
    }
    
}
/*
7
This is bad^h^c
^05^^
^14/ \^d^b   /   \
^u^d^d^l^l^l^l^l^l^l^l^l
^r^r< ACM >^l^l^d/^b   \
^b^d    \ /
^d^l^lv

7
^i9^l8^l7^l6^l5^l4^l3^l2^l1^l0
^o^d^lThis is #1^d^bThis is #2
^d^bThis is #3^d^bThis is #4
^d^bThis is #5^d^bThis is #6
^d^bThis is #7^d^bThis is #8
^i^d^bThis is #9^d^bThis is #10
^54^e Hello^d^l^l^l^lWorld
*/