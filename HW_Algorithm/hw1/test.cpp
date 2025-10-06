#include<bits/stdc++.h>
using namespace std;

double dis(tuple<int,int,int> a , tuple<int,int,int> b ){
    double x1 = get<1>(a) , y1 = get<2>(a);
    double x2 = get<1>(b) , y2 = get<2>(b);
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
bool cmp(tuple<int,int,int> a , tuple<int,int,int> b ){
    return get<0>(a) < get<0>(b);
}
int main(){
    vector<tuple<int,int,int>> arr; 
    int n , x , y ;
    double ans = 1.0*INT_MAX ;
    vector<int> ans_point;
    while( cin >> n >> x >> y , n && x && y ){
        arr.push_back({n,x,y});
    }
    int cnt = 0 ;
    do{
        double sum_dis = 0 ; 
        for(int i = 0 ; i < arr.size() ; i++ ){
            sum_dis += dis(arr[i],arr[(i+1)%arr.size()]);
        }
        if(sum_dis < ans){
            ans_point.clear();
            for(int i = 0 ; i < arr.size() ; i++ ){
                ans_point.push_back(get<0>(arr[i]));
            }
            ans = sum_dis;
        }
    }while(next_permutation(arr.begin(),arr.end(),cmp));
    cout << "distance: " << ans << endl;
    for(int i = 0 ; i < ans_point.size() ; i++ ){
        cout << ans_point[i] << endl;
    }
}