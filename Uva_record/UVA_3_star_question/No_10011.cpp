#include<bits/stdc++.h>
using namespace std;

double mypower(double base , int power ){
    double ans = 1.0 ;
    for(int i = 0 ; i < power ; i++ ){
        ans *= base ;
    }
    return ans ;
}

double dis(double x , double y , double a , double b ){
    return sqrt(mypower(x-a,2) + mypower(y-b,2));
}

int main(){
    int n ;
    cin >> n ;
    while(n--){
        double x , y , r , hx , hy ;
        cin >> x >> y >> r >> hx >> hy;
        double a_pos = (2*x*y + sqrt(4*((mypower(x,2)+mypower(y,2))*mypower(r,2) -mypower(r,4))))/(2*(mypower(x,2)-mypower(r,2)));  // 斜率 
        double a_neg = (2*x*y - sqrt(4*((mypower(x,2)+mypower(y,2))*mypower(r,2) -mypower(r,4))))/(2*(mypower(x,2)-mypower(r,2)));  // 斜率  
        double dis_pos = abs(hx*a_pos-hy) / sqrt(mypower(a_pos,2)+1);
        double dis_neg = abs(hx*a_neg-hy) / sqrt(mypower(a_neg,2)+1);        
        cout << fixed << setprecision(3) << min(dis_pos , dis_neg) << endl;
    }
}
// 
// 