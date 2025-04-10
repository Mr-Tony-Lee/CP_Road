#include<iostream>
using namespace std;

int main(){
    int times ;
    cin >> times ;
    while(times -- ){
        int day ;
        int ans = 0 ; 
        cin >> day;
        int party_number ;
        cin >> party_number;
        int h[party_number];
        int matrix[party_number][day];
        for(int i = 0 ; i < party_number ; i++ ){
            cin >> h[i] ;
        }
        string week[7] = {"Su" , "Mo" , "Tu" , "We" , "Th" , "Fr","Sa" } ;
        for(int i = 0 ; i < party_number ; i++ ){
            for(int j = 0 ; j < day ; j++ ){
                matrix[i][j] = 0 ;
                if((j+1) % h[i] == 0 && week[j%7] != "Fr" && week[j%7] != "Sa"){
                    matrix[i][j] = 1 ;
                }
            }
        }
        for(int i = 0 ; i < day ; i ++ ){
            bool flag = false ;
            for(int j = 0 ; j < party_number ; j++ ){
                if(matrix[j][i] == 1 ){
                    flag = true ;
                }
            }
            if(flag) ans++ ;
        }
        cout << ans << endl;
    }
}
//5ms, 1.6MB