#include<bits/stdc++.h>
using namespace std;

// 101 102 103 201 202 203 
// 259001 259002 259003 259004 259005 260001 260002 260003
// 259001 259002
int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    int kase = 0 ; 
    while(cin >> n ){
        if(kase) cout << endl;
        cout << "Scenario #" << ++kase << endl;

        vector<vector<int>> team ; 
        for(int i = 0 ; i < n ; i++ ){
            int s ;
            cin >> s ;
            vector<int> each(s,0);
            for(int j = 0 ; j < s ; j++ ){
                cin >> each[j] ;
            }
            team.push_back(each);
        }
        string input ;
        vector<queue<int>> q;
        
        while(cin >> input ){
            int number ;
            if(input == "ENQUEUE"){
                cin >> number ;
            }
            else if ( input == "DEQUEUE"){
                cout << q.front() << endl;
                q.pop_front();        
            }
            else if (input == "STOP"){
                break;
            }
        }

    }
    
}