#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    cin.ignore();
    while(t--){
        string input ;
        getline(cin,input);
        char min = 'z'+ 1;
        vector<int> min_index ;
        for(int i = 0 ; i < (int)input.size() ; i++ ){
            if(input[i] < min ){
                min_index.clear();
                min = input[i];
                min_index.push_back(i);
            }
            else if ( input[i] == min ){
                min_index.push_back(i);
            }
        }
        string use = input + input;
        map<string,int>ans;
        for(int i = (int)min_index.size()-1 ; i >= 0 ; i-- ){
            ans[use.substr(min_index[i],input.size())] = min_index[i] + 1 ;
        } 
        cout << (*ans.begin()).second << endl;   
    }
}
/*
    解題說明: 一開始先輸入array ， 找出開頭是最小的位置，ex: aaabaaa 要找出 a 的位置( 0,1,2,4,5,6)作為我們的起始點，
    然後把我們要用的string變成2倍，保證當index是6的時候也可以使用substr ，接下來把substring丟進map的index裡面做排序，
    並把開頭的index+1丟進去所以我們會有 ans["aaaabaa"] = 6+1 ....，最後輸出map的第一個，就是答案。
*/