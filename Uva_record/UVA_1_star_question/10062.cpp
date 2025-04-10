#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
    string input ;
    while(getline(cin , input )){
        map<int,int> record ;
        for(int i = 0 ; i < (int)input.size() ; i++ ){
            if((int)input[i] >= 23 ){
                record[(int)input[i]] ++;
            }
        }
        vector<int> record_times ;
        for(auto iter:record ){
            if(find(record_times.begin() , record_times.end(), iter.second) == record_times.end())record_times.push_back(iter.second);
        }
        sort(record_times.begin(),record_times.end());
        for(int i = 0  ; i < (int)record_times.size() ; i++ ){
            int num = record_times[i] ;
            //for (map<int,int>::reverse_iterator iter = record.rbegin() ; iter != record.rend(); iter++);
            for(auto iter = record.rbegin(); iter != record.rend() ; iter++){
                if((*iter).second == num ){
                    cout << (*iter).first << " " << (*iter).second << endl;
                }
            }
        }
    }
}
//4ms, 336KB