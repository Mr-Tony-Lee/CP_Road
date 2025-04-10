#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int times;
    cin >> times ;
    cin.ignore();
    vector<char> allstring ;
    while(times--){
        string every_line;
        getline(cin , every_line);  
        for(int i = 0 ; i < (int)every_line.size(); i++ ){
            if((every_line[i] <= 'z' && every_line[i] >= 'a') || (every_line[i] <= 'Z' && every_line[i] >= 'A' )){
                allstring.push_back(toupper(every_line[i]));
            }
        }
        cout << every_line << endl;
    }
    int alpht[26] = {0};
    for(int i = 0 ; i < (int)allstring.size(); i++ ){
        cout << allstring[i] << endl;
        alpht[allstring[i]-'A'] ++; 
    }
    int max_alpht= -1;
    for(int i = 0 ; i < 26 ; i++ ){
        max_alpht = max(max_alpht,alpht[i]);
    }
    for(int i = max_alpht ; i > 0 ; i-- ){
        for(int j = 0 ; j < 26 ; j++ ){
            if(alpht[j] == i){
                char character = j+'A';
                cout << character << " " << alpht[j] << endl;
            }
        }
    }
}
//直接放上zerojudge會錯，問題應該出在cin.ignore()，但換getline(cin,empty)一樣錯，但直接在vs code上打測資是對的..