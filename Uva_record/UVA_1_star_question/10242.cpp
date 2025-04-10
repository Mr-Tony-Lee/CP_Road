#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ; 
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 ){
        double x , y ;
        if(x1 == x3 && y1 == y3 ){
            x = x4 + (x2-x1);
            y = y4 + (y2-y1);
        }
        else if(x1 == x4 && y1 == y4 ){
            x = x3 + (x2-x1);
            y = y3 + (y2-y1);
        }
        else if (x2 == x3 && y2 == y3 ){
            x = x1 + (x4-x3);
            y = y1 + (y4-y3);
        }
        else if ( x2 == x4 && y2 == y4){
            x = x1 + (x3-x4);
            y = y1 + (y3-y4);
        }
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }
}
//2ms, 304KB