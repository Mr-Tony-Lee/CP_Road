#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int number;
    int count = 1;
    while(cin >> number){
        vector<int> array;
        vector<int> sum ; 
        bool flag = true;
        int seq;
        cin >> seq;
        array.push_back(seq);
        if(seq < 1 ){
            flag = false ;
        }
        for(int i = 0 ; i < number-1 ; i++){
            cin >> seq ;
            if(seq <= array[i]){
                flag = false ;
            }
            array.push_back(seq) ;
            sum.push_back(2*seq);
            for(int j = 0 ; j < (int)array.size()-1 ; j++){
                if(sum.empty()){
                    sum.push_back(seq + array[j]);
                }
                else if (find(sum.begin(),sum.end(),seq + array[j]) == sum.end()){
                    sum.push_back(seq+array[j]);
                }
                else{
                    flag = false ;
                }
            }
        }

        if (flag ){
            cout << "Case #" << count++ << ": It is a B2-Sequence." << endl;
        }
        else{
            cout << "Case #" << count++ << ": It is not a B2-Sequence." << endl;
        }
    }
}
//35ms, 396KB