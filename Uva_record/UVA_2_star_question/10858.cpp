#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void dfs(vector<vector<int>>& ans , int number , int n  , vector<int>& temp ){
    int bound = sqrt(number);
    for(int i = n ; i <= bound ; i++ ){
        if(number % i == 0 ){
            temp.push_back(i);
            dfs(ans , number/i , i , temp);
            temp.pop_back();
        }
    } 
    temp.push_back(number);
    ans.push_back(temp);
    temp.pop_back();
}

int main(){
    int number ;
    while(cin >> number && number){
        vector<vector<int>> ans ;
        vector<int> temp ; 
        dfs(ans, number, 2  , temp );    
        cout << ans.size()-1 << endl;
        for(int i = 0 ; i < (int)ans.size()-1 ; i++) {
            for(int j = 0 ; j < (int)ans[i].size() ; j++ ){
                if(j != (int)ans[i].size()-1){
                    cout << ans[i][j] << " ";
                }
                else{
                    cout << ans[i][j];
                }
                
            }
            cout << endl;
        }
    }
}