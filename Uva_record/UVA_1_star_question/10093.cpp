#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
    while(getline(cin,input) ){
        bool flag = false ;
        int ans = 1;    //這樣 0 or 1 進去都是2 
        int sum  = 0 ;  //如果R可被N-1整除 那 R的每個數字的和可以被N-1整除
        for(int i = 0 ; i < (int)input.size(); i++){
            int base = 0;
            if(input[i] >= '0' && input[i] <= '9'){
                base = input[i] - '0' ;
            }
            else if ( input[i] >= 'A' && input[i] <= 'Z'){
                base = input[i] - 'A' + 10 ;
            }
            else if ( input[i] >= 'a' && input[i] <= 'z'){
                base = input[i] - 'a' + 36;
            }
            else{
                continue;
            }
            if(base >= 2 ) ans =  max( ans , base );
            sum += base ;
        }
        for(int i = ans ; i < 62 ; i++ ){
            if(sum % i == 0 ){
                cout << i+1 << endl;
                flag = true;
                break;
            }
            
        }
        if(!flag){
            cout << "such number is impossible!" << endl;
        }
    }
}
// 4ms, 324KB