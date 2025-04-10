#include<iostream>
#include<cmath>
using namespace std;


int main(){
    while(1){
        double H , U , D , F ;
        cin >> H >> U >> D >> F ;
        if( H == 0 ) break;
        // H 是牆的高度
        // U 是第一天爬上去的距離
        // D 是滑下來的距離(晚上)
        // F 是疲勞參數
        int d = 1; 
        double now = U ; 
        bool end = false ;
        while(1){
            if(now > H ) {
                end = true;
                break;
            }
            now -= D ; 
            if(now < 0 ){
                break;
            }
            d++;
            double add = U - ((d-1) * U * F * 0.01);
            if(add > 0 ) now +=  add ;
            
        }
        if(end) {
            cout << "success on day " << d << endl; 
        }
        else{
            cout << "failure on day " << d << endl;
        }
    }
}
//Online judge Accepted