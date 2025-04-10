#include<iostream>
#include<vector>
using namespace std;

int main(){
    int times;
    cin >> times ;
    while(times--){
        vector<int> fib;
        vector<int> ans ;
        fib.push_back(1);
        fib.push_back(1);
        int index = 1 ;
        int number ;
        cin >> number;
        while(fib[index] + fib[index-1] <= number){
            fib.push_back(fib[index]+fib[index-1]);
            index++;
        }
        cout << number << " = " ;
        for(int i = (int)fib.size()-1 ; i > 0  ; i-- ){
            if(number >= fib[i]){
                ans.push_back(1);
                number -= fib[i];
            }
            else{
                ans.push_back(0);
            }
        }
        for(int i = 0 ; i < (int)ans.size() ; i++ ){
            cout << ans[i] ;
        }
        cout << " (fib)" << endl;
    }   
}
//5ms, 328KB