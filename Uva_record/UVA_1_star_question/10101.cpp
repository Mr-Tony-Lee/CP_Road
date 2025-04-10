#include<iostream>
#include<string>
using namespace std;

void solve(unsigned long long int input , int& count ){
    cout << "   " << count++ << ". " ;
    if(input == 0 ){
        cout << 0 << endl;
        return ;
    }

    int array[4] = {10000000,100000,1000,100};
    unsigned long long int  ans[4] = {0};
    unsigned long long int ans_2[4] = {0};
    bool state = false ;
    string output_string[4] = {"kuti" , "lakh" , "hajar" , "shata" };
    for(int i = 0 ; i < 4 ; i++ ){
        ans[i] = input / array[i] ;
        input -= ans[i] * array[i];
    }
    if(ans[0] >= 100 ){
        state = true ;
        for(int i = 0 ; i < 4 ; i++ ){
            ans_2[i] = ans[0] / array[i] ;
            ans[0] -= ans_2[i] * array[i] ;
        }
    }
    
    for(int i = 0 ; i < 4 ; i++ ){
        if(ans_2[i] > 0 ){
            cout << ans_2[i] << " " << output_string[i] << " " ;
        }
    }
    for(int i = 0 ; i < 4 ; i++ ){
        if(state && ans[i] == 0 && i == 0 ){
            cout << output_string[i] << " " ;
        }
        else if(ans[i] > 0 ){
            cout << ans[i] << " " << output_string[i] << " " ;
        }
    }
    if( input > 0 ) cout << input << endl;
    else{
        cout << endl;
    }
}

int main(){
    unsigned long long int number ;
    int count = 1 ;
    while(cin >> number){
       solve(number, count);
    }
}
//62ms, 284KB