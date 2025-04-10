#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main(){
    double s , a;
    double r = 6440;
    string  input ; 
    while(cin >> s >> a >> input ){
        double degree ;
        if(input == "min"){
            degree = (double)(a/60) ; //magic 1度是60分鐘
            
        }
        else{
            degree = a ;
        }
        if( degree > 180.0 ) degree = 360.0 - degree;   //要注意超過180 cos會是負數 所以必須要倒回來
        double distance = r + s ;
        double chord = sqrt(2*distance*distance-2*distance*distance*cos(degree*M_PI/180));
        double arc = 2*distance*(M_PI)*(degree/360);
        cout << fixed << setprecision(6) << arc << " "<< chord << endl;
    }
}