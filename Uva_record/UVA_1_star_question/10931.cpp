#include<iostream>
#include<vector>
using namespace std;

int trans_de_to_bi(long long int number){
    cout << "The parity of ";
    vector<long long int> bi;
    bi.push_back(1);
    bi.push_back(2);
    int count = 0 ; 
    if(number == 1 ){
        cout << 1;
        count ++ ;
        cout << " is " ;
        return count;
    }
    int index = 1 ;
    while(bi[index] * 2 <= number ){
        bi.push_back(bi[index]*2);
        index++;
    }
    for(int i = (int) bi.size()-1 ; i >= 0 ; i--){
        if(number >= bi[i]){
            number -= bi[i];
            cout << 1 ;
            count++;
        }
        else{
            cout << 0 ;
        }
    }
    cout << " is ";
    return count;
}

int main(){
    long long int number ;
    while( cin >> number ){
        if(number == 0 ){
            break;
        }
        cout << trans_de_to_bi(number) << " (mod 2)." << endl;
    }
}
//7ms, 316KB