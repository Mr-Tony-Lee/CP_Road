#include<iostream>
#include<string>
using namespace std;

int judge(string input , int count   ){
    int sum = 0 ;
    for(int i = 0 ; i < (int)input.size() ; i++ ){
        sum += (int)(input[i]-'0'); 
    }
    count++ ;
    if(sum == 9 ){
        return count;
    }
    else if (sum < 9 ) {
        return 0 ;
    }
    else{
        return judge(to_string(sum), count );
    }
    
}

int main(){
    string input ;
    while(cin >> input){
        if(input == "0"){
            break;
        }
        int count = judge(input,0);
        if(count == 0 ){
            cout << input << " is not a multiple of 9." << endl;
        }
        else {
            cout << input << " is a multiple of 9 and has 9-degree " << count << "." << endl;
        }
    }
}
//2ms, 348KB