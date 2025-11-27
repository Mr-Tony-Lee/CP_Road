#include<bits/stdc++.h>
using namespace std;

int main(){
    int N , num_track ;
    while(cin >> N >> num_track ){
        vector<int> arr;
        vector<int> ori;
        arr.push_back(0);
        for(int i = 0 ; i < num_track ; ++i ){
            int min;
            cin >> min ;
            arr.push_back(min);
        }
        ori = arr;
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(num_track+1,vector<int>(N+1,0));
        vector<vector<set<int>>> record(num_track+1,vector<set<int>>(N+1));
        for(int i = 1 ; i <= num_track ; i++){
            for(int j = 0 ; j <= N ; j++ ){
                if ( j >= arr[i]){
                    if(dp[i-1][j-arr[i]]+arr[i] > dp[i-1][j]){
                        dp[i][j] = dp[i-1][j-arr[i]]+arr[i];
                        record[i][j] = record[i-1][j-arr[i]];
                        record[i][j].insert(arr[i]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                        record[i][j] = record[i-1][j];
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    record[i][j] = record[i-1][j];
                }
            }
        }
        
        for(int i = 1 ; i <= num_track ; i++ ){
            if(record[num_track][N].count(ori[i])){
                cout << ori[i] << " ";
            }
        }
        cout << "sum:" << dp[num_track][N] << endl;
    }
    
}
// 5 3 1 3 4
// 10 4 9 8 4 2 
// Accepted
