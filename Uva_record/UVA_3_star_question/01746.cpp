#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);  cout.tie(0) ;  ios::sync_with_stdio(0);
    int n  ;
    while(cin >> n ){
        vector<int> arr(n,0) ;
        for(int i = 0 ; i < n ; i++ ){
            cin >> arr[i] ;
        }
        for(int i = min(arr[0],arr[n-1]) ; i >= 0 ; i--){
            int left = 0 ; 
            int right = n-1 ;
            int temp = i ; 
            vector<int> copy = arr ; 
            while(left < n && right >= 0 && copy[left] >= temp && copy[right] >= temp ){
                copy[right] -= temp ;
                copy[left] -= temp;
                if(copy[right] == 0 ) right--;
                if(copy[left] == 0 ) left++;
                temp--;
                if(temp == 0 ){
                    int sum = 0 ; 
                    for(auto& num:copy){
                        sum += num ; 
                    }
                    // 當 i 不等於 1 的時候，剩下的括號要是偶數( 可以都用 1 個 解決) 
                    // 或當 i 是 1 的時候，剩下的數量是 0 
                    if( (!(sum & 1 ) && i != 1) || (sum == 0 && i == 1) ) cout << i << endl;
                    else cout << "no quotation" << endl;
                    goto end ; 
                }
            }
        }
        end:;
    }
}
// 參考資料 : https://www.pinghenotes.com/UVa-1746-String-Theory/