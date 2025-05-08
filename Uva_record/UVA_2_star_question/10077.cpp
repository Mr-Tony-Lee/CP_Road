#include<bits/stdc++.h>
using namespace std;
string ans = "";
int n , m ;
double now ;
int preli = 0 , prelj = 1 , preri = 1 , prerj = 0 ;
void dfs(int i , int j ){
    double t = 1.0 * i / j ;
    if(now > t ){
        ans.push_back('R');
        preli = i , prelj = j ;
        dfs(preli + preri , prelj + prerj );
    }
    else if (now < t ){
        ans.push_back('L');
        preri = i , prerj = j ;
        dfs(preli + preri , prelj + prerj );
    }
    else{
        return ;
    }
}
/*
5 7
878 323
1 1
*/
int main(){
    
    while(cin >> n >> m ){
        if(n == m && n == 1 ) break;
        preli = 0 , prelj = 1 , preri = 1 , prerj = 0 ;
        now = 1.0 * n / m ;
        ans.clear();
        dfs( 1 , 1 );
        cout << ans << endl;
    }
}