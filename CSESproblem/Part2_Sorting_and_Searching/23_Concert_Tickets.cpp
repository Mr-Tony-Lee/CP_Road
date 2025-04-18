// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main(){
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(false);
//     int n , m ;
//     cin >> n >> m ;
//     vector<int> h;
//     for(int i = 0 ; i < n ; i++ ){
//         int hn;
//         cin >> hn;
//         h.push_back(hn);
//     }
//     sort(h.begin(), h.end());
//     for(int i = 0 ; i < m ; i++ ){
//         int tm ; 
//         cin >> tm ;
//         int low = 0 , high = h.size()-1;
//         int max_num= 0  , max_index;
//         while( low <= high ){
//             int middle = ( low+high ) / 2 ;
//             if(h[middle] == tm){
//                 max_num = h[middle];
//                 max_index = middle;
//                 break;
//             }
//             else if ( h[middle] > tm){
//                 high = middle-1;
//             }
//             else{
//                 low = middle + 1;
//             }
//         }
//         if(max_num != 0){
//             cout << max_num << endl;
//             h.erase(h.begin()+max_index);
//         }
//         else{
//             if(low != 0 ){
//                 cout << h[low-1] << endl;
//                 h.erase(h.begin()+low-1);
//             }
//             else{
//                 cout << -1 << endl;
//             }
//         }
//     }    
// }
// TLE ...

#include<iostream>
#include<set>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n , m ;
    cin >> n >> m ;
    multiset<int> h ;   // multiset會儲存重複的元素並排列。 插入，刪除都是log n 
    for(int i = 0 ; i < n ; i++ ){
        int hn;
        cin >> hn;
        h.insert(hn);
    }
    for(int i = 0 ; i < m ; i++ ){
        int t ;
        cin >> t ;
        auto iter = h.upper_bound(t);   // upper_bound會找出 剛好大於t的那一個數字的iterator 
        if(iter == h.begin()){  //如果upper_bound是 begin() 就代表根本沒有比他小的
            cout << -1 << endl;
        }
        else{
            cout << *(--iter) << endl;  //要輸出前一個 所以是輸出*(--iter)
            h.erase(iter);  //因為已經-- ， 所以可以刪掉iter
        }
    }
}
