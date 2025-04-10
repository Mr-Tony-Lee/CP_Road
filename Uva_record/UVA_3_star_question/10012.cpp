#include<bits/stdc++.h>
using namespace std;
#define int long long 
double circle[9] , ans , tmp , X[9];
int n ; 

double my_abs(double x ){
    if(x < 0) return -x ;
    return x ;
}

double get_dis(int c1 , int c2 ){
    double a = circle[c1] + circle[c2];
    double b = my_abs(circle[c1]-circle[c2]);
    return sqrt(a*a - b*b);
}
// 與第 i 個圓相切一定是 x 座標最遠的那個
void solve(){
    do{
        memset(X,-1,sizeof(X));
        X[1] = circle[1];   // 先放好一個圓
        tmp = 1 ;
        for(int i = 2;  i <= n ; i++ ){
            double x_ = circle[i];
            for(int j = 1 ; j < i ; j++ ){  // 找最大的 ， 也就是將下一個要放的圓慢慢往右移，那相切的一定是最遠的那個 
                x_ = max(x_, X[j] + get_dis(i,j));
                X[i] = x_;
            }
        }
        for(int i = 1 ; i <= n ; i++ ){ // 找出紙箱長度 -> X[i]是第 i 個圓的x座標 + 半徑 就是最右邊的邊界
            tmp = max(tmp,X[i]+circle[i]);
        }
        ans = min(ans,tmp);
    }while(next_permutation(circle+1 , circle+1+n));
}

int32_t main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(0);
    int t ;
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 1 ; i <= n ; i++ ){
            cin >> circle[i] ;
        }
        ans = 99999999; // 要夠大，不然會 WA
        sort(circle+1 , circle+1+n);
        solve();
        cout << fixed << setprecision(3) << ans << endl; 
    }
}

// 參考資料 : https://blog.csdn.net/tengfei461807914/article/details/53143336
// 總共有 3 種情況， 
// 第一種 : 如果圓的半徑相差不大，直接排序就好了
// 第二種 : 有半徑相差較大的圓，那小的圓可以直接塞到兩個圓的縫隙當中
// 第三種 : 有半徑相差較大的圓，小的圓靠牆，大的圓也靠牆
// 考慮三種情況，考慮用 greedy + 暴力解 解題，枚舉圓的排列順序，盡量把圓貼到他最左側的圓環。
// 且由於本題是給半徑，不是座標，所以把之前排好的圓用座標表示出來
// 每個圓的 y 軸是半徑， x 軸則是 ( 前面的圓的橫坐標 + 本身到前一個圓的圓新的水平距離 ) 
// X[] 的 array ，紀錄圓的橫坐標 ( 第 i 個圓的擺放位置 )
