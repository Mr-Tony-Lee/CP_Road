#include<iostream>
using namespace std;

int main(){
    int times;
    cin >> times;
    while(times--){
        long long int M , N ;
        cin >> N >> M ;
        if(M == N-1){
            cout << N-1 << endl;
            continue;
        }
        int count = 1 ; 
        while((N-count)*((N-count)-1) >= 2*(M-count)){
            count++;
        }
        cout << count-1 << endl;
    }
}
//Accepted online judge 