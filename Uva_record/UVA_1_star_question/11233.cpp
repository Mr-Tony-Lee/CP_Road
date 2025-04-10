#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int L , N ;
    cin >> L >> N ; 
    map<string,string> irr ;
    for(int i = 0 ; i < L ; i++ ){
        string ir , p ; 
        cin >> ir >> p ;
        irr[ir] = p;
    }
    while(N--){
        string in;
        cin >> in;
        bool flag = false ;
        for(auto& iter:irr ){
            if(iter.first == in ){
                cout << iter.second << endl;
                flag = true;
                break;
            }
        }
        int length = in.size();
        if(!flag){
            if(in[length-1] == 'y' && in[length-2] != 'a' && in[length-2] != 'e' && in[length-2] != 'i' && in[length-2] != 'o' && in[length-2] != 'u'){
                in[length-1] = 'i';
                in+= "es" ;
                cout << in << endl;
            }
            else if (in[length-1] == 'o' || in[length-1] == 's' || (in[length-2] == 'c' && in[length-1] == 'h')
                || (in[length-2] == 's' && in[length-1] == 'h') || in[length-1] == 'x'
            ) {
                in+="es";
                cout << in << endl;
            }
            else{
                in+= "s" ;
                cout << in << endl;
            }
        }
    }
}
//online judge accepted. 