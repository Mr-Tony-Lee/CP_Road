#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double a , b , c ;
    cin >> a >> b >> c ;
    double s = (a + b + c) / 2 ;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    double longest_height = 2 * area / max(a , max(b , c));
    cout << "The height of the longest side: " <<  longest_height << endl;
    return 0 ;
}