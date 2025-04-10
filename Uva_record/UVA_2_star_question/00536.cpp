#include<bits/stdc++.h>
using namespace std;

// pre[preI] 是目前的根節點（因為前序遍歷的第一個字元是根）
// 在中序遍歷中 找到這個根節點的位置 i，可以將中序的數列 分成左子樹和右子樹
// 左子樹：inLow ~ i-1
// 右子樹：i+1 ~ inHigh
int topos(string pre , string in , int preI , int inLow , int inHigh  ){
    if( inLow >= inHigh ) return preI;
    for(int i = inLow ; i < inHigh ; i++ ){
        if(in[i] == pre[preI]){
            preI = topos(pre, in , preI+1 , inLow , i );    // 從 preorder (左子樹的下一個) 的位置， 區間長度是 inLow ~ i (左子樹)
            preI = topos(pre, in , preI , i+1 , inHigh);    // 回來的時候 preI (就會在右子樹的下一個) 的位置，而inorder的區間長度是 i+1 ~ inHigh
            cout << in[i] ; // 最後拆分到最小的區間後，印出 in[i] 
            break;
        }
    }
    return preI;
}
/*
    由於前序是(中,左,右)，而中序是(左,中,右)，故利用前序前頭遇到的字可以知道在中序中這個字會將以它為root的子樹左右兩側分割開來，
    藉以知道以此字為root的左右子樹的區段為何，利用這樣的切割即可輸出成後序的格式。
*/
int main(){
    string pre , in ;
    while(cin >> pre >> in ){
        topos(pre , in , 0 , 0 , in.size());
        cout << endl;
    }
    return 0 ;
}
// 參考資料 : https://knightzone.studio/2016/04/28/3132/uva%EF%BC%9A536%EF%BC%8Dtree-recovery/