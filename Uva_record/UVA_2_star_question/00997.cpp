#include<bits/stdc++.h>
using namespace std;

vector<int> sequence(120,0);

void recursive(string input , int start , int end ){
    bool neg = false;
    int n = 0 ;
    int next_start = 0 ;
    for(int i = start+1 ; i < end ; i++ ){
        if(input[i] == '-'){
            neg = true;
        }
        else if ( input[i] >= '0' && input[i] <= '9'){
            n = n*10 + input[i]-'0';
        }
        else{
            next_start = i ; 
            break;
        }
    }
    if (neg) n *= -1 ;

    if(input[next_start] == '+'){
        recursive(input,next_start+1 , end);    // +[ 
        int temp = sequence[0];
        sequence[0] = n ;
        for(int i = 1 ; i < 50 ; i++ ){
            int now_temp = sequence[i];
            sequence[i] = sequence[i-1] + temp;
            temp = now_temp;
        }
    }
    else if (input[next_start] == '*'){
        recursive(input , next_start+1 , end);
        sequence[0] = n * sequence[0];  // n * S1
        for(int i = 1 ; i < 50 ; i++ ){
            sequence[i] = sequence[i-1] * sequence[i];  // Vi-1 * Si 
        }
    }
    else{
        for(int i = 0 ; i <= 50 ; i++ ){
            sequence[i] = n;
        }
    }
}

int main(){
    string input ;
    int N ;
    while(cin >> input >> N ){
        recursive(input , 0 , input.size());
        for(int i = 0 ; i < N ; i++ ){
            if(i != 0 ){
                cout << " ";
            }   
            cout << sequence[i] ;
        }
        cout << endl;
    }
}
/*
[2+[1]] 3
[2*[5+[-2]]] 7
*/