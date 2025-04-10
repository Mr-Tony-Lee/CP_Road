#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int times ;
    cin >> times;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(times--){
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double m1 = (y2-y1)/(x2-x1);
        double m2 = (y4-y3)/(x4-x3);
        if( m1 == m2 || (to_string(m1) == "inf" && to_string(m2) == "-inf") || (to_string(m1) == "-inf" && to_string(m2) == "inf")){
            if( x1 == x2  ){
                if(x1 == x3 ){
                    cout << "LINE" << endl;
                }
                else{
                    cout << "NONE" << endl;
                }
            }
            else{
                double d1 = y2 - m1*x2;
                double d2 = y4 - m2*x4;
                if( d1 == d2 ){
                    cout << "LINE" << endl;
                }
                else{
                    cout << "NONE" << endl;
                }
            }
            
        }
        else{
            double d1 = y2 - m1*x2;
            double d2 = y4 - m2*x4;
            //y = m1*x + d1  = m2*x + d2  (m1-m2)x = d2-d1;

            double ans_x ;
            double ans_y ;
            if(to_string(m1) == "inf" || to_string(m1) == "-inf"){
                ans_x = x1;
                ans_y = ans_x*m2 + d2 ;
            }
            else if(to_string(m2) == "inf" || to_string(m2) == "-inf"){
                ans_x = x3 ; 
                ans_y = ans_x * m1 + d1 ;
            }
            else{
                ans_x = (d2-d1) / (m1-m2);
                ans_y = ans_x * m1 + d1;
            }  
            cout << "POINT " <<fixed << setprecision(2) << ans_x << " " << ans_y << endl;
        }
    }   
    cout << "END OF OUTPUT" << endl;
}