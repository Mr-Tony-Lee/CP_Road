#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

void process(){
    string name, age, gender ;
    getline(cin, name);
    getline(cin, age);
    getline(cin, gender);
    int num_age = stoi(age);
    
    ofstream out;
    out.open("sample.json");
    out << "{" << endl;
    out << "\t\"name\":\"" << name << "\"," << endl;
    out << "\t\"age\":0x" << hex << num_age << "," << endl;
    out << "\t\"gender\":\"" << gender << "\"" << endl;
    out << "}";

}

int main(){
    process();
}