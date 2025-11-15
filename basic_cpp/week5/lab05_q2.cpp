#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    double distance ;
    cin >> distance ;
    double ans = 70 ;
    if(distance > 1.5 ) ans += (distance-1.5)*50;
    if(distance > 20 ) ans *= 1.1;
    cout << ans << endl;
}