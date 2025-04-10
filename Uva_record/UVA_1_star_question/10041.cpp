#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    while(times--){
        int number ;
        cin >> number ;
        vector<int> array;
        for(int i = 0 ; i < number ; i++ ){
            int input ;
            cin >> input ; 
            array.push_back(input);
        }
        sort(array.begin(), array.end());
        int ans = 0 ;
        for(int i = 0 ; i < number ; i++ ){
            int sum = 0;
            for(int j = 0 ; j < number ; j++ ){
                sum += abs(array[j]- array[i]);
            }
            if( i == 0 ){
                ans = sum ;
            }
            else{
                if(sum > ans){
                    break;
                }
                else{
                    ans = sum ; 
                }
            }
        }
        cout << ans << endl;
    }
}
//2.1s 321KB