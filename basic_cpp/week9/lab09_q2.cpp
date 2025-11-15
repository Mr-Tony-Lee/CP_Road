#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
    char names[50][31];
    int N , M ;
    cin >> N >> M ;
    cin.ignore();
    for(int i = 0 ; i < N ; i++ ){
        fgets(names[i],sizeof(names[i]), stdin);
    }
    char min[31];
    strcpy(min,names[0]);
    for(int i = 0 ; i < N ; i++ ){
        if(strcmp(names[i], min) < 0 ){
            strcpy(min,names[i]);
        }
    }
    cout << min << endl;
}