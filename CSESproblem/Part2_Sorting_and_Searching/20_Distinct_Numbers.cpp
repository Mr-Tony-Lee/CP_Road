#include<iostream>
#include<map>
using namespace std;



int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    map<int,int> record;
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++ ){
        int x ;
        cin >> x ;
        record[x] ++ ;
    }
    cout << record.size() << endl;
}
