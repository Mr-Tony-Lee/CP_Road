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
