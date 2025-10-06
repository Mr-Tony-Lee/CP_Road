#include<bits/stdc++.h>
using namespace std;

int checkhalf(vector<int> vote, int sum ){
    for(int i = 1 ; i < vote.size(); i++){
        if(vote[i]*2 > sum){
            return i ;
        }
    }
    return 0;
}
int kill(vector<int> vote, set<int> killed){
    int minN = 1001;
    int kill = 0 ;
    for(int i = 1 ; i < vote.size(); i++){
        if(killed.count(i)) continue;
        if(vote[i] < minN ){
            minN = vote[i];
            kill = i ;
        }
    }
    return kill;
}
int main(){
    int kase ;
    cin >> kase ;
    while(kase--){
        int n ; 
        cin >> n ;
        cin.ignore();
        map<int,string> candidate; 
        vector<int> vote(n+1,0);
        for(int i = 1 ; i <= n ; i++ ){
            string input ;
            getline(cin,input);
            candidate[i] = input;
        }
        string input ;
        stringstream ss ;
        vector<string> voting ; 
        int sum = 0 ;
        while(getline(cin,input) && input.length() != 0 ){
            voting.push_back(input);
            int first ; 
            ss << input ;
            ss >> first ;
            vote[first]++;
            sum++;
        }
        set<int> killed ; 
        while(!checkhalf(vote,sum)){
            killed.insert(kill(vote,killed));
            vote.clear();
            for(int i = 0 ; i < voting.size(); i++ ){
                int first ; 
                ss << voting[i] ;
                while(ss >> first ){
                    if(!killed.count(first)) break;
                }
                vote[first]++;
            }
        }
        cout << candidate[checkhalf(vote,sum)] << endl;
    }
}