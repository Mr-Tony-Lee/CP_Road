#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    while( cin >> n && n ){
        if(n == 13 ){
            cout << 1 << endl;
            continue;
        }
        long long int m = 2 ;
        while(1){
            vector<int> array ;
            for(int i = 0 ; i < n ; i++ ){
                array.push_back(i+1);
            }
            int count = 0 ;
            while(array.size() != 1 ){
                for(int i = 0 ; i < (int)array.size() ; i++ ){
                    if( count % m == 0 ){
                        array[i] = 0 ;
                    }
                    count++;
                }
                vector<int> newarray;
                for(int i = 0 ; i < (int)array.size() ; i++ ){
                    if(array[i] != 0 ){
                        newarray.push_back(array[i]);
                    }
                }
                array = newarray;
            }
            if(array[0] == 13){
                cout << m << endl;
                break;
            }
            m++;
        }
    }
}

//Accepted online judge