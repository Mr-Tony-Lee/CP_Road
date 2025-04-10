#include<bits/stdc++.h>
using namespace std;
#define int long long 
// 此處開始 dfs 
int dfs(int start , int dest , int dis ,vector<vector<int>>& city , int size , bool* visit){
    
    visit[start] = true;    // 進來的點先設為已走過
	if (start == dest ) return dis;    // 如果到終點了就 return 在這條路徑上找到的最大流量(也就是路徑上的最小值)

	for (int i = 1; i < size ; ++i) if (city[start][i] > 0 && !visit[i]){   // 如果這個邊還可以流，並沒有走訪過
		int tmp = dfs(i, dest, min(dis, city[start][i]), city , size , visit);  // 那就往下一個邊走，然後把到目前的最大流量(最小值)傳下去
		if (tmp > 0)    // 如果最大流量(最小值) 大於 0 
		{
			city[start][i] -= tmp;  // 更新這條路徑上的流量(順向的減掉，逆向的增加)
			city[i][start] += tmp;
			return tmp; // 並回傳最大流量
		}
	}
    return 0 ;  // 如果中途發現此節點為辦法往下走，就回傳0
}

// 模擬水流出去後的所有可走情況 
int32_t main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n ;
    int times = 1 ; 
    while(cin >> n && n ){
        int s , t , c ;
        cin >> s >> t >> c ;
        vector<vector<int>> city ;  // 紀錄所有邊的剩餘流量
        for(int i = 0 ; i < n+1 ; i++ ){
            vector<int> s_city(n+1,0);
            city.push_back(s_city);
        }
        int ans = 0 ; 
        int city_cnt = 1 ; 
        for(int i = 0 ; i < c ; i++ ){
            int a , b , num ; 
            cin >> a >> b >> num ;
            city[a][b] += num ; 
            city[b][a] += num ;
        }
        bool visit[n+1] = {};   // 是否走過 
        while(1){
            memset(visit, false, sizeof(visit));    
            // 每次dfs都重置visit ， 因如果找到一條增廣路徑，那麼那一條路徑上有一個邊會是0，因為是0 ， dfs 就不會走，自然就排除掉走重複的路的問題了
            int tmp = dfs(s , t , 10001 , city , n+1 ,visit);   
            // 找到增廣路徑上可以走的最大流量
            if (tmp <= 0) break;   
            else ans += tmp ;   // 把每條路的流量都加起來
        }
        cout << "Network " << times++ << endl;
        cout << "The bandwidth is " << ans << "." << endl;
        cout << endl;
    }
}
/*
    解題說明 : 
        此題運用 Ford-Fulkerson 去解決問題，透過dfs去找出每一條路徑上可以流多少水，有點像往起點倒入無限的水，有多少水可以順著管道流向終點，
        實作流程就是，一開始用陣列存取每個邊的流量(雙向圖)，透過dfs，每找到一條路徑可以流，
        就記錄此路徑的最大流量(路徑上的最小值)，最後透過遞迴，去更新這條路徑上的值，順向的就要扣掉此最大流量，逆向的就要加回來，
        最後把每一條路徑的最大流量記錄到 ans 並加起來。
*/

/*
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
*/

/*
4 6
A D 5
A B 20
A C 10
B C 5
B D 10
C D 20
A D
*/
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<pair<int,int>> edge[101];
//     int n ; 
//     int times = 1 ; 
//     while(cin >> n && n ){ 
//         int arr[n+1][n+1] = {};
//         int ans = 0 ; 
//         int s , t , c ;
//         cin >> s >> t >> c ;
//         while(c--){
//             int a , b , dis ;
//             cin >> a >> b >> dis ;
//             edge[a].push_back(make_pair(b,dis));
//             edge[b].push_back(make_pair(a,dis));
//         }
//         // for(int i = 1 ; i <= n ; i++ ){
//         //     for(int j = 0; j < edge[i].size() ; j++ ){
//         //         cout << i << " " << edge[i][j].first << " " << edge[i][j].second << endl;
//         //     }
//         // }

//         // dfs 
//         int root = s ;
//         stack<int> dfs ;
//         dfs.push(root);
//         bool Visit[n+1] = {};
//         Visit[root] = true; 
     
        
//         int route = INT_MAX;
//         while(!dfs.empty()){
//             root = dfs.top();
//             dfs.pop();
//             for(auto it:edge[root]){
//                 if(!Visit[it.first]){
                    
//                 }
//             }    
//             if(root == t){
//                 ans += route;
//             }
//         }

//         cout << "Network " << times++ << endl;
//         cout << "The bandwidth is " << ans << "." << endl;
//     }
// }
// /*

// 4
// 1 4 5
// 1 2 20
// 1 3 10
// 2 3 5
// 2 4 10
// 3 4 20

// */