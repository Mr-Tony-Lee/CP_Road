#include<iostream>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    int count = 1 ;
    while(times--){
        int a , b ;
        cin >> a >> b ;
        unsigned long long int sum = 0 ;
        for(int i = a ; i <= b ; i++){
            if(i % 2 == 1 ){
                sum += i;
            }
        }
        cout << "Case " << count++ << ": "<< sum << endl;
    }
}
//2ms, 300KB