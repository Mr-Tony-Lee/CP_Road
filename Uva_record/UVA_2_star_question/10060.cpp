#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6

typedef pair<double,double> point ;

double myabs(double n ){
    if(n < 0 ) return -n ; 
    return n ;
}

double area(point a , point b ){
    return 1.0*(a.first * b.second - a.second * b.first);
}

int main (){
    cin.tie(0) ; cout.tie(0); ios::sync_with_stdio(false);
    int N ;
    while(cin >> N , N ){
        double total_volumn = 0 ; 
        for(int i = 0 ; i < N ; i++ ){
            vector<point> arr ; 
            double ti , x0 , y0 ;
            cin >> ti >> x0 >> y0; 
            arr.push_back({x0,y0});
            double x , y ;
            while(cin >> x >> y ){
                if(myabs(x-x0) < eps && myabs(y-y0) < eps ) break;
                arr.push_back({x,y});
            }

            double temp = 0 ; 
            for(int j = 0 ; j < (int)arr.size() ; j++){
                point next = arr[(j+1) % arr.size()];
                temp += area(arr[j] , next);
            }
            total_volumn += myabs(temp) * ti / 2 ;
        }
        double R , L ;
        cin >> R >> L ;
        double circle_volumn = 1.0 * R * R * M_PI * L ; 
        cout << int(total_volumn / circle_volumn) << endl;      
    }      
}
/*
2
2 0 0 0 10 5 15 12 10 10 0 0 0 
5 0 0 5 100 100 0 0 0 
5 3
1
2 0 0 10 0 10 10 0 10 0 0 
5 2
0
*/