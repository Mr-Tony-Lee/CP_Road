#include<bits/stdc++.h>
using namespace std;
bool cmp(tuple<int,int,string> a , tuple<int,int,string> b){
    return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b));
}
int main(){
    cin.tie(0);  cout.tie(0) ; ios::sync_with_stdio(0);
    int M ;
    cin >> M ;
    while(M--){
        int m , n ;
        cin >> m >> n ;
        cin.ignore();
        // priority_queue<pair<int,string>,vector<pair<int,string>> , greater<pair<int,string>>> inversion_string ;    // 不保證是根據原本題目的Order  
        vector<tuple<int,int,string>> inversion_string;
        for(int i = 0 ; i < n ; i++ ){
            string line ; 
            getline(cin,line);
            int inversion = 0 ;
            for(int j = 0 ; j < m-1 ; j++ ){
                int now = line[j];
                for(int k = j+1 ; k < m ; k++ ){
                    if( now > line[k]){
                        inversion++ ; 
                    }
                }
            }
            inversion_string.push_back({inversion,i,line});
        }
        sort(inversion_string.begin() , inversion_string.end(), cmp);
        for(auto& [inversion,i,line] : inversion_string){
            cout << line << endl;
        }
        if( M != 0 ){
            cout << endl;
        }
    }
}
/*
1

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

*/