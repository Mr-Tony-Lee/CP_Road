#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

void process(const string& filename){
    ifstream in;
    in.open(filename);
    int PCB_Width , PCB_Length, IC_Num ;
    stringstream ss ;
    string line ;
    getline(in,line);
    string number;
    for(int k = 0 ; k < line.size() ; k++ ){
        if(line[k] == ','){
            line[k] = ' ';
        }
    }
    ss << line; 
    ss >> PCB_Width >> PCB_Length >> IC_Num;
    double Power_sum = 0 ; 
    int Area_sum = 0 ; 
    for(int i = 0 ; i < IC_Num ; i++ ){
        getline(in,line);
        for(int k = 0 ; k < line.size() ; k++ ){
            if(line[k] == ','){
                line[k] = ' ';
            }
        }
        ss << line ;
        double IC_Power;
        int IC_Area ;
        ss >> IC_Power >> IC_Area;
        Power_sum += IC_Power;
        Area_sum += IC_Area;
    }    
    bool Spec1 = false ;
    bool Spec2 = false ;
    if(Power_sum / IC_Num <= 3 ){
        Spec1 = true ;
    }
    if(Area_sum*2 <= PCB_Length * PCB_Width){
        Spec2 = true;
    }
    cout << "Average IC Power=" << fixed << setprecision(2) <<  Power_sum/IC_Num <<",SPEC1 " << (Spec1 ? "PASS":"FAIL") << endl;
    cout << "Total IC Area=" << fixed << setprecision(2) << Area_sum <<",SPEC2 " << (Spec2 ? "PASS":"FAIL") << endl;
}

int main(){
    process("ex_11_1.csv");
    // process("ex_11_2.csv");
}