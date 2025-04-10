#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string *fib = new string[5001];
    fib[0] = ("0");
    fib[1] = ("1");
    fib[2] = ("1");
    int now = 2;
    while( now <= 5000 ){
        string ans = fib[now-1] ;
        bool flag = false ;
        int i ;
        for( i = 0 ; i < (int)fib[now-2].size() ; i++ ){
            int digit = flag ? (fib[now-2][i]-'0') + (ans[i] -'0') + 1 : (fib[now-2][i]-'0') + (ans[i] -'0');
            ans[i] = digit % 10 + '0';
            if(digit >= 10 ){
                flag = true;
            }
            else{
                flag = false;
            }
        }
        while(flag){
            if(ans.size() == fib[now-2].size()){
                ans.push_back('1');
                break;
            }
            else{
                int digit = (ans[i]-'0') + 1;
                if( digit == 10 ){
                    flag = true ;
                    ans[i] = '0';
                    i++;
                    continue;
                }
                else{
                    ans[i] = digit + '0';
                    break;
                }
            }
        }
        fib[now] = ans;
        now++;
    }
    int n ;
    while(cin >> n ){
        cout << "The Fibonacci number for " << n << " is " ;
        for(int i = fib[n].size()-1 ; i >= 0 ; i-- ){
            cout << fib[n][i];
        }
        cout << endl;
    }
}
//Accepted by zerojudge 12ms, 3.1MB.