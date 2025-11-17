/*
    Author : 李承諺(B123040032)
    Date : Sept. 16, 2024 
    PurPose : 印出 1 到 N 之間所有整數之階乘(factorial) ， N <= 50 
*/
#include<iostream>
using namespace std;

//使用陣列的乘法去存數字
int* mult( int* number1 , int scale ){  //傳入要乘的scale 跟 基底的數字陣列
    int* next_number = new int[100]();  // 結果的數字陣列
    for(int i = 100 ;  i >= 1 ; i-- ){  // 把結果的數字陣列就是基底陣列的每一格都乘以scale
        next_number[i] = number1[i] * scale ;
    }
    //處理進位問題
    for(int i = 100 ; i >= 1 ; i--){    
        if( next_number[i] / 10 >= 1 ){ //如果數字大於10
            next_number[i-1] += next_number[i] / 10  ;  //那此數字的前一格就要加上 (此格的數字/10)
            next_number[i] = next_number[i] % 10 ;      //此格的數字取餘數
        }
    }
    //計算位數
    int digit = 0 ;     //計算0有幾個
    //從最前面開始跑 ， 數字是00000...000001...，一遇到不是0的就停止
    for(int i = 0 ; i < 101 ; i++ ){
        if(next_number[i] != 0 ){
            break;
        }
        digit++ ; 
    }
    next_number[0] = 101-digit ;    //最後數字的位數就是101-0的個數，且存進數字陣列的第0格
    return next_number ;            //回傳結果的數字陣列
}

int main(){
    int number ;
    while(cin >> number ){  // 不停輸入數字
        if(number == 0 ){   //如果輸入是0 ， 結束while
            break;
        }
        int* level[number]; //一個2維陣列，每格存一個數字，每個數字用陣列存
        int* first_number = new int[101](); //最一開始的數字 1 
        first_number[100] = 1 ;             //從最後開始放
        first_number[0] = 1;                //陣列的第0個位置放數字的位數
        level[0] = first_number;            //把1放進陣列中
        for(int i = 2 ; i <= number ; i++ ){    //之後的每一個數字利用上一個數字去算出來 
            level[i-1] = mult(level[i-2],i);    // 2! = 1 * 2 , 3! = 2! * 3 以此類推...
        }       
        for(int i = 1 ; i <= number ; i++ ){    //輸出每個階層
            cout << i << "!=" ;                 // 輸出 n!
            for(int j = 101-level[i-1][0] ; j < 101 ; j++  ){   //輸出數字 , 先算出數字的位數 , 因為陣列開101格，且每一個數字的第0個存數字的位數
                cout << level[i-1][j] ;                         //所以從101-level[i-1][0]開始(跳過一堆0)，跑到最後
            }   
            cout << endl;
        }
        cout << endl;
    }
}