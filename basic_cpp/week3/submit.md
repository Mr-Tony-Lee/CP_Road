第一題:
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    ifstream file;
    file.open("data.txt");
    int count = 1 ; 
    string input ;
    while(getline(file,input)){
        stringstream ss;
        ss << input;
        int num1 , num2 ;
        ss >> num1 ;
        ss >> num2 ;
        cout << "Line " << count++ << ": Sum=" << num1 + num2 << ", Diff=" << num1-num2 << ", Prod=" << num1*num2 << ", Quot=" << num1/num2 << endl;
    } 
}

第二題:
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