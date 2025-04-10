#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long int n , m ;
    while(cin >> n >> m ){
        vector<long long int> output ;
        if(m == 0 ){
            cout << "Boring!" << endl;
            continue;
        }
        while( n % m == 0 ){
            output.push_back(n);
            n /= m ; 
        }
        if(n == 1 ){
            output.push_back(1);
            for(int i = 0 ; i < (int)output.size() ; i++ ){
                cout << output[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Boring!" << endl;
        }
    }
}
//3ms, 316KB