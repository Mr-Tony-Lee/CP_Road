#include<bits/stdc++.h>
using namespace std;

int binary_automaton[8] , int_state[33] , ans[40];

// 用枚舉找出生成一個環的所有可能性，只要是一個環，就成功了 -> reachable 

bool dfs(int now, int size ){
    if( now >= size ){
        return ((ans[0] == ans[size]) && (ans[1] == ans[size+1])) ; 
        // 想像 如果最前面的兩個 left 跟 middle 可以生成後面的 ans 
        // 如果最後的兩個 跟 最前面的兩個一樣， 代表最後的兩個可以生成同樣的環
        // 只要是一個環，那就成功了 !! 
    }
    for(int i = 0 ; i < 8 ; i++ ){  // 
        if((int_state[now] == binary_automaton[i]) && (now == 0 || ((ans[now]*4 + ans[now+1] * 2 ) == ( i & 6 ))) ){    // 去枚舉每一種可能 state 對應到的 automaton 可能有多個 
            // 上面的 if 如果現在的state 跟 automaton的結果有對到，並且 前兩個 的 left 跟 middle 跟現在的 i 一樣 
            if(now == 0 ){
                ans[now] = ((i & 4) > 0) ;
                ans[now+1] = ((i & 2) > 0) ;
            }
            ans[now+2] = ((i & 1) > 0); 
            // 前一個的 middle 跟 right 是這一個的 left 跟 middle 
            // 用這個left 跟 middle 去猜 right 是多少 -> 枚舉
            if(dfs(now+1,size)){
                return true;
            }
        }   
    }
    return false;
}

int main(){
    int automaton , N ;
    string state ;
    while( cin >> automaton >> N >> state){
        for(int i = 0 ; i < 8 ; i++ ){
            binary_automaton[i] = (automaton & 1) ;
            automaton >>= 1 ;
        }
        for(int i = 0 ; i < N ; i++ ){
            int_state[i] = state[i]-'0';
        }
        if(dfs(0,N)){
            cout << "REACHABLE" << endl;
        }
        else{
            cout << "GARDEN OF EDEN" << endl;
        }
    }   
}
// 題目真的很難懂
// 參考資料 : https://blog.csdn.net/mobius_strip/article/details/51123015
// 參考資料 : https://mypaper.pchome.com.tw/zerojudge/post/1324309153