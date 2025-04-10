#include<bits/stdc++.h>
using namespace std;

int total , board_x , board_y ; 

class tile{
    public:
        int m , w , h ;
        tile(int = 0 , int = 0 , int = 0 );
};

tile::tile(int a , int b , int c){
    m = a ;
    w = b ;
    h = c ;
}
void travel(vector<vector<bool>>& map , int x , int y , int type , tile t ){
    if(type == 1 ) swap(t.w,t.h);
    for(int i = x ; i < x + t.w ; i++ ){
        for(int j = y ; j < y + t.h ; j++ ){
            map[i][j] = (!map[i][j]);   // 走第一次就是放下去，第二次就是拿起來 
        }
    }
    if(type == 1 )  swap(t.h,t.w);  // 換回去
    
}
bool judge(vector<vector<bool>>& map  , int x , int y , tile t , int type){
    if(type == 1 )  {
        if(t.w == t.h) return false ;   // 如果是正方形，那有沒有切換沒差
        swap(t.w,t.h);  // 切換成另一種方塊 
    }
    if( x + t.w > board_x || y + t.h > board_y) return false ;  // 確認邊界
    for(int i = x ; i < x + t.w ; i++ ){
        for(int j = y ; j < y + t.h ; j++ ){
            if(map[i][j]){
                if(type == 1 ) swap(t.w,t.h);   // 換回去
                return false ;  // 如果有區塊被佔用了， 那就不能放
            }   
        }
    }
    swap(t.w,t.h);   // 換回去
    return true ;
}


int dfs(vector<vector<bool>>& map , vector<tile>& tile , int x , int y , int now){ // now 是現在總共用的數量
    // cout << x << " " << y << endl;
    int ans = 0 ;
    if ( now == total ) return 1 ;
    if( y == board_y ) return dfs(map, tile, x+1 , 0 , now);
    if( x >= board_x) return 0 ;
    if( map[x][y] ) return dfs(map, tile , x , y+1 , now);

    for(int k = 0 ; k < tile.size() ; k++ ){    // 把每一種方塊跑一遍
        if(!tile[k].m) continue;    // 沒了方塊，就跳過不用
        if(judge(map,x,y,tile[k],0)){   // 放第一種
            travel(map, x, y , 0 , tile[k]);
            tile[k].m--;
            ans += dfs(map, tile ,x , y+1 , now+1);
            travel(map, x, y , 0 , tile[k]);
            tile[k].m++;
        }
        if(judge(map,x,y,tile[k],1)){   // 放第二種
            travel(map, x, y , 1 , tile[k]);
            tile[k].m--;
            ans += dfs(map, tile ,x , y+1 , now+1);
            travel(map, x, y , 1 , tile[k]);
            tile[k].m++;
        }
    }
    
    return ans ;
}

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    while(cin >> board_x >> board_y ){
        int n ; 
        cin >> n ;
        vector<tile> all ; 
        // 總共就20種方塊
        total = 0 ; 
        for(int i = 0 ; i < n ; i++ ){
            int m , w , h ;
            cin >> m >> w >> h ;
            total += m ; 
            all.push_back(tile(m,w,h));
        }
        vector<vector<bool>> map(board_x, vector<bool>(board_y,false));
        cout << dfs(map , all , 0 , 0 , 0 ) << endl;
    }
}
/*
    解題說明 : 
        用dfs把所有的方塊都排一次。

*/