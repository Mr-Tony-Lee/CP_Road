#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MAX 110
#define M   10100

void dp(vector<vector<bool>>& gar , vector<vector<int>>& num , vector<vector<bool>>& Visit , vector<int>& path , int i , int j , int row , int col ){
    if(Visit[i][j]) return ;
    Visit[i][j] = true ;

    if(gar[i][j]) num[i][j] ++ ; 
    
    int num_left = 0 , num_down = 0 ; 
    if( j <= col-1 ){
        dp(gar , num , Visit , path , i,j+1 , row , col );
        num_left = num[i][j+1]; 
    }
    if( i <= row-1){
        dp(gar , num , Visit , path , i+1 ,j , row , col );
        num_down = num[i+1][j]; 
    }
    int now_pos = (i-1)*col + j ; 
    int left_pos = (i-1)*col + j + 1;
    int down_pos = i * col + j ;
    if(num_down >= num_left){
        num[i][j] += num_down;
        path[now_pos] = down_pos; 
    }
    else{
        num[i][j] += num_left ; 
        path[now_pos] = left_pos;
    }
    return ; 
}

int count_path(vector<vector<bool>>& gar , vector<vector<int>>& num , vector<vector<bool>>& Visit , vector<vector<int>>& cnt , int i , int j , int row , int col ){
    if(Visit[i][j]) return cnt[i][j];
    Visit[i][j] = true ;
    if(num[i][j] == 1 ){
        cnt[i][j] = 1 ; 
        return cnt[i][j]; 
    }
    for(int dx = 0 ; i + dx <= row ; dx++){
        for(int dy = 0 ; j + dy <= col ; dy++ ){
            if(!dx && !dy) continue ;   // 兩個都不能為0
            if(gar[i+dx][j+dy] && (num[i][j] == (num[i+dx][j+dy]+gar[i][j]))){    // 這個地方有垃圾，並且現在這個地方的最大垃圾總數跟下一個地方的最大垃圾總數只差 1 
                cnt[i][j] += count_path(gar , num , Visit , cnt , i+dx , j+dy, row , col);    // 那就加上這個路徑
            }
        }
    }
    return cnt[i][j];
}
void print_path(vector<vector<bool>>& gar , vector<vector<int>>& num , vector<int>& path , int now_pos , int g_count , int row, int col ){
    if( g_count > num[1][1]) return ; 
    // 將編號轉化為座標，並看有沒有垃圾 
    int now_x , now_y;
    if(now_pos % col == 0 ) {
        now_y = col ; 
        now_x = now_pos / col;
    }
    else{
        now_y = now_pos % col ; 
        now_x = now_pos / col + 1 ;
    }
    int next = path[now_pos];
    if(gar[now_x][now_y]){
        if(g_count == num[1][1]) cout << now_pos << endl;
        else{
            cout << now_pos << " " ;
            print_path(gar , num , path , next , g_count+1 , row , col );
        }
    }
    else{
        print_path(gar , num , path , next , g_count , row , col );
    }
    return ;
}
int32_t main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(0);
    int row , col ; 
    int t = 1 ;
    while(cin >> row >> col ){
        if(row == -1 && row == col ) break;
        vector<vector<bool>> gar(MAX, vector<bool>(MAX,false)); // 紀錄是否有 garbage
        vector<vector<int>> num(MAX,vector<int>(MAX,0));    // num[i][j] 從 i , j 出發走到最後的最大垃圾總數  , path[M] 紀錄最佳路徑 
        vector<vector<int>> cnt(MAX,vector<int>(MAX,0));    // count[i][j] 從 i , j 出發走到最後的 最佳方法總數
        vector<int> path(M,0);
        int gar_x , gar_y ;
        while(cin >> gar_x >> gar_y) {   
            if(gar_x == gar_y && gar_x == 0 ) break;
            gar[gar_x][gar_y] = true;
        }
        vector<vector<bool>> visit_dp(MAX,vector<bool>(MAX,0));
        dp(gar , num , visit_dp, path ,1,1 ,row , col );

        vector<vector<bool>> visit_cnt (MAX,vector<bool>(MAX,0));
        count_path(gar , num , visit_cnt, cnt , 1 , 1 , row , col );

        cout << "CASE#" << t++ << ": " << num[1][1] << " " << cnt[1][1] << " ";
        print_path(gar , num , path , 1, 1 , row,col);
    }
}

/*
6 7
1 2
1 4
2 4
2 6
4 4
4 7
6 6
0 0
-1 -1 
*/ 