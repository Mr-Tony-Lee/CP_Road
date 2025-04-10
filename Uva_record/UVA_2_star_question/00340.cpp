#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    int g = 0 ;
    while(cin >> N ){
        if(N == 0 ){
            break;
        }
        vector<int> ans ;
        for(int i = 0 ; i < N ; i++ ){
            int n ; 
            cin >> n ;
            ans.push_back(n);
        }
        cout << "Game " << ++g << ":" << endl;
        while(1){
            vector<int> copy = ans ;
            vector<int> input; 
            int count = 0 ; 
            int A = 0 , B = 0 ; 
            for(int i = 0 ; i < N ; i++ ){
                int n ; 
                cin >> n ;
                input.push_back(n);
                if(n == 0 ){
                    count++;
                }
                if(n == ans[i]){
                    A++;
                    copy[i] = 0 ;
                    input[i] = 0 ;
                }
            }
            if(count == N ){
                break;
            }
            for(int i = 0 ; i < N ; i++ ){
                if(copy[i] != 0 ){
                    auto iter = find(input.begin(),input.end() , copy[i]);
                    if( iter != input.end()){
                        *iter = 0 ;
                        B++;
                    }
                }
            }
            
            cout << "    (" << A << "," << B << ")" << endl;
        
        }
    }
}
//Online judge Accepted