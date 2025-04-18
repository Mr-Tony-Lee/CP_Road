#include<iostream>
#include<cmath>
using namespace std;
using ll = long long ;
void hanoi(int i , int m , int d , int number ){
    if(number == 1){    //當搬動一個的時候，就印出來
        cout << i << " " << d << endl;
        return ;
    }
    hanoi(i, d, m, number-1);
    hanoi(i, m, d, 1);
    hanoi(m, i, d, number-1);
}
ll power_2[17] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    cout << power_2[n]-1 << endl;
    hanoi(1,2,3,n);
}