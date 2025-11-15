第一題:
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int main(){
    int a , b , c ;
    cin >> a >> b >> c ;
    if(a > b) swap(a , b);
    if(b > c) swap(b , c);
    if(a > b) swap(a , b);

    cout << a << " " << b << " " << c << endl;

    return 0 ; 
}


第二題:

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