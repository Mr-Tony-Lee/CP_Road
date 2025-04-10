#include<iostream>
#include<map>
#include<cmath>
#include<iomanip>
using namespace std;
int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int ans[101][25] = {0};

void solve2(int N ){
    int i = 0 ; 
    int N_copy = N ; 
    while( prime[i] <= N ){
        if(N % prime[i] == 0 ){
            N /= prime[i] ;
            ans[N_copy][i] ++ ;
        }
        else{
            i++ ; 
        }
    }
    return;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ans[2][0] = 1;  
    for(int i = 3 ; i <= 100 ; i++ ){
        for(int j = 0 ; j < 25 ; j++ ){
            ans[i][j] += ans[i-1][j];
        }
        solve2(i);
    }
    int N ;
    while(cin >> N && N ){
        int count = 1 ; 
        cout << setw(3) << N ;
        cout << "! =" ;
        for(int i = 0 ; i < 25 ; i++ ){
            if(ans[N][i] > 0 ){
                if(count % 16 == 0 ){
                    cout << endl;
                    cout << "      ";
                }
                cout << setw(3) << ans[N][i] ;
                count++;
            }
        }
        cout << endl;
    }
}