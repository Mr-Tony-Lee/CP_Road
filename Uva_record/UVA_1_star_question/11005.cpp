#include<iostream>
#include<string>
#include<cmath>
#include<vector>    
#include<algorithm>
using namespace std;

long long int  trans(long long int number , int b , int* cost ){
    long long int ans = 0;
    do{
        int remainder = number % b;
        number /= b ;
        ans += cost[remainder];
    }while( number > 0 );
    return ans ;
}


int main(){
    int times ;
    cin >> times ;
    int count = 1 ; 
    while(times--){
        int cost[36] = {0};
        string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0 ; i < 36 ; i++  ){
            cin >> cost[i] ;
        }
        int number_to_input ;
        cin >> number_to_input ;
        cout << "Case " << count++ << ":" << endl;
        while(number_to_input--){
            long long int number;
            cin >> number ;
            vector<int> base ;
            vector<int> min_cost ;
            long long int record_min = trans(number , 2 , cost );
            for(int i = 2 ; i <= 36 ; i++ ){
                long long int sum = trans(number , i , cost );
                base.push_back(i);
                min_cost.push_back(sum);
                record_min = min(record_min , sum);
            }
            cout << "Cheapest base(s) for number " << number << ":";
            for(int i = 0 ; i < (int)min_cost.size() ; i++ ){
                if(min_cost[i] == record_min){
                    cout << " " << base[i] ;
                }
            }
            cout << endl;
        }
        if(times != 0 ){
            cout << endl;
        }
    }   
}
//UVA online judge 0.000s