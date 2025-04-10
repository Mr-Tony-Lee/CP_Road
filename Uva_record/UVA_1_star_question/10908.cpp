#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T ;
    while(T--){
        int M , N , Q;
        cin >> M >> N >> Q;
        char matrix[M][N];
        for(int i = 0 ; i < M ; i++ ){
            for(int j = 0 ; j < N ; j ++ ){
                cin >> matrix[i][j];
            }
        }
        cout << M << " " << N << " " << Q << endl;
        while(Q--){
            int r , c ; // center
            cin >> r >> c ;
            bool flag = true;
            int count = 0 ; 
            while(flag){
                count ++ ;
                for(int i = r-count ; i <= r+count ; i++ ){
                    for(int j = c-count ; j <= c+count ; j++ ){
                        if(matrix[i][j] != matrix[r][c]){
                            flag = false ;
                            break;
                        }
                        if(j < 0 || j > N-1 ){
                            flag = false;
                            break;
                        }
                    }
                    if(i < 0 || i > M-1 ){
                        flag = false ;
                        break;
                    }
                }
            }
            cout << 2*count-1 << endl;   
        }
    }
}
//6ms, 320KB