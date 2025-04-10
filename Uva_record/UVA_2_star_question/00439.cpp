#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string pos1 , pos2 ;
    while(cin >> pos1 >> pos2 ){
        int ans = 0 ;
        if(pos1 == pos2 ){
            cout << "To get from " << pos1 <<" to "<< pos2 << " takes "<< 0 << " knight moves."<< endl;
        }
        int pos1_x = pos1[0]-'a';
        int pos1_y = pos1[1]-'0';
        int pos2_x = pos2[0]-'a';
        int pos2_y = pos2[1]-'0';
        



        cout << "To get from " << pos1 <<" to "<< pos2 << " takes "<< ans << " knight moves."<< endl;
    }
}