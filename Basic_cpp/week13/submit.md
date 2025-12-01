第一題:
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

第二題:

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Student{
    char name[20];
    int score;
};

Student* findTopStudent(Student* list , int N ){
    if(N == 0 ) return nullptr;
    Student* mmax;
    int smax = 0 ; 
    for(int i = 0 ; i < N ; i++ ){
        if(list[i].score > smax){
            mmax = &list[i];
            smax = list[i].score;
        }
    }
    return mmax ;
}

int main(){
    int N ;
    cin >> N ;

    Student* list = new Student[N];
    for(int i = 0 ; i < N ; i++ ){
        string n ;
        int s;
        cin >> n >> s ;
        for(int j = 0 ; j < n.size() ; j++ ){
            list[i].name[j] = n[j];
        }
        list[i].score = s ;
    }
    Student* mmax = findTopStudent(list, N);
    cout << "Top student: ";
    for(int i = 0 ; i < strlen(mmax->name) ; i++ ){
        cout << mmax->name[i] ;
    }
    cout << endl;
}