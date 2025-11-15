#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
    char s[51];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s)-1;
    cout << "len=" << len << endl;
    for( int i = 0 ; i < len ; i++){
        if(i != 0 ) cout << " ";
        cout << s[i];
    }
    cout << endl;
}