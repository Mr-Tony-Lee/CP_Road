#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m;

vector<int> edge[10021]; //邊的陣列

int Visit[10021];
int dist[10021], important[10021]; //dist 從 x 到 index 的距離
// important 重要車站，當經過的路徑大於 2，就是重要車站

// 使用 bfs 走訪所有車站
int solve(int root){ \
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX; // root 一開始無法抵達這些點，因此都是 INT_MAX
    memset(Visit, 0, sizeof(Visit));

    deque<int> q; // queue 類似於 dijkstra piority queue
    q.push_back(root); 
    dist[root] = 0; // root 到本身為 0

    while(!q.empty()){
        root = q.front(); q.pop_front();
        for(auto it: edge[root]){
            if(dist[it] > dist[root] + 1){
                dist[it] = dist[root] + 1;
                if(!Visit[it]){
                    Visit[it] = 1;
                    q.push_back(it);
                }
            }
        }
    }

    int ans = 0; 
    for(int i = 1; i <= n; i++){ //計算可以抵達每一個車站，使用多少距離
        if(important[i] > 1) ans += dist[i]; //如果 root 沒辦法抵達此車站，那就會是 INT_MAX
    }
    return ans;
}

int32_t main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) edge[i].clear();

        memset(important, 0, sizeof(important));
        while(m--){
            int pre, next;
            cin >> pre;
            while(cin >> next && next){
                edge[pre].push_back(next); //有向圖
                edge[next].push_back(pre);
                important[pre]++; //經過的路徑 + 1
                pre = next;
            }
            important[pre]++;  //經過的路徑 + 1
        }
        // min_dist 當前的最小距離，ans 當前最小距離的車站
        int ans = 0, min_dist = INT_MAX, dist;
        for(int i = 1; i <= n; i++){
            if(important[i] > 1){ //當經過的路徑大於 1，就是重要車站
                dist = solve(i);
                if(dist < min_dist){
                    ans = i;
                    min_dist = dist;
                }
            }
        }
        cout << "Krochanska is in: " << ans << endl; //輸出答案
    }
    return 0;
}
/*
    解題說明 : 
        使用 bfs 去解題，把所有車站都存在edge裡面 edge[i] 存放第i個車站的可以前往的車站，然後important一定出現2次以上，
        存完後，遍歷所有的車站，如果此車站是important，那就進去solve函數，一開始初始化與所有車站的距離，然後root就是目前的important，
        然後用 bfs 遍歷所有車站，更新與所有車站的距離，最後再去計算此imoportant 到其他important車站的距離是多少，
        最少的就是我們的ans
*/