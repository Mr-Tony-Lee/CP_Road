#include<iostream>
#include<map>
#include<utility>
using namespace std;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    pair<int,int> array[64] ;
    int map[8][8] ; 
    for(int i = 0 ; i < 8 ; i++ ){
        for(int j = 0 ; j < 8 ; j++ ){
            array[8*i+j] = make_pair(i,j);
        }
    }
    int K , Q , M ;
    while( cin >> K >> Q >> M ){
        if( K == Q ){
            cout << "Illegal state" << endl;
            continue;
        }
        for(int i = 0 ; i < 8 ; i++ ){
            for(int j = 0 ; j < 8 ; j++ ){
                map[i][j] = 0;
            }
        }
        map[array[K].first][array[K].second] = 1 ;
        map[max(0,array[K].first-1)][max(0,array[K].second)] = 2 ;
        map[max(0,array[K].first+1)][max(0,array[K].second)] = 2 ;
        map[max(0,array[K].first)][max(0,array[K].second-1)] = 2 ;
        map[max(0,array[K].first)][max(0,array[K].second+1)] = 2 ;
        if (array[Q].first == array[K].first && array[K].first == array[Q].first){
            if(array[Q].second > array[K].second ){ // K 在左邊 Q在右邊
                if(array[M].second <= array[K].second){
                    cout << "Illegal move" << endl;
                    continue;        
                }
            }
            else{
                if(array[M].second >= array[K].second){
                    cout << "Illegal move" << endl;
                    continue;        
                }
            }
        }
        else if (array[Q].second == array[K].second){
            if(array[Q].first > array[K].first ){ // K 在左邊 Q在右邊
                if(array[M].first <= array[K].first){
                    cout << "Illegal move" << endl;
                    continue;        
                }
            }
            else{
                if(array[M].first >= array[K].first){
                    cout << "Illegal move" << endl;
                    continue;        
                }
            }
        }
        if(M == K  || (!(Q/8 * 8 <= M && M < (Q/8+1)*8 ) && abs(M-Q) % 8 != 0)  || M == Q ){
            cout << "Illegal move" << endl;
        }
        else if(map[array[M].first][array[M].second] == 2) {
            cout << "Move not allowed" << endl;
        }
        else{
            if((M == 49 && K == 56) || (M==54 && K==63) || (M == 14 && K == 7) || (M == 9 && K == 0) ){
                cout << "Stop" << endl;
            }   
            else{
                cout << "Continue" << endl;
            }
        }
    }
}