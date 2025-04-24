#include<bits/stdc++.h>
using namespace std;

int n , m ; 

int main(){
    while(cin >> n >> m ){
        cin.ignore();
        vector<string> all_file ;
        for(int i = 0 ; i < n ; i++ ){
            string input ;
            getline(cin,input);
            all_file.push_back(input);
        }
    }
}
/*
19 2
LICENCE.TMP
WIN32.LOG
FILEID.
PSTOTEXT.TXT
GSVIEW32.EXE
GSVIEW32.ICO
GSVIEWDE.HLP
LICENCE
GSVIEWEN.HLP
GSVW32DE.DLL
FILEID.TMP
GSVW32EN.DLL
PSTOTXT3.DLL
PSTOTXT3.EXE
GSV16SPL.EXE
GVWGS32.EXE
ZLIB32.DLL
PRINTER.INI


*/