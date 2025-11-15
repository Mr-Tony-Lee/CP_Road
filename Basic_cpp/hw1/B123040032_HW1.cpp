#include<iostream>
#include<string>
#include<cstdlib>
#include<cctype>
#include<cstring>
using namespace std;

int main(){
    char input[103] = "";
    cin.getline(input, 100);
    
    string target ;
    cin >> target ; 
    
    int index_pre = -1, index_end = -1;
    int n = strlen(input), m = target.size();

    for(int i = 0 ; i < n ; i++ ){
        if( i+m < n && tolower(input[i]) == tolower(target[0])){
            int count = 0 ; 
            for(int j = 0 ; j < m ; j++ ){
                if(tolower(input[i+j]) == tolower(target[j])){
                    count ++ ;
                }
            }
            if(count == m ){
                index_pre = i;
                index_end = i+m;
                break;
            }
        }
    }
    cout << index_pre << endl;
    for(int i = 0 ; i < n ; i++ ){
        if(i == index_pre) cout << "[";
        if(i == index_end) cout << "]";
        cout << input[i];
    }
    cout << endl;
}
/*
HeLLo, C-String world! 
hello

, , , 
bsbs

GOOD MORNING!!! 
mOrni
*/

