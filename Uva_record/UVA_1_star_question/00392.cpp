#include<iostream>
using namespace std;

int main(){
    int a , b , c , d , e , f , g , h, i ;
    while( cin >> a >> b >> c >> d >> e >> f >> g >> h >> i ){
        int array[9] = {i , h , g , f , e , d , c , b, a };
        bool flag = false ;
        for(int i = 8 ; i >= 0 ; i-- ){
            if(array[i] != 0 ){
                if(array[i] > 0 && flag ){
                    cout << " + ";
                }
                else if ( array[i] < 0 && i != 8 && flag) {
                    cout << " - ";
                }
                else if ( array[i] < 0 && !flag){
                    cout << "-" ;
                }
                if(abs(array[i]) > 1 || (i == 0 && abs(array[i]) >= 1 )){
                    cout << abs(array[i]);
                }
                if(array[i] != 0 && i >= 1 ){
                    cout << "x" ;
                }
                if( i > 1 ){
                    cout << "^" << i ;
                }
                flag = true; 
            }
        }
        if(!flag){
            cout << 0 ;
        }
        cout << endl;
    }
}
//Accepted