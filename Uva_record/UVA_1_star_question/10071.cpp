#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double v , t;
    while(cin >> v >> t ){
        if(t == 0){
            cout << 0 << endl;
            continue;
        }
        double a = v/t ; 
        double v0 = v-a*t;
        cout << v0 * 2 * t + 0.5 * a * pow(2*t,2) << endl;
    }
}
//7ms, 320KB