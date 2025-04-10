#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(0);
    int S ;
    while(cin >> S && S ){
        vector<vector<int>> arr ; 
        vector<int> ans ; 
        int N , n;
        cin >> N ; 
        for(int i = 0 ; i < N  ; i++ ){
            int dp[2000] = {};
            cin >> n ;
            vector<int> this_vec ;
            for(int j = 0 ; j < n ; j++ ){
                int d ; 
                cin >> d ;
                this_vec.push_back(d);
                dp[d] = 1 ;
            }
            arr.push_back(this_vec);
            int now = 1 ; 
            while(now < 2000){
                if( dp[now] == 1 ){
                    now++;
                    continue;
                } 
                int sum = S + 1 ;
                for(int k = 0 ; k < (int)this_vec.size() ; k++ ){
                    if(this_vec[k] <= now ){
                        sum = min((dp[this_vec[k]] + dp[now-this_vec[k]]),sum);
                    }
                    else{
                        break;
                    }
                }
                if( sum > S ) break;
                dp[now] = sum;
                now++;
            }
            ans.push_back(now-1);
        }
        int idx = 0 , maxx = -1 , max_d = -1 ; 
        for(int i = 0 ; i < (int)ans.size() ; i++ ){
            if(ans[i] == maxx){
                if(arr[i].size() < arr[idx].size() ||  arr[i][arr[i].size()-1] < max_d ){
                    idx = i ;
                    maxx = ans[i];
                    max_d = arr[i][arr[i].size()-1] ;
                } 
            }
            else if(ans[i] > maxx ){
                idx = i ;
                maxx = ans[i];
                max_d = arr[i][arr[i].size()-1] ;
            }
        }
        cout << "max coverage =" << setw(4) << maxx << " :";
        for(int i = 0 ; i < (int)arr[idx].size() ; i++ ){
            cout << setw(3) << arr[idx][i] ; 
        }
        cout << endl;
    }
}

/*
    解題說明 : 
        使用 dp 去算出每一種的方法數，如果使用郵票的數量超過 S 就跳出，那dp的過程就是把數字拆成更小的組合，
        假如現在是 11 ， 拆成 4 + 7 ， 7 也可以拆成 4 + 3 ， 3可以拆成 1 + 2 ， 2可以拆成 1+1，
        這樣11 就是 4 + 4 + 1 + 1 + 1 ，這樣用5張，那當超過S 就停住，最後輸出 maximum。
*/