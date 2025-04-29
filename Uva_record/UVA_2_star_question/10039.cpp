#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> DT;

int main(){
    int t;
    cin >> t ;
    int kase = 0 ;
    while(t--){
        int n ;
        cin >> n ;
        map<string,int> city;
        for(int i = 0 ; i < n ; i++ ){
            string input;
            cin >> input ;
            city[input] = i;
        }
        int T ;
        cin >> T ;
        vector<vector<DT>> edge(101) ;
        while(T--){
            int ti;
            cin >> ti ;
            int from , to , pre_time = 0 ;
            for(int i = 0 ; i < ti ; i++ ){
                int st ;
                string name ;
                cin >> st >> name;
                to = city[name];
                if(i && st >= pre_time){
                    edge[from].push_back({pre_time , st , to});
                }
                from = to , pre_time = st ;
            }
        }
        int start_time , from , to ;
        string name1 , name2 ;
        cin >> start_time >> name1 >> name2 ;
        from = city[name1];
        to = city[name2];
        cout << "Scenario " << ++kase << endl;


        int dist[2400][105];    // dist[抵達時間][到達哪站] = 出發時間
        memset(dist,-1,sizeof(dist));
        for(int i = 0 ; i < (int)edge[from].size() ; i++ ){
            int from_time = get<0>(edge[from][i]) ;
            int arrival_time = get<1>(edge[from][i]) ;
            int arrival_pos = get<2>(edge[from][i]) ;
            if( from_time >= start_time ){
                dist[arrival_time][arrival_pos] = from_time ;
            }
        }
        bool connect = false;
        for(int i = start_time ; i < 2400  ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                if(dist[i][j] == -1 ) continue;
                //  假如現在 m 有路到 j ， 那就看 j 能到哪裡
                // 假設可以從 j 到 l ， 那就表示也可以直接從 m 到 l 
                // 那就看 m 到 l 跟 j 到 l 哪個出發的時間較晚
                for(int k = 0 ; k < (int)edge[j].size() ; k++ ){
                    int from_time = get<0>(edge[j][k]) ;
                    int arrival_time = get<1>(edge[j][k]) ;
                    int arrival_pos = get<2>(edge[j][k]) ;
                    if( from_time >= i ){
                        dist[arrival_time][arrival_pos] = max(dist[arrival_time][arrival_pos], dist[i][j]);
                    }
                }
            }
            if(dist[i][to] != -1 ){
                printf("Departure %04d " , dist[i][to] );
                cout << name1 << endl;
                printf("Arrival   %04d " , i );
                cout << name2 << endl;
                connect = true; 
                break;
            }
        }
        if(!connect){
            cout << "No connection" << endl;
        }
        cout << endl;
    }
}
// 參考資料 : https://mypaper.pchome.com.tw/zerojudge/post/1324398988
/*
2
3
Hamburg
Frankfurt
Darmstadt
3
2
0949 Hamburg
1006 Frankfurt
2
1325 Hamburg
1550 Darmstadt
2
1205 Frankfurt
1411 Darmstadt
0800
Hamburg
Darmstadt
2
Paris
Tokyo
1
2
0100 Paris
2300 Tokyo
0800
Paris
Tokyo
*/