#include<iostream>
#include<vector>
#include<utility>
using namespace std;
using ll = long long ;


ll C (ll x , ll y ){
    ll ans = 1 ;
    for(int i = x ; i > x-y ; i--){
        ans *= i ;
    }
    for(int i = y ; i > 1 ; i-- ){
        ans /= i ;
    }
    return ans ;
}

bool check(int line , int list , char** table , int n ){
    for(int i = 0 ; i < line ; i++ ){
        if(table[i][list] != 0 ){
            return false;
        }
    }
    for(int i = line-1 , j = list-1 ; i >= 0 && j >= 0 ; i--,j--){
        if(table[i][j] != 0 ){
            return false;
        }
    }
    for(int i = line-1 , j = list+1 ; i>=0 && j < n ; i-- ,j++ ){
        if(table[i][j] != 0 ){
            return false;
        }
    }
    return true;
}

void printmap(char** table , bool** status , int n ){
    cout << "-----------------------" << endl;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if(table[i][j]) {
                cout << "Q ";
            }
            else{
                if(status[i][j]){
                    cout << ". ";
                }
                else{
                    cout << "* ";
                }
            }
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

void solve(char** table , bool** status , int line , int n , ll& count ){
    for(int list = 0 ; list < n ; list++ ){
        if(status[line][list] && check( line , list , table , n )){
            table[line][list] = 'Q';  
            if(line == n-1 ){
                count++;
                //printmap(table, status, n );
                table[line][list] = 0 ;
                return ;
            }
            solve(table , status , line+1 , n ,count );      
            table[line][list] = 0;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n = 8 ; 
    bool** status = new bool*[n];
    char** table = new char*[n];
    for(int i = 0 ; i < n ; i++ ){
        status[i] = new bool[n];
        table[i] = new char[n];
        for(int j = 0 ; j < n ; j++ ){
            char x ;
            cin >> x ;
            if(x == '.') status[i][j] = true;
            else status[i][j] = false;
            table[i][j] = 0 ;
        }
    }
    ll ans = 0 ;
    solve(table , status , 0 , n , ans );
    cout << ans << endl;
}
