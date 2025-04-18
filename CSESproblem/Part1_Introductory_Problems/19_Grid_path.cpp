#include<iostream>
#include<vector>
using namespace std;
using ll = long long ;

int n_x[5] = {-1 , 0 , 1 , 0 };
int n_y[5] = {0 , 1 , 0 , -1 };
const int n = 7 ; 
bool map[n+2][n+2] ;

vector<int> order ;

int travel_map(int now_step , int now_i , int now_j ){

    //優化， 如果可以向左也可向右走，但不能向上且向下走，意味著會把區域分兩邊，那必定會無解
    if((map[now_i][now_j+1] && map[now_i][now_j-1]) && (!map[now_i-1][now_j] && !map[now_i+1][now_j])){
        return 0;
    }
    //優化， 如果可以向上也可向下走，但不能向左且向右走，意味著會把區域分兩邊，那必定會無解
    if((!map[now_i][now_j+1] && !map[now_i][now_j-1]) && (map[now_i-1][now_j] && map[now_i+1][now_j])){
        return 0;
    }
    
    //如果走到目的地，那就判斷是不是最後一步
    if(now_i == 7 && now_j == 1 ){
        if(now_step == 48 ) return 1 ;
        return 0 ;
    }
    if(now_step == 48 ) return 0 ;
    
    int ans = 0 ;
    map[now_i][now_j] = true;
    if(order[now_step] <= 4 ){
        int next_i = now_i + n_x[order[now_step]-1];
        int next_j = now_j + n_y[order[now_step]-1];
        if(!map[next_i][next_j]) ans += travel_map(now_step+1 , next_i , next_j);
    }
    else{
        for(int i = 0 ; i < 4 ; i++ ){
            int next_i = now_i + n_x[i];
            int next_j = now_j + n_y[i];
            if(!map[next_i][next_j]) ans += travel_map(now_step+1 , next_i , next_j);
        }
    }
    map[now_i][now_j] = false;
    return ans ;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string input;
    cin >> input ;
    for(int i = 0 ; i < (int)input.size() ; i++ ){
        if(input[i] == 'L') order.push_back(4);
        else if (input[i] == 'R')   order.push_back(2);
        else if (input[i] == 'U')   order.push_back(1);
        else if (input[i] == 'D')   order.push_back(3);
        else order.push_back(5);
    }
    //將邊界向外擴一行，且設為true表示不能走
    for(int i = 0 ; i < n+2 ; i++ ){
        map[i][n+1] = true;
        map[i][0] = true;
        map[0][i] = true;
        map[n+1][i] = true;
    }
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= n ; j++ ){
            map[i][j] = false;
        }
    }
    //第0步開始，且都是從1 1 開始
    int start_i = 1 , start_j = 1 , now_step = 0 ;
    int ans = travel_map(now_step , start_i , start_j);
    cout << ans << endl;
}