#include<bits/stdc++.h>
using namespace std;

// 101 102 103 201 202 203 
// 259001 259002 259003 259004 259005 260001 260002 260003
// 259001 259002
int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    int kase = 0 ; 
    while(cin >> n , n){
        if(kase) cout << endl;
        cout << "Scenario #" << ++kase << endl;

        map<int,int> num_team ;
        for(int i = 0 ; i < n ; i++ ){
            int m ; 
            cin >> m ; 
            for(int j = 0 ; j < m ; j++ ){
                int num ;
                cin >> num ;
                num_team[num] = i ;
            }
        }
        vector<queue<int>> team_first(n);
        queue<queue<int>*> all_team ;
        string input ;
        while(1){
            cin >> input ;
            if(input == "ENQUEUE"){
                int x ;
                cin >> x; 
                if( team_first[num_team[x]].empty()){
                    all_team.push(&team_first[num_team[x]]);
                }
                team_first[num_team[x]].push(x);
            }
            else if (input == "DEQUEUE"){
                if(all_team.front()->empty()){
                    all_team.pop();
                }
                int num = all_team.front()->front();
                all_team.front()->pop();
                cout << num << endl;
            }
            else{
                break;
            }
        }
    }   
}
/*
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0

*/