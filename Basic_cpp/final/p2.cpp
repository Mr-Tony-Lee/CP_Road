#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    string name ;
    while(getline(cin, input)){
        stringstream ss ;
        if(input.substr(0,4) == "NAME"){
            ss << input.substr(5);
            ss >> name;    
            continue;
        }
        double average = 0 ;
        
        ss << input.substr(6);
        string subj;
        ss >> subj;
        string score;
        int cnt = 0 ;
        while(ss >> score){
            bool flag = true;
            for(int i = 0 ; i < score.size() ; i++){
                if(score[i] > '9' || score[i] < '0'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                average += stoi(score);
                cnt ++ ;
            }
        }
        average /= cnt;
        cout << name << " "<< subj << " " << average << endl;
    }
}