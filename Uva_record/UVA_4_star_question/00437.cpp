#include<bits/stdc++.h>
using namespace std;
#define int long long

class box{
    public:
        box(int = 0 ,int = 0  , int = 0  );
        int x ; // 長跟寬小的那個
        int y ; // 長跟寬大的那個
        int z ;
    friend bool operator < (box& , box& );
};
box::box(int x1  ,int y1  , int z1 ):x(x1),y(y1),z(z1){}

bool operator < (box& a , box& b ){
    if(a.x != b.x ){
        return a.x < b.x ;
    }
    else{
        return a.y < b.y ; 
    }
}

int32_t main(){
    int n ; 
    int count = 1 ; 
    while( cin >> n && n ){
        int ans = 0; 
        vector<box> arr ; 
        for(int i = 0 ; i < n ; i++){
            int x , y , z ;
            cin >> x >> y >> z ;
            arr.push_back(box(min(x,y),max(x,y),z));
            arr.push_back(box(min(x,z),max(x,z),y));
            arr.push_back(box(min(z,y),max(z,y),x));
        }
        sort(arr.begin(), arr.end());
        int record_max[90] = {}; // 最多 30 * 3 個積木 , 紀錄前面幾個積木疊起來的最大值
        for(int i = 0 ; i < (int)arr.size() ; i++ ){
            record_max[i] += arr[i].z ; 
            for(int j = i+1 ; j < (int)arr.size() ; j++ ){
                if(arr[i].x < arr[j].x && arr[i].y < arr[j].y){
                    record_max[j] = max(record_max[i] , record_max[j]);
                }
            }
            ans = max(ans , record_max[i]);
        }
        cout << "Case " << count++ << ": maximum height = " << ans << endl;
    }
}

/*
    解題說明 :  這題是疊方塊的問題，越下面的方塊的長、寬要越大，且任一個方塊可以任意翻轉，所以一開始先開一個vector放所有可以用的方塊，
    那輸入的時候會給3個值(x,y,z) 那因為可以翻轉，所以每個都要append 3種尺寸的方塊進去，所以最多有90個方塊可以用
    那再來，使用另一個 vector 存最高高度， 那每個index上面可能還有前面的方塊，像 record_max[0] 只有一個
    record_max[1]可能有1個，可能有兩個，要看最大高度， 最後 dp 出最大高度是多少就是答案
*/