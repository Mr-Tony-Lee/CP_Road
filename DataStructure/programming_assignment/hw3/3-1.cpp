/*
    Author : 李承諺(B123040032)
    Date : Sept. 17, 2024 
    PurPose : 以Stack的方式實作西洋棋騎士(Knight)走完棋盤的順序
*/
#include<iostream>  //include iostream 資料庫
#include<iomanip>   //include iomanip資料庫 for 輸出的調整
using namespace std;    //這行用來省略任何內建函式開頭的std:: 

//兩個一維陣列紀錄能走的八種方法 K1~K8
int step_x[8] = {-2 , -1 , 1 , 2 ,  2 ,  1 , -1 , -2 }; //這是K1~K8變化的i 
int step_y[8] = { 1 ,  2 , 2 , 1 , -1 , -2 , -2 , -1 }; //這是K1~K8變化的j
class Node{ //Node的class 
    public:
        Node(int = 0  , int = 0  , int = 0 , Node* next = NULL );   //constructor for class Node 
        int pos_i ; //紀錄i 
        int pos_j ; //紀錄j
        int step ;  //記錄下一步怎麼走
        Node* next ; //紀錄下一個是哪個Node ，方便把Stack串再一起
};
//constructor for Node 
//i 是傳進來的pos_i , j 是傳進來的pos_j , s 是傳進來的step , n 是傳進來的next Node 
Node::Node(int i , int j , int s, Node* n  ) : pos_i(i), pos_j(j), step(s) ,next(n){
}

class Stack{    //Stack的class 
    friend class Node ; //設定friend class ，方便使用Node的private
    public:
        Stack(Node* = NULL);    //constructor 
        void push(int , int , int );    //push function 
        int pop();  // pop function 
        Node* head; // 一個Node的指標儲存head的地址
};

// constructor for Stack 
Stack::Stack(Node* h): head(h) {
}
//Stack的push
void Stack::push (int pre_i , int pre_j , int push_step){   //傳入上一步踩的position，和將要嘗試的方法
    Node* temp = new Node(pre_i , pre_j , push_step);   //先new一個node出來，以push進stack內
    if( head == NULL ){ //如果沒有head
        head = temp ;   //那直接賦值
        return ;        //並跳出function 
    }
    temp->next = head ; //temp的下一個是原本的head
    head = temp ;   //現在head是temp 
}   // end push 

//stack的pop    
int Stack::pop(){
    Node* temp = head ; //先創建一個temp儲存head 
    head = head->next;  //把head移至head的下一個node
    int tried_step = temp->step ;   // 為了要記錄head上次走的step，所以先存起來
    delete temp ;   //把原本的head刪掉
    return tried_step ; //回傳原本head上一步走的方法
}   // end pop 

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

//印出二維陣列
void print_map(int**map , int size ){       //傳入二維陣列和陣列的大小
    for(int i = 0 ; i < size ; i++ ){       //迴圈變數
        for(int j = 0 ; j < size ; j++ ){   //迴圈變數
            cout.width(3);  //使輸出的數字都維持3格的長度
            cout.fill(' '); //如果不夠3格會補空格 
            cout << map[i][j] << " " ;  //輸出每個數字
        }
        cout << endl;   //換行
    }
    cout << endl;   //換行
}   // end print_map

//檢查是否有解的function 
void check_solution(int** map , int size , int all_step ){  //傳入二維陣列，二維陣列的大小，和總共走多少步
    if(size*size == all_step ){ //如果走過的步數等於size的平方
        print_map(map , size ); // 那就是有解，印出map 
    }
    else cout << "no solution" << endl << endl; //如果沒有解則印出無解
}   // end check_solution 

//The function for solving question 
void solve(int n){  //傳進來陣列的大小 
    Stack mystack;  //Stack 
    int** map = new int*[n];  //二維陣列記錄走過的地方 ，此行創建二維陣列
    for(int i = 0 ; i < n ; i++ ){  //迴圈變數 for 二維陣列
        map[i] = new int[n];    //創建二維陣列中的每行一維陣列
        for(int j = 0 ; j < n ; j++ ){  //迴圈變數 for 二維陣列
            map[i][j] = 0 ;     //初始化
        }
    }
    int now_step = 0 ;  //紀錄現在走了幾步
    map[0][0] = ++now_step ;    //第一步 左上角
    int first[n*n+3] = {0};   //用來記錄是否此步是第一次走
    if(!find_method(map , 0 , 0 , n , 0 )){     //檢查能不能走第二步，如果不行就直接判斷是否有解
        check_solution(map , n , now_step); //判斷是否有解 
        return ;    //直接結束solve function 
    }
    else{
        first[1] = find_method(map , 0 , 0 , n , 0 );  //第一步已經走過
        mystack.push(0,0,first[1]);    //如果有的話，把如何走第二步push進stack
    }
    
    while(!(now_step == n*n)){   //只要還沒走滿n*n步，就一直找直到結束
        if(mystack.head == NULL && !(find_method(map ,0 ,0 ,n ,first[now_step+1]))){    //如果已經stack已經空了(表示重走第二步)且沒辦法走出第二步，則直接break
            break;
        }
        else if (mystack.head == NULL ){    //如果stack是空的，則代表現在要走第二步
            first[now_step+1] = find_method(map ,0 ,0 ,n ,first[now_step+1]);   //紀錄這次的走法
            mystack.push(0,0,first[now_step+1]);    //push進stack
            now_step++;        
        }
        else{   //如果stack不為空且有找到走法
            int now_i = mystack.head->pos_i + step_x[mystack.head->step-1]; //先記錄這次要走的位置的i座標
            int now_j = mystack.head->pos_j + step_y[mystack.head->step-1]; //先記錄這次要走的位置的j座標
            map[now_i][now_j] = now_step+1; //在二維陣列的map上做上記號
            if(now_step+1 == n*n) { //如果現在即將要走的是第n*n步，則直接把總步數+1(因為已經走出來了) 並break;
                now_step++;
                break;
            }    
            if(find_method(map ,now_i ,now_j ,n ,first[now_step+1])){     //如果這是第一次走和可以找到走的方法，就push進stack
                first[now_step+1] = find_method(map ,now_i ,now_j ,n ,first[now_step+1]);   //紀錄這次的走法
                mystack.push(now_i,now_j,first[now_step+1]);    //push進stack
                now_step++; //並把總步數+1
            }
            else{   //如果找不到可以走的方法，就代表這一步不能走
                map[now_i][now_j] = 0;  //把已經做好的記號刪掉
                mystack.pop();          //並pop掉上一次的判斷
                now_step--;             //總步數-1( 因為上一步的判斷是錯的)
                first[now_step+2] = 0 ; //並將原本要走的下一步的走法清空 (因為原本要走的下一步是第二步，現在是第0步，那第二步的紀錄不影響這次的結果，所以直接歸零)
            }
        }
        
    }   
    check_solution(map , n , now_step); //判斷現在是否有解
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
    // solve(7);   //輸入7
}