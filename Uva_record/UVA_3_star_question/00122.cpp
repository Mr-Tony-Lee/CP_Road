#include<bits/stdc++.h>
using namespace std;
#define int long long 

bool cmp(pair<string,int> p1 , pair<string,int> p2 ){
    return (p1.first.size() == p2.first.size()) ? (p1.first < p2.first) : (p1.first.size() < p2.first.size());
}

int32_t main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string line ;    
    while(1){
        map<string,int> tree;
        string input ;
        bool comp = true , end = true ;
        while( cin >> input ){
            end = false;
            if(input.size() == 2) break;
            string pos = "" ; 
            int number = 0 ; 
            bool state = false ;
            for(int i = 1 ; i < (int)input.size()-1 ; i++ ){
                if(input[i] == ','){
                    state = true ;
                    continue;
                }
                if(!state)  number = number * 10 + input[i]-'0';
                else pos.push_back(input[i]);
            }
            if(tree.count(pos) > 0 || number == 0){
                comp = false;
            }
            tree[pos] = number ; 
        }
        if(end) break;
        if(!comp) {
            cout << "not complete" << endl;
            continue;
        }
        vector<pair<string,int>> ans;
        for(auto it:tree){
            string pos = it.first;
            if(it.first == ""){
                ans.push_back(make_pair(it.first ,it.second));
            }
            else if (tree.count(pos.substr(0,pos.size()-1))){
                ans.push_back(make_pair(it.first,it.second));
            }
            else{
                comp = false;
                break;
            }
        }
        if(!comp){
            cout << "not complete" << endl;
        }
        else{
            sort(ans.begin() , ans.end(), cmp);
            for(auto it:ans){
                if( it.first == "" ) cout << it.second ;
                else cout << " " << it.second ; 
            }
            cout << endl;
        }
    }
}
/*
    解題說明 : 
        本題是利用實作BST的level order，且是用字串來告知node的位置，那我使用map實作，
        把path存進去map的key裡面，value則是存node的值，然後判斷有沒有父節點的方法就是利用substr
        LLL的父節點就是LL，RLR的父節點就是RL，所以就是把最後一個丟棄，就是父節點，只要全部都有父節點
        且沒有缺失的值和重複的位置，就印出level order，否則印出 "not complete"
        實作level order的方法是用vector，把path跟value放進去，去比較path，排出順序。
*/

/*
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()
(,L) (1,R) (2,) (3,LR) (1,RL) (2,LL) (3,RR) ()
*/