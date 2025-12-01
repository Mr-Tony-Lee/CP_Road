#include<iostream>
using namespace std;

int** CreateMatrix(int m , int n ){
    int **matrix = new int*[m];
    for(int i = 0 ; i < m ; i++ ){
        matrix[i] = new int[n];
        for(int j = 0 ; j < n ; j++ ){
            matrix[i][j] = 0 ; 
        }
    }
    return matrix;
}
void DeleteMatrix(int** mat , int m ){
    for(int i = 0 ; i < m ; i++ ){
        delete mat[i];
    }
    delete mat ;
}

int main(){
    int m , n ;
    cin >> m >> n ;
    int **matrixA = CreateMatrix(m,n);
    int **matrixB = CreateMatrix(m,n);
    int **matrixC = CreateMatrix(m,n);
    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cin >> matrixA[i][j];
        }
    }
    
    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cin >> matrixB[i][j];
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if(j == 0 )
                cout << matrixC[i][j] ;
            else
                cout << " " << matrixC[i][j];
        }
        cout << endl;
    }

    DeleteMatrix(matrixA, m );
    DeleteMatrix(matrixB, m );
    DeleteMatrix(matrixC, m );
    return 0 ;
}