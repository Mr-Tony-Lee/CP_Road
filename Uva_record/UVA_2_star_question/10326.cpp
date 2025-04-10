#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

map<ll,ll> solve(map<ll,ll> base , map<ll,ll> multi){   //calculate polynomial multiplication
    map<ll,ll> ans ; 
    for(auto iter1:multi){
        for(auto iter2:base){
            ans[iter1.first+iter2.first] += iter1.second*iter2.second;
        }
    }
    return ans ; 
}

int main(){
    int n ;
    while(cin >> n ){
        vector<int> root ;
        for(int i = 0 ; i < n ; i++ ){
            int x ;
            cin >> x ;
            root.push_back(-x);
        }
        map<ll,ll> now;
        now[1] = 1 ;
        now[0] = root[0];

        map<ll,ll> pow_coe; 
        for(int i = 1 ; i < n ; i++ ){
            pow_coe[1] = 1 ;
            pow_coe[0] = root[i];
            now = solve(now , pow_coe);
        }
        
        for(auto iter = now.rbegin(); iter != now.rend() ; iter++  ){
            if(iter->first != 0 && iter->second == 0 ){
                continue;
            }
            else if (iter->first == 0 ){
                if(iter->second == 0 ){
                    cout << "+ 0 " ;
                }
                else{
                    if(iter->second < 0 ){
                        cout << "- " << abs(iter->second) << " ";
                    }
                    else{
                        cout << "+ " << abs(iter->second) << " ";
                    }
                }
            }
            else if (iter->first == n ){
                if(n == 1 ){
                    cout << "x" << " ";
                }
                else{
                    cout << "x^" << iter->first << " ";
                }
            }
            else if (iter->first == 1 ){
                if(iter->second < 0 ){
                    if(abs(iter->second) == 1 ){
                        cout << "- " << "x " ;
                    }
                    else{
                        cout << "- " << abs(iter->second) << "x " ;
                    }
                }
                else{
                    if(abs(iter->second) == 1 ){
                        cout << "+ " << "x " ;
                    }
                    else{
                        cout << "+ " << abs(iter->second) << "x " ;
                    }
                }
            }

            else if (iter->second != 0 ){
                if(iter->second < 0 ){
                    if(abs(iter->second) == 1 ){
                        cout << "- " << "x^" << iter->first << " " ;
                    }
                    else {
                        cout << "- " << abs(iter->second) << "x^" << iter->first << " " ;
                    }
                }
                else{
                    if(abs(iter->second) == 1 ){
                        cout << "+ " << "x^" << iter->first << " " ;
                    }
                    else {
                        cout << "+ " << abs(iter->second) << "x^" << iter->first << " " ;
                    }
                }
            }
        }
        cout << "= 0" << endl;
    }
}

// Accepted Uva 