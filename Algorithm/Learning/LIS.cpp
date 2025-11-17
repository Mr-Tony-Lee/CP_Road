#include<bits/stdc++.h>
using namespace std;
#define int long long 



int LIS(vector<int>& s ){
    if(s.size() == 0 ) return 0 ;

    vector<int>pos(s.size() , -1);
    vector<int> ans ; // longest increasing sequence 
    unordered_map<int,int> arr ; 
    pos[0] = 1 ;
    vector<int> temp_lis;
    temp_lis.push_back(s[0]);
    arr[s[0]] = 1; 
    for(int i = 1 ; i < s.size() ; i++ ){
        if(s[i] <= temp_lis.back() ){
            arr[s[i]] = arr[*(lower_bound(temp_lis.begin() , temp_lis.end() , s[i]))] ; 
            *(lower_bound(temp_lis.begin() , temp_lis.end() , s[i])) = s[i];
            pos[i] = arr[s[i]];
        }    
        else{
            temp_lis.push_back(s[i]);
            pos[i] = temp_lis.size();
            arr[s[i]] = temp_lis.size();
        }
    }
    int count = temp_lis.size();

    for(int i = pos.size() ; i >= 0 ; i--){
        if(pos[i] == count ){
            ans.push_back(s[i]);
            count--;
        }
    }
    
    
    for(int i = ans.size()-1 ; i >= 0  ; i-- ){
        cout << ans[i] << " ";
    }
    cout << endl;
    return ans.size();
}

int32_t main(){
    vector<int> s = {-7 , 10, 9 , 2 , 3 , 8 , 8 , 1 };
    cout << LIS(s) << endl;
}