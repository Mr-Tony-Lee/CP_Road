第一題:

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

第二題:

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