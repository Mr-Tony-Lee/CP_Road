#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a , b ;
    while(cin >> a >> b ){
        if(a == 0 && b == 0 ){
            break;
        }
        int count = 0 ; 
        for(int i = a ; i <= b ; i++ ){
            double every_sqrt = sqrt(i);
            if(every_sqrt == (int)every_sqrt){
                count++ ;
            }
        }
        cout << count << endl;
    }
}
//35ms, 316KB