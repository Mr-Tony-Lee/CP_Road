#include<bits/stdc++.h>
using namespace std;

int main(){
    
    while(1){
        string input;
        vector<string> arr ;
        while(cin >> input ){
            
            arr.push_back(input);
        }
        for(int i = 0 ; i < arr.size() ; i++ ){
            cout << arr[i] << endl;
        }
    }
}
// 不寫