#include<iostream>
#include<vector>
using namespace std;

int main(){
    int times ;
    cin >> times;
    cin.ignore();
    int count = 0 ; 
    while(times--){
        count++;
        int ans = -1; 
        vector<vector<string>> all;
        for(int i = 0 ; i < 100 ; i++ ){
            vector<string> every;
            all.push_back(every);
        }
        for(int i = 0 ; i < 10 ; i++ ){
            int number ;
            string input ; 
            cin >> input >> number ;
            cin.ignore();
            all[number-1].push_back(input);
            ans = max(ans,number-1);
        }
        cout << "Case #" << count << ":" << endl;
        for(int i = 0 ; i < (int)all[ans].size() ; i++ ){
            cout << all[ans][i] << endl;
        }
    }
}