#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int trans_he_to_de(int number){
    int sum = 0 ; 
    int power = 0; 
    while(number > 0 ){
        sum += (number%10)*pow(16,power);
        power++;
        number/=10;
    }
    return sum;
}

int trans_de_to_bi (int number){
    vector<int> ans ;
    vector<int> bi;
    bi.push_back(1);
    bi.push_back(2);
    int index = 1;
    while(bi[index]*2 <= number){
        bi.push_back(bi[index]*2);
        index++;
    }
    int count = 0 ;
    for(int i = (int)bi.size()-1 ; i >= 0  ; i--){
        if(number >= bi[i]){
            number -= bi[i];
            ans.push_back(1);
            count++;
        }
        else{
            ans.push_back(0);
        }
    }
    return count ;
}

int main(){
    int times;
    cin >> times ;
    while(times--){
        int number; 
        cin >> number ;
        cout << trans_de_to_bi(number) << " " << trans_de_to_bi(trans_he_to_de(number)) << endl;
    }
}
//7ms, 316KB