#include<iostream>
using namespace std;

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    else if(a == 0){
        return b;
    }
    else{
        if( a > b ){
            return GCD( a % b , b);
        }
        else if(b > a){
            return GCD(a ,b % a);
        }
        else{
            return a;  //a、b相等
        }
    }
}
int main(){
    int N;
    while(cin >> N ){
        if(N == 0 ){
            break;
        }
        int G = 0;
        for(int i = 1; i < N ; i++){
            for(int j = i + 1 ; j <= N ; j++){
                G+=GCD(i,j);
            }
        }
        cout << G << endl;
    }
}
//0.2s, 324KB