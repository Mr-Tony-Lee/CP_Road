#include<bits/stdc++.h>
using namespace std;
#define int long long 

int dfs(int start , int dest , int tons ,vector<vector<int>>& city , int size , bool* visit){
    visit[start] = true;
	if (start == dest ) return tons; 

	for (int i = 1; i < size ; ++i) if (city[start][i] > 0 && !visit[i]){
		int tmp = dfs(i, dest, min(tons, city[start][i]), city , size , visit);
		if (tmp > 0)
		{
			city[start][i] -= tmp;
			city[i][start] += tmp;
			return tmp;
		}
	}
    return 0 ;
}

int32_t main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n , r ;
    int t = 1 ; 
    while(cin >> n >> r){
        if(n == r && r == 0 ) break;
        vector<vector<int>> city ;
        for(int i = 0 ; i < n+1 ; i++ ){
            vector<int> s_city(n+1,0);
            city.push_back(s_city);
        }
        int ans = 0 ; 
        int city_cnt = 1 ; 
        unordered_map<string,int> name ;
        for(int i = 0 ; i < r ; i++ ){
            string c1 , c2 ;
            int tons ;
            cin >> c1 >> c2 ;
            cin >> tons ;
            if(name.count(c1) == 0 ) name[c1] = city_cnt++;
            if(name.count(c2) == 0 ) name[c2] = city_cnt ++ ;
            city[name[c1]][name[c2]] += tons;
            city[name[c2]][name[c1]] += tons;    
        }
        string start , dest ;
        cin >> start >> dest ;
        bool visit[n+1] = {};
        while(1){
            memset(visit, false, sizeof(visit));
            int tmp = dfs(name[start] , name[dest] , 10001 , city , n+1 ,visit);
            if (tmp <= 0) break;
            else ans += tmp ;
        }
        if(t != 1 ){
            cout << endl;
        }
        cout << "Scenario #" << t++ << endl;
        cout << ans << " tons" << endl;
    }
}

/*
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20

4 6
A D 5
A B 20
A C 10
B C 5
B D 10
C D 20
A D
*/