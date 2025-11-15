#include<iostream>
using namespace std;

int main(){
    int ax1 , ay1 , ax2 , ay2 , bx1 , by1 , bx2 , by2 ;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2 ;

    int ansX = ax2 - bx1 ; 
    int ansY = by2 - ay1 ; 

    cout << ansX * ansY << endl;
}