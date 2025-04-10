#include<iostream>
#include<utility>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

double dis(pair<int,int> a, pair<int,int> b  ){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

int main(){
    int n ;
    int count = 0 ;
    while(cin >> n && n ){
        if(count != 0 ){
            cout << endl;
        }
        count ++ ;
        vector<pair<int,int>> point ; 
        double array[200][200];
        for(int i = 0 ; i < n ; i++ ){
            int x , y ;
            cin >> x >> y ;
            point.push_back(make_pair(x,y));
        }
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                array[i][j] = dis(point[i],point[j]);
            }
        }
        for(int k = 0 ; k < n ; k++ ){
            for(int i = 0 ; i < n ; i++ ){
                for(int j = 0 ; j < n ; j++ ){
                    if(array[i][j] > max(array[i][k], array[k][j])){
                        array[i][j] = max(array[i][k], array[k][j]);
                    }
                }
            }
        }
        cout << "Scenario #" << count << endl << "Frog Distance = ";  
        cout << fixed << setprecision(3) << array[0][1] << endl;
    }
}