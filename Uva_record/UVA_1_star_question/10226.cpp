#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int times ;
    cin >> times;
    cin.ignore();
    string empty;
    getline(cin, empty);
    while(times--){
        map<string, int > record;
        string input ;
        int count = 0 ;
        while(getline(cin, input)){
            if(input.size() == 0 || input[0] == 32 ){   // 空格會讀到
                break;
            }
            record[input]++;
            count++;
        }
        for(auto& it:record){
            cout << it.first << " ";
            cout  << fixed << setprecision(4) << (double)it.second*100/count << endl;
        }
        if(times != 0 ) cout << endl;
    }
}
//fuck you zerojudge 