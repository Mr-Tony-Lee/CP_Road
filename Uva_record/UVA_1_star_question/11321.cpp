#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int M ; 
// bool compare(int a , int b  ){
//     if(a % M > b % M ){
//         return false ;
//     }
//     else if (a % M == b % M ){
//         if((a % 2) && (b % 2) ){
//             if(a < b){
//                 return false ;
//             }
//         }
//         else if ( a % 2 == 0 && b % 2 == 0 ){
//             if(b < a){
//                 return false ;
//             }
//         }
//         else{
//             return false ;
//         }
//     }
//     return true ;
// }
bool compare(int p1,int p2)
{
    if((p1%M)!=(p2%M))
    {
        return p1%M<p2%M;
    }
    else if((p1%2==1)&&(p2%2==1))//若此判斷這樣寫RE，改為else if((p1%2)&&(p2%2))則AC
    {
        return p1>p2;
    }
    else if((p1%2==0)&&(p2%2==0))
    {
        return p1<p2;
    }
    else
    {
        return p1%2;
    }
}
int main(){
    while(1){
        int N ;
        cin >> N >> M ;
        if(N == 0 && M == 0 ){
            cout << 0 << " " << 0 << endl;
            break;
        }
        vector<long long int> array ;
        for(int i = 0 ; i < N ; i++ ){
            long long int x ;
            cin >> x ;
            array.push_back(x);
        }
        sort(array.begin(), array.end() , compare);
        cout << N << " " << M << endl;
        for(int i = 0 ; i < (int)array.size() ; i++ ){
            cout << array.at(i) << endl;
        }
    }
}
