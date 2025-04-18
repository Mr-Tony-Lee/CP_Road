#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string input ;
    map<string,int> m;
    cin >> input ;
    int count = 0 ;
    sort(input.begin(),input.end());
    do{
        m[input]++;
        count++;
    }while(next_permutation(input.begin(),input.end()));
    cout << count << endl;
    for(auto& iter:m){
        cout << iter.first << endl;
    }
}