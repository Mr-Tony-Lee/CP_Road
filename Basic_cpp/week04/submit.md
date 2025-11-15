第一題:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int main(){
    srand(time(0));
    int a , b ;
    cin >> a >> b ;
    if(a > b) swap(a , b);
    cout << rand() % (b - a) + a << endl;
    return 0 ; 
}

第二題:

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