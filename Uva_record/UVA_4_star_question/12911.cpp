#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int N, T, input_set[41];   
    map<ll , int> Sum_pre, Sum_after;   // 兩個map用來記錄前半段窮舉的所有值 跟後半段窮舉的所有值
    while (cin >> N >> T){
        for (int i = 0; i < N; i++) {
            cin >> input_set[i];
        }    
        Sum_pre.clear(); // clear Sum_pre 
        Sum_after.clear();  // clear Sum_after 
        int N_pre = N / 2 , N_after = N - N_pre ; // 把進來的數列拆成兩個部分， 前半部分是 N_pre，後半部分是 N_after 
        if(N_pre == 0 ) N_pre = 1 ;   // 如果 N_pre 是 0 代表 Set 只有一個element ，那就只跑Ca就好了

        for (int i = 1; i < pow(2 , N_pre); i++) {   // 我們要窮舉出所有集合的總和 >> 如果前半部分有Na個，那就是2^Na次方種組合
            ll sum = 0;
            for (int j = 0; j < N_pre; j++)    // 我們現在 i = 5 , 代表我們會用到101 >> 陣列中的第0個 跟陣列中的第2個元素去組成一種集合
                if (i & (1 << j))       // 那我們用 j 跑過整個Na ， 如果 j = 001(第0個) 和 100(第二個)，我們就相加 
                    sum += input_set[j];
            Sum_pre[sum]++;  
        }
        for (int i = 1; i < pow(2 , N_after); i++){    //從1開始是因為沒有000 ( 全部都沒用 ) 
            ll sum = 0;
            for (int j = 0; j < N_after; j++)
                if (i & (1 << j))
                    sum += input_set[N_pre + j];  //陣列的後半段
            Sum_after[sum]++;
        }
        
        // 最後是計算總共有哪些組合可以組起來
        ll count = 0;
        for (auto iter : Sum_pre){
            if (Sum_after.count(T - iter.first)){
                count += 1LL * iter.second * Sum_after[T - iter.first];
            }
        }
        cout << count + Sum_pre[T] + Sum_after[T] << endl;    // 看有沒有剛好等於這個數的集合
    }
}
/*
    這題是要算出一個長度 N 的 Set，用裡面的元素組成的任何set加起來達到Target的所有組合數 
    首先把進來的set 拆成兩個set，然後窮舉出所有的組合，並把每一個組合的值加起來的結果放到一個 map 裡面 ，計算總共出現此數字的次數
    然後把set看成一個binary的形式 0 表示沒用這個數字， 1 則表示有用這個數字 剛好就是 2^n次方 ，
    例如 : Set中有 (2,3,5,7) ， 如果現在 i 迴圈跑到 13 (1101)，則代表現在的subset 是 (2,3,7)
    用這種方式窮舉出所有的組合  所以會需要第二個迴圈跑內部的 1101 如果遇到 1 則把值加到 Sum 裡面
    最後把值存進map中，最後用map.count()去找有沒有其他值在subset 後半段裡面裡面，如果target是20，
    就必須在後半段的set中找到值是 7 的 ， 找到count++ ，最後答案要檢查有沒有剛好等於target的，因為map裡面沒有存0 
*/