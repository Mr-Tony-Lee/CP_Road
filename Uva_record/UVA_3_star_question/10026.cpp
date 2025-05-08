#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> p ; 

bool cmp(p a , p b  ){
    return a.first > b.first || (a.first == b.first && a.second < b.second );
}

int main(){
    int t ;
    cin >> t ;
    int kase = 0 ; 
    while(t--){
        int n ;
        cin >> n ;
        if(kase) cout << endl;
        vector<p> arr ;
        for(int i = 0 ; i < n ; i++ ){
            int f , d ;
            cin >> d >> f ;
            double avg = 1.0*f / d;
            arr.push_back({avg, i+1});
        } 
        sort(arr.begin(),arr.end(), cmp);
        for(int i = 0 ; i < arr.size() ; i++ ){
            if(i == 0 ) cout << arr[i].second ;
            else{
                cout << " " << arr[i].second ;
            }
        }
        cout << endl;
        kase++;
    }
}