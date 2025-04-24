#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p ;

bool cmp(p a , p b ){
    return a.first < b.first || (a.first == b.first && b.second < a.second); 
}


int main(){
    int t ;
    cin >> t ;
    while(t--){
        int M ;
        cin >> M ;
        int l, r ;
        vector<p> all_seg ;
        while(cin >> l >> r && (l || r)){
            all_seg.push_back({l,r});
        }
        int L = 0 ; 
        sort(all_seg.begin() , all_seg.end(), cmp);
        vector<p> ans ;
        int i = 0 ;
        while( L < M ){
            int maxR = 0 , maxI = 0 ;
            bool find = false ;
            while( i < (int)all_seg.size() ){
                if( all_seg[i].first <= L ){
                    find = true;
                    if(all_seg[i].second > maxR){
                        maxR = all_seg[i].second;
                        maxI = i ;
                    }
                }
                else break;
                i++;
            }
            if(find){
                ans.push_back(all_seg[maxI]);
                L = maxR;
            }
            else{
                break;
            }
        }
        if( L >= M ){
            cout << ans.size() << endl;
            for(int i = 0 ; i < (int)ans.size(); i++ ){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
        else{
            cout << "0" << endl;
        }
        cout << endl;
    }
}

// greedy and sort ,
// 把資料根據 L 排序， 一開始設左區間終點為 L = 0 
// 接下來下一筆資料的左區間必須從 L <= 0 開始，
// 然後把 L 符合的資料抓出來，找出最大 R 的區段
// 然後把此筆資料的右區間紀錄， 更新 L = maxR
// 接下來作法以此類推，每次都選小於 L 的，並更新 L 
// 參考資料 : https://yuihuang.com/zj-e576/
/*
2
1
-1 0
-5-3
2 5
0 0

1 
-1 0
0 1
0 0

*/