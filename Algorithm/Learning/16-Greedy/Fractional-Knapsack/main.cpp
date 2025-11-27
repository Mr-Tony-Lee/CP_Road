#include<bits/stdc++.h>
using namespace std;
int capacity ;
vector<int> val ;
vector<int> wt ;
vector<pair<int,int>> arr;

bool cmp(pair<int,int> a, pair<int,int> b ){
    double frac_a = 1.0 * a.first/a.second;
    double frac_b = 1.0 * b.first/b.second;
    return  frac_a > frac_b ;
}

void Greedy(){
    // 根據比例權重由大到小排列
    sort(arr.begin() , arr.end(), cmp);
    double now = 0 ; 
    double ans = 0 ;
    for(int i = 0 ; i < (int)arr.size() ; i++ ){
        if(now == capacity){
            break;
        }
        if(now + arr[i].second <= capacity){
            ans += arr[i].first;
            now += arr[i].second;
        }
        else{
            ans += arr[i].first * ((capacity-now)/arr[i].second);
            break;
        }
    }
    cout << "Greedy -> Maximum value : " << ans << endl;
}

void testcase1(){
    val = {60,100,120};
    wt = {10,20,30};
    capacity = 50 ;
    for(int i = 0 ; i < (int)val.size(); i++ ){
        arr.push_back({val[i],wt[i]});
    }
    Greedy();
}

int main(){
    testcase1();
    
}