#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    int n ;
    cin >> n ;
    while(n--){
        int m , y , c ;
        cin >> m >> y >> c;
        string need;
        cin >> need;
        map<char, vector<int>> table; 
        table['M'] = {1,0,0};
        table['Y'] = {0,1,0};
        table['C'] = {0,0,1};
        table['R'] = {1,1,0};
        table['V'] = {1,0,1};
        table['G'] = {0,1,1};
        table['B'] = {1,1,1};
        table['W'] = {0,0,0};

        for(int i = 0 ; i < (int)need.size() ; i++){
            m -= table[need[i]][0];
            y -= table[need[i]][1];
            c -= table[need[i]][2];
        }
        if( m < 0 || y < 0 || c < 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES " << m << " " << y << " " << c << endl;
        }   
    }
}
// Accepted Uva