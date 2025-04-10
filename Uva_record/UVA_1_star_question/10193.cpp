#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int GCD(int a, int b){
    if(b==0){
        return a;
    }else if(a==0){
        return b;
    }else{
        if(a>b){
            return GCD(a%b,b);
        }else if(b>a){
            return GCD(a,b%a);
        }else{
            return a;  //a、b相等
        }
    }
}

int main(){
    int times ;
    cin >> times ;
    cin.ignore();
    int pair = 1 ;
    while(times--){
        string s1 , s2 ;
        getline(cin , s1);
        getline(cin , s2);
        long long int sum1 = 0  , sum2 = 0  ;
        int count = 0 ; 
        for(int i = (int)s1.size()-1 ; i >= 0;  i--  ){
            if(s1[i] == '1'){
                sum1 += pow(2,count);
            }
            count++;
        }
        count = 0 ;
        for(int i = (int)s2.size()-1 ; i >= 0;  i--  ){
            if(s2[i] == '1'){
                sum2 += pow(2,count);
            }
            count++;
        }
        
        
        if(GCD(sum1,sum2) != 1 ){
            cout << "Pair #" << pair++ << ": All you need is love! " << endl;
        }
        else{
            cout << "Pair #" << pair++ << ": Love is not all you need! " << endl;
        }
    }
}
//3ms, 328KB