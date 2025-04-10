#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int m , n ;
    while(cin >> m >> n ){
        vector<vector<bool>> trans(26,vector<bool>(26,false));
        for(int i = 0 ; i < m ; i++ ){
            char a , b ;
            cin >> a >> b ;
            trans[a-'a'][b-'a'] = true;
        }
        // 有向圖 ford
        for(int k = 0 ; k < 26 ; k++ ){
            for(int i = 0 ; i < 26 ; i++ ){
                for(int j = 0 ; j < 26 ;j++ ){
                    trans[i][j] = trans[i][j] || (trans[i][k] & trans[k][j]);
                }
            }
        }
        // for(int i = 0 ; i < 26 ; i++ ){
        //     for(int j = 0 ; j < 26 ; j++ ){
        //         if(trans[i][j]) cout << char('a'+i) << " " << char('a' + j ) << endl;
        //     }
        // }
        // for(int i = 0 ; i < 26 ; i++ ){
        //     cout << char('a' + i) << " : ";
        //     for(int j = 0 ; j < trans[i].size() ; j++ ){
        //         cout << trans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0 ; i < n ; i++ ){
            string a , b ;
            cin >> a >> b ;
            if( a.size() != b.size()){
                cout << "no" << endl;
                continue;
            }
            int j = 0; 
            for(j = 0 ; j < a.size() ; j++ ){
                if(a[j] == b[j]) continue ;
                if(!trans[a[j]-'a'][b[j]-'a']){
                    cout << "no" << endl;
                    break;
                }
            }
            if( j == a.size())
                cout << "yes" << endl;
            // cout << a << " " << b << endl;
        }
        
    }
}
/*
9 5
c t
i r
k p
o c
r o
t e
t f
u h
w p
we we
can the
work people
it of
out the
*/