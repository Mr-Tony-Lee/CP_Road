#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file ;
    file.open("../all.txt");
    ofstream out ; 
    out.open("../out.txt");
    string question ;
    while(getline(file,question)){
        int size = question.size();
        if(question.size() < 7 ){
            for(int i = 0 ; i < 7-size ; i++ ){
                question.insert(question.begin(),'0');
            }
        }
        out << question.substr(0,5) << endl;
    }
}