#include<bits/stdc++.h>
using namespace std;
#define int long long 

int LIS(vector<int>& s ){
    if(s.size() == 0 ) return 0 ;

    int pos[s.size()] = {};
    vector<int> ans ; // the answer of longest increasing sequence 
    unordered_map<int,int> arr ; // 每個數值 的 位置 -> arr[value] = index of longest increasing sequence 
    vector<int> temp_lis;   // 用來暫存 longest increasing sequence ， 但不一定是正解，只是其中一種解，或不是解，但長度一定是正解的長度
    pos[0] = 1 ;
    temp_lis.push_back(s[0]);   // 先 push 第0個進去 確保迴圈不會出錯 
    arr[s[0]] = 1; 

    for(int i = 1 ; i < s.size() ; i++ ){   
        if(s[i] <= temp_lis.back() ){   // 如果比現在temp_lis 的最後一個元素小 
            arr[s[i]] = arr[*(lower_bound(temp_lis.begin() , temp_lis.end() , s[i]))] ; // 那我們要找到他應該在的位置
            *(lower_bound(temp_lis.begin() , temp_lis.end() , s[i])) = s[i];    // 然後把現在的temp_lis 的那個位置改成 s[i]
            pos[i] = arr[s[i]]; // 然後把 他現在的 index 存進去 position 裡面
        }    
        else{   // 如果比現在最後一個元素大
            temp_lis.push_back(s[i]);       // 那就直接放進去 
            pos[i] = temp_lis.size();   // 然後位置就是 temp_lis 的大小
            arr[s[i]] = temp_lis.size();    // 然後把現在的 index 存進去 position 
        }
    }
    
    int count = temp_lis.size();    // 最後從最後面往前找 ， 找到最後出線的 LIS ， 如果要找到最先出現的，就從前面往後找
    for(int i = s.size() ; i >= 0 && count > 0 ; i--){  
        if(pos[i] == count ){
            ans.push_back(s[i]);
            count--;
        }
    }
    
    cout << ans.size() << endl;
    cout << "-" << endl;
    for(int i = ans.size()-1 ; i >= 0  ; i-- ){
        cout << ans[i] << endl;
    }
    return ans.size();
}


int32_t main(){
    cin.tie(0) ;
    cout.tie(0) ; 
    ios::sync_with_stdio(0);
    vector<int> arr ;
    int n ; 
    while(cin >> n){
        arr.push_back(n);
    }
    LIS(arr);
}
/*
    解題說明 : 本題要找到 Longest Increasing Sequence (LIS)
    那我的解法就是找出每個數字應該在的位置，然後最後從後面看回來，一個一個選到答案裡面
    假設 input 是  {-7 , 10, 9 , 2 , 3 , 8 , 8 , 1 } 
    那 pos 的對應是 {1 , 2 , 2 , 2 , 3 , 4 , 4 , 2 }
    然後從後面選回來 依序是 8 , 3 , 2 , -7 ， 最後 reverse ， 時間複雜度是 O(n log n )
    此題不能使用 dp 找出所有的 LIS ， 複雜度是 O( n^2 ) 會 TLE 
*/


// 以下為 Wrong Answer , 和 TLE 版本 
// int32_t main(){
//     vector<int> arr ;
//     int n ; 
//     while(cin >> n && n != -1 ){
//         arr.push_back(n);
//     }
//     vector<int> new_max ; 
//     vector<int> ans ;
//     for(int j = 0 ; j < arr.size() ; j++ ){
//         new_max.push_back(arr[0]);
//         for(int i = j+1 ; i < arr.size() ; i++ ){
//             if(new_max[new_max.size()-1] >= arr[i] ){
//                 if(new_max.size() < 2 || arr[i] > new_max[new_max.size()-2]){
//                     new_max[new_max.size()-1] = arr[i];
//                 }
//             }
//             else if (arr[i] > new_max[new_max.size()-1]){
//                 new_max.push_back(arr[i]);
//             }
//         }    
//         if(new_max.size() > ans.size() ){
//             ans = new_max ; 
//         }
//         new_max.clear();
//     }
    
//     cout << ans.size() << endl;
//     cout << "-" << endl;
//     for(int i = 0 ; i < ans.size(); i++ ){
//         cout << ans[i] << endl ;
//     }
// }
// 1 3 2 2 4 0 
// 3 2 1 5 2 6 7 
// -7 10 9 2 3 8 8 6

