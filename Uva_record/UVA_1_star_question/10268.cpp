#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

int main(){
    int x ;
    while( cin >> x ){
        cin.ignore();
        // // string empty;
        // // getline(cin,empty);
        string input ;
        getline(cin , input);
        vector<int> poly ;
        stringstream ss(input); //用成sstream去讀取
        int coefficient;
        while(ss >> coefficient){
            poly.push_back(coefficient) ;
        }
        long long int sum = 0 ;
        int power = 1 ; 
        for(int i = (int)poly.size()-2 ; i >= 0 ; i--){
            sum += power * poly[i] * pow(x,power-1);
            power++;
        }
        cout << sum << endl;
    }
}
//58ms, 324KB