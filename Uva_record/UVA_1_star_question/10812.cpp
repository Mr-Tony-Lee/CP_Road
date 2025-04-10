#include<iostream>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    while(times--){
        int sum , dis ;
        cin >> sum >> dis ;
        bool flag = false ;
        for(int i = 0 ; i <= sum ; i++){
            int j = sum-i;
            if(abs(i-j) == dis ){
                cout << max(i,j) << " " << min(i,j) << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "impossible" <<endl;
        }
    }
}
//2ms, 284KB