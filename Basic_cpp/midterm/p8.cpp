#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int seed , R ;
    cin >> seed >> R ;
    srand(seed);

    double mean = 0 ; 
    vector<int> face(6,0);
    for(int i = 0 ; i < R ; i++ ){
        face[rand()% 6] += 1 ; 
    }
    int minf = 10000000 , maxf = 0 ; 
    int ansmin , ansmax ;
    for(int i = 0 ; i < 6 ; i++ ){
        mean += face[i] * (i+1);
        if(face[i] < minf){
            ansmin = i+1 ;
            minf = face[i];
        }
        if(face[i] > maxf ){
            ansmax = i+1 ;
            maxf = face[i];
        }
    }
    mean /= R ;
    cout << "COUNTS: ";
    for(int i = 0; i< 6 ; i++ ){
        cout << face[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) <<  "MEAN: " << mean << endl;
    cout << "MAX COUNT FACE: " << ansmax << endl;
    cout << "MIN COUNT FACE: " << ansmin << endl;



}