#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> arr; 
int n , x , y ;
double ans = 1.0 * INT_MAX ;
vector<int> ans_point;
vector<vector<double>> all_dis;
double dis(tuple<int,int,int> a , tuple<int,int,int> b ){
    double x1 = get<1>(a) , y1 = get<2>(a);
    double x2 = get<1>(b) , y2 = get<2>(b);
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void dis_map(){
    for(int i = 0 ; i < arr.size() ; i++){
        vector<double> each_row ;
        for(int j = 0 ; j < arr.size(); j++ ){
            each_row.push_back(dis(arr[i],arr[j]));
        }
        all_dis.push_back(each_row);
    }
    for(int i = 0 ; i < arr.size();  i++ ){
        for(int j = 0 ; j < arr.size() ; j++ ){
            cout << all_dis[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    while( cin >> n >> x >> y , n && x && y ){
        arr.push_back({n,x,y});
    }
    // dis_map();
    for(int i = 0 ; i < arr.size() ; i++ ){ // 起點
        vector<int> start_point;    
        double total_dis = 0 ; // 從此起點走的總距離
        int now = get<0>(arr[i]);
        set<int> record;
        record.insert(now);
        start_point.push_back(now);
        while(record.size() != arr.size()){
            int min_index = 0 ;
            double min_dis = 1.0*INT_MAX;
            for(int j = 1 ; j <= arr.size() ; j++ ){
                if(!record.count(j)){
                    double p_dis = dis(arr[now-1],arr[j-1]);
                    if( p_dis < min_dis){
                        min_index = j ;
                        min_dis = p_dis ;
                    }
                }
            }
            record.insert(min_index);
            total_dis += min_dis;
            now = min_index ;
            start_point.push_back(now);
        }
        total_dis += dis(arr[start_point.back()-1],arr[i]);
        if(total_dis < ans ){
            ans_point.clear();
            ans_point = start_point;
            ans = total_dis;
        }
    }
    cout << "distance: " << ans << endl;
    for(int i = 0 ; i < ans_point.size() ; i++ ){
        cout << ans_point[i] << endl;
    }
}