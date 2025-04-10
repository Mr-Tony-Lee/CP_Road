#include<iostream>
#include<string>
using namespace std;

int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30};
string week[8] = {"" , "Monday" , "Tuesday" , "Wednesday" , "Thursday", "Friday" , "Saturday" , "Sunday"};

int main(){
    int initial = 6;    // 1/1 是禮拜6
    int times ;
    cin >> times;
    while(times--){
        int count = 0; 
        int i_month , i_day ; 
        cin >> i_month >> i_day;
        for(int i = 0 ; i < i_month; i++){
            count += day[i];
        }
        count += i_day;
        int that_day = (initial + count - 1) % 7;
        if(that_day == 0 ){
            cout << week[7] << endl;
        }
        else{
            cout << week[that_day] << endl;
        }
    }
}
//3ms, 336KB