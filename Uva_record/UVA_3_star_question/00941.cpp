#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define int long long

int32_t main(){
    int times; 
    cin >> times;
    while(times--){
        cin.ignore();
        string input ;
        getline(cin , input);
        sort(input.begin(),input.end());

        int factorial[21];
        factorial[0] = 1 ;
        factorial[1] = 1 ;
        for(int i = 2 ; i <= 20 ; i++ ){
            factorial[i] = i * factorial[i-1];
        }
        
        int n ; 
        cin >> n ;
        for(int i = (int)input.size()-1 ; i >= 0 ; i-- ){
            int index = n / factorial[i];
            n %= factorial[i];
            cout << input[index];
            input.erase(input.begin()+index);
        }
        cout << endl;
    }
}

/*
    解題說明 : 
        本題要找出排列組合中的第n個組合是甚麼，Ex : abc 可以排成 abc acd bac bca cab cba -> 如果 n = 5， 那答案是 cba
        那本題如果用爆解的，會TLE，所以我們要使用算的，以上的組合看成 第一個字母 + 後面兩個字母的組合 ，也就是一開始 abc 的index 是 012 
        那可以發現，每一個都是2個，開頭是a的有2個組合，開頭是b的有兩個組合...，也就是 3 * 2! ，所以可以把 N 除以 2! ，找出開頭的字母，
        那接下來把那個字母從string裡面刪掉，然後取 N / 2! 的餘數 ，找出下一個字母，以此類推。 
*/