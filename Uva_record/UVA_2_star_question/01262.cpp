#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        cin.ignore();
        map<int,map<int,int>> first_cnt;
        map<int,map<int,int>> ans ;
        for(int i = 0 ; i < 6 ; i++ ){
            string input ;
            getline(cin,input);
            for(int j = 0 ; j < (int)input.size() ; j++ ){
                first_cnt[j][input[j]]++;
            }
        }
        for(int i = 0 ; i < 6 ; i++ ){
            string input ;
            getline(cin,input);
            for(int j = 0 ; j < (int)input.size(); j++ ){
                if(first_cnt[j][input[j]] > 0 ){
                    ans[j][input[j]]++;
                }
            }
        }
        vector<int> colsize ; 
        int total = 1 ;
        for(int i = 0 ; i < 5 ; i++ ){
            colsize.push_back(ans[i].size());
            total *= ans[i].size(); 
        }
        if( n > total){
            cout << "NO" << endl;
            continue;
        }
        n--;
        vector<char> out ;
        // 2 * 3 * 4 * 5 * 6 
        // 0 
        // 0 0 0 0 0 
        // 3 * 4 * 5 * 6 = n 
        // 1 0 0 0 0 
        // total /= colsize[now_col]
        // 1 /= total;
        for(int i = 0 ; i < (int)colsize.size() ; i++ ){
            total /= colsize[i] ;
            int idx = n / total ; 
            n %= total;
            int j = 0 ; 
            for(auto& iter:ans[i]){
                if( j == idx ){
                    out.push_back(iter.first);
                    break;
                } 
                j++;
            }
            
        }
        // cout << "ANS: ";
        for(int i = 0 ; i < (int)out.size() ;i++){
            cout << (char)out[i];
        }
        cout << endl;
    }
}
/*
3
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
5
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
64
FGHIJ
EFGHI
DEFGH
CDEFG
BCDEF
ABCDE
WBXDY
UWYXZ
XXZFG
YYFYH
EZWZI
ZGHIJ
*/