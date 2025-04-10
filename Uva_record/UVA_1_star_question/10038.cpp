#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int times;
    while(cin >> times){
        vector<int> origin_number;
        for(int i = 0 ; i < times ; i++ ){
            int number;
            cin >> number;
            origin_number.push_back(number);
        }
        vector<int> distance;
        for(int i = 0 ; i < (int)origin_number.size()-1 ; i++ ){
            distance.push_back(abs(origin_number[i]-origin_number[i+1]));
        }
        sort(distance.begin(), distance.end());
        bool flag = true;
        for(int i = 0 ; i < (int)distance.size() ; i++){
            if(distance[i] != i+1 ){
                flag = false ;
                break;
            }
        }
        if(flag){
            cout << "Jolly" << endl;
        }
        else{
            cout << "Not jolly" << endl;
        }
    }
}
//16ms, 368KB