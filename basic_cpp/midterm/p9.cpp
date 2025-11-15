#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string> name ; 
    vector<double> p ;
    vector<double> d ;
    for(int i = 0 ; i < 3 ; i++ ){
        string n ;
        double price , day ;
        cin >> n >> price >> day ;
        name.push_back(n);
        p.push_back(price);
        d.push_back(day);
    }
    cout << left << setw(10) << "Name" << right << setw(10) << "Price" << right << setw(10) << "Days" << right << setw(10) << "Total" << endl;
    for(int i = 0 ; i < 3 ; i++ ){
        cout << left << setw(10) << name[i] << right << setw(10) << fixed << setprecision(2) << p[i] ;
        cout << fixed << setprecision(0)<< right << setw(10) << d[i];
        cout << right << setw(10) << fixed << setprecision(2) << p[i]*d[i] << endl;
    }
    
       
}