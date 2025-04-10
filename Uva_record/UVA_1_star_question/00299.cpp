#include<iostream>
#include<vector>
using namespace std;



int main(){
    int times;
    cin >> times ;
    while(times-- ){
        int number ;
        vector<int> train;
        cin >> number ;
        for(int i = 0 ; i < number ; i++ ){
            int x ;
            cin >> x ;
            train.push_back(x);
        }              
        int count = 0 ;
        for(int i = 0 ; i < (int)train.size() - 1 ; i++){
            for(int j = 0 ; j < (int) train.size()-1 ; j++ ){
                if(train[j] > train[j+1]){
                    swap(train[j],train[j+1]);
                    count++ ; 
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps."<< endl;
    }
}
//2ms, 344KB