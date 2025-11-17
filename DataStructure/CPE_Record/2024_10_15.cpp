#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

ll power(ll x , int y ){
    ll sum = 1 ;
    while(y){
        if(y & 1) sum *= x ;
        x *= x ;
        y >>= 1 ;
    }
    return sum ; 
}
void question4(){
    int size = 1000000;
    bool *map = new bool[size];
    memset(map , false , size);
    vector<ll> prime ;
    for(int i = 2 ; i < size; i++ ){
        if(!map[i]){
            prime.push_back(i);
            for(int j = i*i ; j < size ; j += i ){
                map[j] = true;
            }
        }
    }
    ll l = 1 , h = 1000000000000;
    ll array[80070];
    int count = 0 ; 
    for(int i = 0 ; i < (int)prime.size() && prime[i]*prime[i] <= h ; i++ ){
        ll h_loop = h ; 
        int k = 0 ;
        while(h_loop != 0 ){
            h_loop /= prime[i];
            k++;
        }
        for(int j = k ; j > 1 && power(prime[i],j) >= l ; j-- ){
            ll num = power(prime[i] , j);
            if(num >= l && num <= h ){
                array[count++] = num ; 
            }
        }
    }
    int times ;
    cin >> times ;
    while(times--){
        ll l , h ; 
        cin >> l >> h ;
        int ans = 0 ;
        for(int i = 0 ; i < count ; i++ ){
            if(array[i] <= h && array[i] >= l ){
                ans ++ ;
            }
        }
        cout << ans << endl;
    } 
}

void question3(){
    int n ;
    while(cin >> n ){
        if( (double)(sqrt(n)) == (int)(sqrt(n))){
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;
    }
}

void question2(){
    int n ;
    vector<int> a ;
    while( cin >> n ){
        a.push_back(n);
        sort(a.begin(), a.end());
        if(a.size() & 1 ){
            int middle = a[a.size()/2];
            cout << middle << endl;
        }
        else{
            int middle1 = a[a.size()/2], middle2 = a[a.size()/2-1];
            cout << (middle1 + middle2)/2 << endl;
        }
    }   
}

double power(double x , int y ){
    double ans = 1 ;
    for(int i = 0 ; i < y ; i++ ){
        ans *= x ;
    }
    return ans ;
}

double dis(double x1, double y1, double z1,double x2, double y2,double z2){
    return sqrt(power(x1-x2,2)+power(y1-y2,2)+power(z1-z2,2));
}

void question5(){
    string input ;
    while(cin >> input){
        double x1,y1,z1,x2,y2,z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int n ;
        cin >> n ;
        
        double dis_p1_p2 = dis(x1,y1,z1,x2,y2,z2);

        double sphere[10][4];
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < 4 ; j++ ){
                cin >> sphere[i][j];
            }
        }
        double dis_mid_p1[10];
        double dis_mid_p2[10];
        for(int i = 0 ; i < n ; i++ ){
            dis_mid_p1[i] = dis(sphere[i][0],sphere[i][1],sphere[i][2],x1,y1,z1);
            dis_mid_p2[i] = dis(sphere[i][0],sphere[i][1],sphere[i][2],x2,y2,z2);
        }
        double cos[10];
        double sin[10];
        double dis_mid_v[10];
        bool wh[10] = {0};
        for(int i = 0 ; i < n ; i++ ){
            cos[i] = (power(dis_mid_p2[i],2)+power(dis_p1_p2,2)-power(dis_mid_p1[i],2))/(2*dis_mid_p2[i]*dis_p1_p2);
            sin[i] = sqrt(1-power(cos[i],2));
            dis_mid_v[i] = dis_mid_p2[i] * sin[i];
            if(dis_mid_v[i] < sphere[i][3]){
                wh[i] = true;
            }
        }
        double ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(wh[i]){
                ans += 2*sqrt(power(sphere[i][3],2)-power(dis_mid_v[i],2));
            }
        }
        cout << input << endl;
        cout << fixed << setprecision(2) << 100 * ans / dis_p1_p2 << endl;
    }
}

int main(){
    question2();
    question3();
    question4();
    question5();    
}