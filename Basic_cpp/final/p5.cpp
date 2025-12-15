#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> arr(4,vector<int>(4,0));
    for(int i = 0 ; i < 4 ; i++ ){
        for(int j = 0 ; j < 4 ; j++ ){
            cin >> arr[i][j] ;
        }
    }   
    vector<int> counter_row(5,0);
    vector<int> counter_col(5,0);
    
    bool valid = true;
    // check each row and col 
    for(int i = 0 ; i < 4 ; i++ ){
        counter_row.assign(5,0);
        counter_col.assign(5,0);
        for(int j = 0 ; j < 4 ; j++ ){
            if(arr[i][j] <= 4 && arr[i][j] >= 1 ){
                counter_row[arr[i][j]]++;
            }
            if(arr[i][j] <= 4 && arr[j][i] >= 1 ){
                counter_col[arr[j][i]]++;
            }
        }
        for(int j = 1 ; j <= 4 ; j++ ){
            if(counter_row[j] != 1 || counter_col[j] != 1 ){
                valid = false;
                break;
            }
        }
        if(!valid) break;
    }
    
    // check block
    vector<int> counter_block(5,0);
    pair<pair<int,int>,pair<int,int>> sub_block[4] = { {{0,1},{0,1}}, {{0,1},{2,3}} , {{2,3},{0,1}}, {{2,3},{2,3}}} ;
    for(int k = 0 ; k < 4 ; k++ ){  // iter sub-block
        counter_block.assign(5,0);
        for(int i = sub_block[k].first.first; i <= sub_block[k].first.second ; i++ ){
            for(int j = sub_block[k].second.first ; j <= sub_block[k].second.second; j++){
                if(arr[i][j] >= 1 && arr[i][j] <= 4 ){
                    counter_block[arr[i][j]]++;
                }
            }
        }
        for(int j = 1 ; j <= 4 ; j++ ){
            if(counter_block[j] != 1 ){
                valid = false;
                break;
            }
        }
    }
    cout << (valid ? "Valid":"Invalid") << endl;
    
}