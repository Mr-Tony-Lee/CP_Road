#include<iostream>
#include<string>
using namespace std;

int main(){
    string a , b ;
    while(cin >> a >> b){
        int ascii_a[128] = {0};
        for(int i = 0 ; i < (int)a.size(); i++){
            ascii_a[(int)a[i]] ++ ;
        }
        int ascii_b[128] = {0};
        for(int i = 0 ; i < (int)b.size() ; i++ ){
            ascii_b[(int)b[i]] ++ ; 
        }
        for(int i = 65 ; i < 128 ; i++ ){
            if(ascii_a[i] != 0 && ascii_b[i] != 0 ){
                int number = min(ascii_a[i],ascii_b[i]);
                while(number--){
                    cout << (char)i ;
                } 
            }
        }
        cout << endl;
    }
}
//2ms, 316KB    