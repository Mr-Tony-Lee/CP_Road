#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    string name ;
    getline(cin,name);
    int Qty ;
    double Unit ;
    string c_name ;
    cin >> Qty >> Unit;
    double total = Qty * Unit ; 
    cin.ignore();
    getline(cin,c_name);
    cout << left << setw(20) << "Item" << right << setw(6) << "Qty" << right << setw(10) << "Unit" << right << setw(12) << "Total" << endl;
    cout << fixed << setprecision(2) ; 
    cout << left << setw(20) << name << right << setw(6) << Qty << right << setw(10) << Unit << right << setw(12) << total << endl;
    cout << c_name << endl;
}