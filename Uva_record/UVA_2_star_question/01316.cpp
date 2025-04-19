#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a , pair<int,int> b ){
    return (a.first > b.first) || (a.first == b.first && a.second > b.second);
}

int main(){
    int n ;
    while( cin >> n ){
        vector<pair<int,int>> list;
        int maxd = 0 ; 
        for(int i = 0 ; i < n ; i++ ){
            int d , g ;
            cin >> g >> d ;
            list.push_back({g,d});
            maxd = max(maxd,d);
        }
        sort(list.begin() , list.end() , cmp);  // 先把 list 根據 gain由大到小排序
        int ans = 0 ;
        vector<int> day_arange(maxd+1,0);   // day_arange[i] 代表把工作排在 區間 [i-1,i]
        for(int i = 0 ; i < (int)list.size() ; i++ ){   
            for(int j = list[i].second ; j > 0 ; j--){
                if(day_arange[j] == 0 ){    // 在區間 [0,i] 之間找到一個區塊可以放，越後面越好
                    day_arange[j] = list[i].first;
                    ans += list[i].first;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
/*
4 50 2 10 1 20 2 30 1
7 20 1 2 1 10 3 100 2 8 2 5 20 50 10
*/
// 參考資料 https://par.cse.nsysu.edu.tw/~cbyang/course/advprog/advprog_index.htm -> greedy method 