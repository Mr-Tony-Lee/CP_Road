#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    int n ;
    cin >> n ;
    int count = 1; 
    while(n--){
        int N ;
        cin >> N ; 
        vector<vector<int>> matrix;
        for(int i = 0 ; i < N ; i++ ){
            vector<int> row; 
            string input;
            cin >> input ;
            for(int j = 0; j < N ; j++ ){
                row.push_back(input[j]-'0') ;
            }
            matrix.push_back(row);
        }
        int M ;
        cin >> M ; 
        while(M--){
            fflush(stdin);
            string input ;
            cin >> input ;
            if(input[0] == 'r'){
                int a , b ;
                cin >> a >> b ;
                for(int i = 0 ; i < N ; i++ ){
                    swap(matrix[a-1][i], matrix[b-1][i]);
                }
            }
            else if ( input[0] == 't'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < i ; j++ ){
                        swap(matrix[i][j] , matrix[j][i]);
                    }
                }
            }
            else if (input[0] == 'i'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < N ; j++ ){
                        matrix[i][j]++;
                        matrix[i][j] %= 10 ;
                    }
                }
            }
            else if (input[0] == 'd'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < N ; j++ ){
                        matrix[i][j]--;
                        if(matrix[i][j] < 0 ){
                            matrix[i][j] += 10 ;
                        }
                    }
                }
            }
            else if (input[0] == 'c'){
                int a , b ;
                cin >> a >> b ;
                for(int i = 0 ; i < N ; i++ ){
                    swap(matrix[i][a-1], matrix[i][b-1]);
                }
            }
        }
        cout << "Case #" << count << endl;
        for(int i = 0 ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j++ ){
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout<< endl;
        count ++ ;
    }
}
// Accepted Uva