#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , p;
    int kase = 0 ; 
    while(cin >> n >> p , n || p){
        if(kase){
            cout << endl;
        }

        cin.ignore();
        map<string,int> r ; 
        for(int i = 0 ; i < n ; i++ ){
            string input ;
            getline(cin,input);
            r[input]++ ;
        }
        int ans_met = 0 , ans_price = 0;
        string ans_name ;
        for(int i = 0 ; i < p ; i++ ){
            string name ;
            getline(cin , name);
            double price;
            int j ; 
            int cnt = 0 ; 
            cin >> price >> j ;
            cin.ignore();
            while(j--){
                string each_requirement;
                set<string> record ;
                getline(cin,each_requirement);
                if(r.count(each_requirement)){
                    // if(!record.count(each_requirement)){
                        cnt++ ;
                    //     record.insert(each_requirement);
                    // }
                }
            }
            if(cnt > ans_met){
                ans_met = cnt ; 
                ans_price = price ;
                ans_name = name;
            }
            else if (cnt == ans_met ){
                if(price < ans_price){
                    ans_price = price;
                    ans_name = name ;
                }
            }
        }
        cout << "RFP #" << ++kase << endl;
        cout << ans_name << endl;
    }
}