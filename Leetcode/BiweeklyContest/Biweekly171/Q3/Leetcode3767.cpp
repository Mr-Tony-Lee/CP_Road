#include<bits/stdc++.h>
using namespace std;

bool cmp (pair<int,int> a , pair<int,int> b ){
    return a.first-a.second > b.first-b.second ;
}
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int N = technique1.size();
        pair<int,int> arr[N];
        for(int i = 0 ; i < N ; i++ ){
            arr[i] = {technique1[i],technique2[i]};
        }
        sort(arr,arr+N,cmp);
        long long ans = 0 ; 
        for(int i = 0 ; i < k ; i++ ){
            ans += arr[i].first;
        }
        for(int i = k ; i < N ; i++ ){
            ans += max(arr[i].first, arr[i].second);
        }
        return ans ;
    }
};