/*
    Author : 李承諺(B123040032)
    Date : Sept. 16, 2024 
    PurPose : 印出一階、三階、五階、七階、九階的魔方陣，魔方陣定義為，方陣中的各個橫列，直行，對角斜線上之數字加起來的和均相等
*/

#include<iostream>
using namespace std;

//處理square的函式
void magic_square(int number ){
    int matrix[number][number]; // 紀錄的二維陣列
    int sum = 0 ;   // 現在填入幾個，一開始是0

    //初始化 
    for(int i = 0 ; i < number ;i++ ){  //迴圈變數 for 初始化矩陣
        for(int j = 0 ; j < number ;j++){
            matrix[i][j] = 0 ;  //將每個位置設為0
        }
    }

    int now_i = 0  , now_j = number/2;  // 填入1的位置在第0行的正中間
    matrix[now_i][now_j] = ++sum;       // 填入1
    //填入數字
    for(int i = 0 ; i < number ; i++ ){
        for(int j = 0 ; j < number ; j++ ){
            int next_i = now_i - 1 < 0 ? number-1 : now_i - 1 ;     // 下一個填入位置的 i , j  
            int next_j = now_j - 1 < 0 ? number-1 : now_j - 1 ;     // 如果小於0，就是到另一邊的邊界

            if(matrix[next_i][next_j]){     // 如果下一個要填入的數字有值的話，那就填到上一個數字的下方
                next_i = now_i + 1 > number ? 0 : now_i + 1 ;   //如果上一個數字的下方超出邊界的話，就回到另一邊的邊界
                next_j = now_j; //j維持不動
            }
            matrix[next_i][next_j] = ++sum;     //填入數字
            now_i = next_i ;                    //讓now變成現在填入的位置
            now_j = next_j ;                    //讓now變成現在填入的位置
            if (sum == number*number) break ;   // 如果填入的數字數量 = number的平方， 就結束程式
        }
    }

    //輸出二維陣列
    for(int i = 0 ; i < number ; i++ ){     //迴圈變數 for 印出二維陣列
        for(int j = 0 ; j < number ; j++ ){ //迴圈變數 for 印出二維陣列
            cout << matrix[i][j] << " ";    //輸出每個數字 並讓數字跟數字間有空格
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    magic_square(1);    
    magic_square(3);    
    magic_square(5);    
    magic_square(7);    
    magic_square(9);    
}