#include<iostream>
#include<vector>
using namespace std;


int main(){
    int times;
    cin >> times ;
    int Case = 1 ;
    while ( times-- ){
        int x1 , y1 , x2 , y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;
        long long int count = 0 ;
        long long int sum1 = x1 + y1;
        long long int sum2 = x2 + y2 ;
        for(int i = sum1+1 ; i < sum2 ; i++ ){  //中間
            count += i+1 ; 
        }
        if(sum1 == sum2 ){
            count = x2-x1;
        }
        if(sum1 != sum2 ) count += y1 ; 
        if(sum1 != sum2 ) count += x2+1;
        cout << "Case " << Case++ << ": " << count << endl;
    }
}
//2ms, 312KB