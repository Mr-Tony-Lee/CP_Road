#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> indices(n+1);
    vector<int> all ;
    all.push_back(0);
    for(int i = 0 ; i < n ; i++ ){
        int x;
        cin >> x ;
        all.push_back(x);
        indices[x] = i ;
    }
    int ans = 1 ;
    for(int num = 1 ; num < n ; num++ ){
        if(indices[num+1] < indices[num]){
            ans++;
        }
    }
    for(int i = 0 ; i < m ; i++ ){
        int a , b ;
        cin >> a >> b ;

        // judge a-1 , a , a+1 

        if(all[a] != 1 && all[b] != n ){
            int count_a = 0 , count_b = 0 ;
            if( indices[all[a]-1] > indices[all[a]]){
                count_a ++ ;
            }
            if( indices[all[a]] > indices[all[a]+1]){
                count_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                count_b ++ ;
            }
            if( indices[all[b]] > indices[all[b]+1]){
                count_b ++ ;
            }
            int new_a = 0 , new_b = 0 ; 
            indices[all[a]] = b ;
            indices[all[b]] = a ;
            if( indices[all[a]-1] > indices[all[a]]){
                new_a ++ ;
            }
            if( indices[all[a]] > indices[all[a]+1]){
                new_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                new_b ++ ;
            }
            if( indices[all[b]] > indices[all[b]+1]){
                new_b ++ ;
            }
            ans += (new_a-count_a);
            ans += (new_b-count_b);
        }
        else if ( all[a] != 1 ){
            int count_a = 0 , count_b = 0 ;
            if( indices[all[a]-1] > indices[all[a]]){
                count_a ++ ;
            }
            if( indices[all[a]] > indices[all[a]+1]){
                count_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                count_b ++ ;
            }
            int new_a = 0 , new_b = 0 ; 
            indices[all[a]] = b ;
            indices[all[b]] = a ;
            if( indices[all[a]-1] > indices[all[a]]){
                new_a ++ ;
            }
            if( indices[all[a]] > indices[all[a]+1]){
                new_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                new_b ++ ;
            }
            ans += (new_a-count_a);
            ans += (new_b-count_b);
        }
        else{
            int count_a = 0 , count_b = 0 ;
            if( indices[all[a]] > indices[all[a]+1]){
                count_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                count_b ++ ;
            }
            if( indices[all[b]] > indices[all[b]+1]){
                count_b ++ ;
            }
            int new_a = 0 , new_b = 0 ; 
            indices[all[a]] = b ;
            indices[all[b]] = a ;
            if( indices[all[a]] > indices[all[a]+1]){
                new_a ++ ;
            }
            if( indices[all[b]-1] > indices[all[b]]){
                new_b ++ ;
            }
            if( indices[all[b]] > indices[all[b]+1]){
                new_b ++ ;
            }
            ans += (new_a-count_a);
            ans += (new_b-count_b);
        }
        swap(all[a],all[b]);          
    
        cout << ans << endl;
        for(int i = 1 ; i < all.size() ; i++ ){
            cout << all[i] << " ";
        }
        cout << endl;
    }
}
