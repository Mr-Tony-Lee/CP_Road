#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N ; 
    while(cin >> N && N ){
        int now_x = 1 , now_y = 1 ;
        if(N == 1 ){
            now_x = 1 ;
            now_y = 1 ;    
        }
        else if (N == 2){
            now_x = 1 ;
            now_y = 2 ;    
        }
        else if (N == 3){
            now_x = 2 ;
            now_y = 2 ;    
        }
        else if (N == 4 ){
            now_x = 2 ;
            now_y = 1 ;    
        }
        else {
            vector<int> initial;
            initial.push_back(5);
            int push = 5 ; 
            int now = 2 ;
            //偶數項是從下面往上走
            //奇數項是從上面往右走
            while(push < 2000000000){
                push += 2*now+1;
                initial.push_back(push);
                now++;
            }
            int start_x , start_y ;
            int flag = -1 ; // 如果是0代表從下往上， 1則代表從上往右 // -1 則代表剛好是起始點
            int i ; 
            for(i = 0 ; i < (int)initial.size() ; i++ ){
                if(initial[i+1] > N ){
                    if( i % 2  == 0 ){
                        start_x = 3+i;
                        start_y = 1 ;
                        if(initial[i] != N ) flag = 0 ;
                    }
                    else if (i % 2 == 1 ){
                        start_x = 1 ;
                        start_y = 3+i;
                        if(initial[i] != N ) flag = 1 ;
                    }
                    break;
                }
            }
            if(flag == -1 ){
                now_x = start_x;
                now_y = start_y;
            }
            else if (flag == 0 ){
                int dis = N-initial[i];
                if(dis <= i+2){
                    now_x = start_x;
                    now_y = start_y + dis  ; 
                }
                else{
                    now_y = start_y + i +2;
                    now_x = start_x - (dis - i - 2);
                }
            }
            else{
                int dis = N - initial[i];
                if(dis <= i+2){
                    now_x = start_x + dis  ;
                    now_y = start_y;
                }
                else{
                    now_x = start_x+i+2;
                    now_y = start_y - (dis - i - 2);
                }
            }
        }  
        cout << now_x << " " << now_y << endl;
    }
}
// Online Judge Accepted.
/*
    解題說明 : 
        這一題是尋找規律，找出螞蟻在t秒後所在的位置，可以觀察，一開始起始點在左下角，
        只有前面的1,2,3,4沒有規律，後面，我們要找出轉彎的地方( Ex : 5 , 10 , 17 , 26 ... )，那可以發現之間的差距是 5 , 7 , 9 , .... ( 2*n + 1 )
        然後只要起始點是奇數，那下一個點就是往上走，如果是偶數，那下一個點就是往右走，所以我們先把5,10,17,26,...放進一個array 
        然後如果檢查輸入的數字在哪兩個數之間 (Ex: N = 8 , 在5 , 10 之間)，那就找出5的座標，因為5是奇數，所以5的x座標是 3 + index -> 3
        而y座標一定是 1 ，那如果是偶數的話 x座標一定是 1 ，y 座標則是 3+i ，再來計算要走幾格， 如果N = 8 ，那我們要走3格 -> dis = 3 
        ，那再來檢查 dis 有沒有大於 (10-1-5) /2 也剛好等於 index + 2 ，如果沒有就直接把dis加上y的值，如果有就x 扣掉 dis-(index+2)  y則是加 index + 2 
        最後就是答案。
*/ 