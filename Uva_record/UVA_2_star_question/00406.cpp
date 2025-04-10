#include<iostream>
#include<cmath>
using namespace std;
int prime[1000];
int prime_sum[1001];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N , C ; 
    int count = 2;
    prime[0] = 1 ;
    prime[1] = 2 ; 
    prime_sum[1] = 1;
    prime_sum[2] = 2 ;
    for(int i = 3 ; i <= 1000 ; i++ ){
        bool flag = false;
        for(int j = 2 ; j <= sqrt(i) ; j++ ){
            if(i % j == 0 ){
                flag = true;
                break;
            }
        }
        if(!flag) {
            prime[count++] = i ;
            prime_sum[i] = prime_sum[i-1]+1;
        }
        else{
            prime_sum[i] = prime_sum[i-1];
        }
    }
    int times = 0 ;
    while(cin >> N >> C ){
        if(times != 0 ) cout << endl;
        times++;
        cout << N << " " << C << ": " ;
        if(prime_sum[N] & 1 ){
            if(2*C-1 < prime_sum[N]){
                int middle = prime_sum[N]/2;
                for(int i = middle-C+1 ; i <= middle+C-1 ; i++ ){
                    cout << prime[i] << " ";
                }
                cout << endl;
                continue;
            }
            else{
                for(int i = 0 ; i < prime_sum[N] ; i++ ){
                    cout << prime[i] << " ";
                }
                cout << endl;
                continue;
            }
        }
        else{
            if(2*C >= prime_sum[N]){
                for(int i = 0 ; i < prime_sum[N] ; i++ ){
                    cout << prime[i] << " ";
                }
                cout << endl;
                continue;
            }
            else{
                int middle = prime_sum[N]/2;
                for(int i = middle-C ; i <= middle+C-1 ; i++ ){
                    cout << prime[i] << " ";
                }
                cout << endl;
                continue;
            }
        }
    }
}