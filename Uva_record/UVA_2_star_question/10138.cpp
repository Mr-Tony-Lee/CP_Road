#include<bits/stdc++.h>
using namespace std;


class License{
    public:
        string car ;
        int time;   // 24 * 60 * day + 60 * hour + mins ;
        string status;
        int location ;
        int fare; 
};

bool cmp(License a , License b ){
    if(a.car != b.car){
        return a.car < b.car ;
    }
    return a.time < b.time;
}

int main(){
    int kase;
    cin >> kase ;
    while(kase--){
        vector<int> arr;
        for(int i = 0 ; i < 24 ; i++ ){
            int x ; 
            cin >> x ;
            arr.push_back(x);
        }
        cin.ignore();
        string input ;
        License photo[1000];
        int index = 0; 
        while(getline(cin,input) && input.length() > 0 ){
            stringstream ss ; 
            ss << input ;
            string date;
            ss >> photo[index].car >> date;
            
            photo[index].time = atoi(date.substr(3,2).data()) * 24 * 60 ;
            photo[index].time += atoi(date.substr(6,2).data()) * 60 ;
            photo[index].time += atoi(date.substr(9,2).data());

            ss >> photo[index].status >> photo[index].location;
            
            photo[index].fare = arr[atoi(date.substr(6,2).data())];

            index++;
        }
        sort(photo, photo+1000);
        
        if(kase) cout << endl;
    }
}
