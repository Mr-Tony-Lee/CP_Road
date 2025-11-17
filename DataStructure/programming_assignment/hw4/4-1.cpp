/*
    Author : 李承諺(B123040032)
    Date : Sept. 18, 2024 
    PurPose : 以Recursive的方式實作西洋棋騎士(Knight)走完棋盤的順序
*/
#include<iostream>
using namespace std;

//兩個一維陣列紀錄能走的八種方法 K1~K8
int step_x[8] = {-2 , -1 , 1 , 2 ,  2 ,  1 , -1 , -2 }; //這是K1~K8變化的i 
int step_y[8] = { 1 ,  2 , 2 , 1 , -1 , -2 , -2 , -1 }; //這是K1~K8變化的j

//印出二維陣列
void print_map(int**map , int size ){       //傳入二微陣列和陣列的大小
    for(int i = 0 ; i < size ; i++ ){       //迴圈變數
        for(int j = 0 ; j < size ; j++ ){   //迴圈變數
            cout.width(3);  //使輸出的數字都維持3格的長度
            cout.fill(' '); //如果不夠3格會補空格 
            cout << map[i][j] << " " ;  //輸出每個數字
        }
        cout << endl;   //換行
    }
    cout << endl;   //換行
}
//用來看能不能走下一步的函式
int find_method(int** map , int now_i , int now_j , int size , int pre ){   //傳入二微陣列，現在的位置，陣列的大小，跟走過的方法(未走過pre = 0 )
    //有8種走法 
    //如果第一次走，那pre是0，如果已經走過這個走法，pre就會等於走法
    //先判斷會不會超出邊界，後判斷是否已經走過，最後看看是不是已經嘗試過這個走法
         if(now_i-2 >= 0    && now_j+1 < size  && map[now_i-2][now_j+1] == 0 && pre < 1) return 1 ; //如果條件符合，且沒嘗試過第一種方法
    else if(now_i-1 >= 0    && now_j+2 < size  && map[now_i-1][now_j+2] == 0 && pre < 2) return 2 ; //如果條件符合，且沒嘗試過第二種方法
    else if(now_i+1 < size  && now_j+2 < size  && map[now_i+1][now_j+2] == 0 && pre < 3) return 3 ; //如果條件符合，且沒嘗試過第三種方法
    else if(now_i+2 < size  && now_j+1 < size  && map[now_i+2][now_j+1] == 0 && pre < 4) return 4 ; //如果條件符合，且沒嘗試過第四種方法
    else if(now_i+2 < size  && now_j-1 >= 0    && map[now_i+2][now_j-1] == 0 && pre < 5) return 5 ; //如果條件符合，且沒嘗試過第五種方法
    else if(now_i+1 < size  && now_j-2 >= 0    && map[now_i+1][now_j-2] == 0 && pre < 6) return 6 ; //如果條件符合，且沒嘗試過第六種方法
    else if(now_i-1 >= 0    && now_j-2 >= 0    && map[now_i-1][now_j-2] == 0 && pre < 7) return 7 ; //如果條件符合，且沒嘗試過第七種方法
    else if(now_i-2 >= 0    && now_j-1 >= 0    && map[now_i-2][now_j-1] == 0 && pre < 8) return 8 ; //如果條件符合，且沒嘗試過第八種方法
    else return 0 ; //不行走下一步或全部方法都走過一次，回傳0 
}   // end find_method

//檢查是否有解的function 
void check_solution(int** map , int size , int all_step ){  //傳入二維陣列，二維陣列的大小，和總共走多少步
    if(size*size == all_step ){ //如果走過的步數等於size的平方
        print_map(map , size ); // 那就是有解，印出map 
    }
    else cout << "no solution" << endl << endl; //如果沒有解則印出無解
}   // end check_solution 

//跑遞迴的函式，回傳bool值
bool Run_for_Recursive(int ** map , int pre_i, int pre_j , int size ,int now_method , int& now_step ){
    now_step++ ;    //一進到這個function 代表現在踩到下一步的位置 ，所以總步數+1
    int now_step_i = pre_i+step_x[now_method-1];    //把現在的位置記錄下來
    int now_step_j = pre_j+step_y[now_method-1];    //把現在的位置記錄下來
    map[now_step_i][now_step_j] = now_step;         //在現在的位置上填上到目前為止的總步數
    if(now_step == size*size ) return true;         //如果總步數已經跟size*size一樣，則代表全部都走過了，直接回傳true代表走到底了
    int right_method = find_method(map,now_step_i,now_step_j, size ,0); //找出要怎麼走出下一步
    while(right_method != 0){   //如果可以走出下一步，就會進到這個迴圈
        if(Run_for_Recursive(map, now_step_i,now_step_j,size,right_method,now_step) ){  //再進到下一步的遞迴裡，如果遞迴到最後回傳有解，則會直接回傳true
            return true;
        }
        right_method = find_method(map,now_step_i,now_step_j,size,right_method);    //如果走到無解的路，則會回來目前的遞迴，然後再找出其他種走法，繼續嘗試
    }
    map[now_step_i][now_step_j] = 0 ;   //那麼只要這個遞迴沒辦法往下走了，就要往前退一步，先把目前的紀錄刪除
    now_step--;     //總步數-1
    return false ;  //回傳false給上一層遞迴，表示下一步是不能走的
}
//end Run_for_Recursive 

//The function for solving question 
void solve(int n){  //傳進來陣列的大小 
    int** map = new int*[n];  //二維陣列記錄走過的地方 ，此行創建二維陣列
    for(int i = 0 ; i < n ; i++ ){  //迴圈變數 for 二維陣列
        map[i] = new int[n];    //創建二維陣列中的每行一維陣列
        for(int j = 0 ; j < n ; j++ ){  //迴圈變數 for 二維陣列
            map[i][j] = 0 ;     //初始化
        }
    }
    int now_step = 1;   //第一步一定在0,0
    map[0][0] = 1 ;     //第一步一定在0,0
    int first_step_method = find_method(map, 0, 0 , n , 0); //找出第二步的走法
    if(!find_method(map , 0 , 0 , n , 0 )){     //檢查能不能走第二步，如果不行就直接判斷是否有解
        check_solution(map , n , now_step); //判斷是否有解 
        return ;    //直接結束solve function 
    }
    while(first_step_method != 0){  //只要第二步能走，就一直跑，直到遞迴結束或第二步全部可以走的都嘗試過了
        if(Run_for_Recursive(map , 0 , 0 , n ,first_step_method,now_step)){     //如果這個方法可以走到最後，就直接break
            break;
        }
        first_step_method = find_method(map, 0 , 0 , n , first_step_method);    //如果不能走到最後，就再找出下一種走法
    }
    check_solution(map,n,now_step); //檢查是否有解
    //清空已用掉的記憶體
    for(int i = 0 ; i < n ; i++ ){      //迴圈變數 for 刪掉二維陣列中每一行
        delete map[i];  //刪掉二維陣列中每一行
    }
    delete map; //刪掉整個二維陣列
}
//end solve
//主函式
int main(){
    solve(1);   //輸入1
    solve(2);   //輸入2
    solve(3);   //輸入3
    solve(4);   //輸入4
    solve(5);   //輸入5
    solve(6);   //輸入6
    //solve(7);   //輸入7
}