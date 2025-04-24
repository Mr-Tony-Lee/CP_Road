#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> table ;

int cnt ; 
int n , m ; 

void print(){
    cout << "A=>"; 
    for(int i = 0 ; i < (int)table['A'].size() ; i++ ){
        if(i == 0 ) cout << "   " << table['A'][i];
        else{
            cout << " " << table['A'][i];
        }
    }
    cout << endl;
    cout << "B=>"; 
    for(int i = 0 ; i < (int)table['B'].size() ; i++ ){
        if(i == 0 ) cout << "   " << table['B'][i];
        else{
            cout << " " << table['B'][i];
        }
    }
    cout << endl;
    cout << "C=>"; 
    for(int i = 0 ; i < (int)table['C'].size() ; i++ ){
        if(i == 0 ) cout << "   " << table['C'][i];
        else{
            cout << " " << table['C'][i];
        }
    }
    cout << endl;
    cout << endl;
}

void hanoi(int init , int mid , int des , int disk){
    if( disk == 1 ){
        table[des].push_back(table[init].back());
        table[init].pop_back();
        cnt++;
        if(cnt > m){
            return ;
        }
        print();
        return ;
    }
    hanoi(init, des , mid , disk-1);
    if(cnt > m ){
        return ;
    }
    hanoi(init , mid , des , 1 );
    hanoi(mid , init , des , disk-1);
}

int main(){
    int kase = 1 ; 
    while(cin >> n >> m && (n || m)){
        table.clear();
        cnt = 0 ;
        for(int i = n ; i > 0 ; i-- ){
            table['A'].push_back(i);
        }
        cout << "Problem #" << kase++ << endl << endl;
        print();
        hanoi('A','B','C', n );
    }   
}