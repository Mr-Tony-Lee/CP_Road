#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    cin.ignore();
    string less = ""; 
    getline(cin,less);
    while(t--){
        int n ; 
        cin >> n ;
        cin.ignore();
        int map[n+1][n+1] = {};
        char temp ; 
        int correct = 0 , incorrect = 0 ; 
        for(int i = 1 ; i <= n ; i++ ){
            map[i][i] = 1 ;
        }
        while((temp = getchar()) && temp != '\n' ){
            int a ,b ;
            cin >> a >> b ;
            cin.ignore();
            // cout << temp << " " << a << " " << b << endl;
            if(temp == 'c') {
                map[a][b] = 1 ;
                map[b][a] = 1 ;
            }
            else if ( temp == 'q'){
                for(int k = 1 ; k <= n ; k++ ){
                    for(int i = 1 ; i <= n ; i++ ){
                        for(int j = 1 ; j <= n ; j++ ){
                            if(map[i][k] && map[k][j]){
                                map[i][j] = 1 ; 
                            }
                        }
                    }
                }
                if(map[a][b]){
                    correct++;
                }
                else{
                    incorrect++;
                }
            }
        }
        cout << correct << "," << incorrect << endl;
        if(t != 0 ){
            cout << endl;
        }
    }
}