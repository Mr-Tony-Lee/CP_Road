#include<iostream>
using namespace std;

int main(){
    int number ;
    while( cin >> number ){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        int col[105][105] = {0};
        for(int i = 1 ; i <= number ; i++ ){
            for(int j = 1 ; j <= number ; j++ ){
                int x ;
                cin >> x ;
                col[i][j] = col[i-1][j] + x ;
            }
        }
        int ans = col[1][1];
        int sum;
        for(int i = 1 ; i <= number ; i++ ){
            for(int j = i ; j <= number ; j++ ){ 
                sum = 0 ;
                for(int k = 1 ; k <= number ; k++ ){
                    sum += col[j][k] - col[i-1][k];
                    if(sum < 0 ){
                        sum = 0 ;
                    }
                    ans = max(sum,ans);
                }
            }
        }
        cout << ans << endl;
    }
}