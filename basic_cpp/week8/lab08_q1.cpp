#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k ;
    vector<int> ans(5,0);
    cin >> k ;
    for(int i = 0 ; i < 5 ; i++) {
        cin >> ans[(i+k)%5];
    }
    for(int i = 0 ; i < 5 ; i++ ){
        cout << ans[i] << " ";
    }
    cout << endl;
}
