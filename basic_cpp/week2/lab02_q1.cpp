#include<iostream>
using namespace std;

int main(){
    double u = 12.3 ; 
    double a = 4.7;
    int t = 7;
    cout << "Initial Velocity: " << u << endl;
    cout << "Acceleration: " << a << endl;
    cout << "Time: " << t << endl;
    cout << "Displacement: " << u*t+0.5*a*t*t << endl;
    return 0 ; 
}