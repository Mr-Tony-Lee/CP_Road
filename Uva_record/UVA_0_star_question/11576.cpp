#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    while(times-- ){
        int k , w ;
        cin >> k >> w ;
        cin.ignore();
        string array[w];
        for(int i = 0 ; i < w ; i++ ){
            getline(cin, array[i]);
        }
        if( w == 1 ){
            cout << k << endl;
            continue;
        }
        string ans = "";
        ans += array[0];
        for(int i = 1 ; i < w ; i++ ){
            bool flag = false ;
            for(int j = array[i].size() ; j >= 1 ; j-- ){
                if(ans.substr(ans.size()-j , j ) == array[i].substr(0,j)){
                    ans += (array[i].substr(j , array[i].size()-j+1));
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans += array[i] ;
            }
        }
        cout << ans.size() << endl;
    }
}
//  Accepted online judge 