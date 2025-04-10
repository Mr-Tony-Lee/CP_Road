#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
    int number ;
    while(cin >> number ){
        vector<int> array_x ;
        for(int i = 0 ; i < number ; i++ ){
            int x ; 
            cin >> x;
            array_x.push_back(x);
        }
        sort(array_x.begin() , array_x.end());
        int middle_1 , middle_2;
        int size_of_array = (int) array_x.size();
        if( size_of_array % 2 == 0 ){
            middle_1 = array_x[size_of_array/2-1];
            middle_2 = array_x[size_of_array/2];
        }
        else{
            middle_1 = array_x[size_of_array/2];
            middle_2 = array_x[size_of_array/2];
        }
        cout << middle_1 << " " ;
        
        int ans = 0 ;
        int min_sum = 0 ; 
        if(middle_1 != middle_2){
            ans = middle_2-middle_1 + 1 ; 
            for(int i = 0 ; i < size_of_array ; i++ ){
                if(array_x[i] == middle_1 || array_x[i] == middle_2 ){
                    min_sum++;
                }
            }
        }
        else {
            ans = 1 ;
            for(int i = 0 ; i < size_of_array ; i++ ){
                if(array_x[i] == middle_1 || array_x[i] == middle_2 ){
                    min_sum++;
                }
            }
        }
        cout << min_sum << " " ;
        cout << ans << endl;
    }
}
//45ms, 1.2MB1