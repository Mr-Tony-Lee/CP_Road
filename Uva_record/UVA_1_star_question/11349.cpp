#include<iostream>
#include<string>
using namespace std;


int main(){
    int times ;
    cin >> times ;
    int count = 1 ;
    while(times--){
        char useless_1,useless_2;
        int N ;
        cin >> useless_1 >> useless_2 >> N ;
        long long int **matrix = new long long int*[N];
        for(int i = 0 ; i < N ; i++ ){
            matrix[i] =  new long long int[N];
            for(int j = 0 ; j < N ; j++ ){
                cin >> matrix[i][j] ;
            }
        }
        bool flag = true ;
        for(int i = 0 ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j++ ){
                if(matrix[i][j] != matrix[abs(N-i-1)][abs(N-j-1)] || matrix[i][j] < 0 ){
                    flag = false ;
                    break;
                }
            }
            if(!flag){
                break;
            }   
        }
        if(flag){
            cout << "Test #" << count << ": Symmetric." << endl;
        }
        else{
            cout << "Test #" << count << ": Non-symmetric." << endl;
        }   
        count ++ ; 
        for(int i = 0 ; i < N ; i++){
            delete matrix[i];
        }
        delete matrix;
    }
}
//4ms, 360KB