#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> arr(n,vector<int>(n,0));   
    int width = 0; 
    int copy = n*n ;
    while(copy > 0 ){
        copy /= 10 ;
        width++ ;
    }
    // 3 2 2 1 1
    // 4 3 3 2 2 1 1
    // 10 9 9 8 8 7 7 6 6 5 5 4 4 3 3 2 2 1 1 
    int now = 1 ; 
    for(int i = 0 ; i < n ; i++ ){
        arr[0][i] = now++;
    }
    int now_dir = 1; 
    int now_i = 0 , now_j = n-1;
    for(int i = n-1 ; i >= 1 ; i-- ){   // 跑數字
        for(int m = 0 ; m < 2 ; m++ ){  // 每個數字重複兩次
            now_dir %= 4 ; 
            for(int k = 0 ; k < i ; k++ ){  // 放值
                now_i += di[now_dir];
                now_j += dj[now_dir];
                arr[now_i][now_j] = now++;   
            }
            now_dir ++;
        }
    }
    
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cout << fixed << setw(width) << arr[i][j];
            if( j != n-1 ){
                cout << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}