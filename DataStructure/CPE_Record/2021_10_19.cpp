#include<bits/stdc++.h>
using namespace std;
#define int long long
using llu = unsigned int ;


void question_a(){ // 12959 Strategy Game 
    int J , R ;
    while(cin >> J >> R && ( J || R )){
        map<int,int> score;
        for(int i = 0 ; i < R ; i++ ){
            for(int j = 0 ; j < J ; j++ ){
                int x ;
                cin >> x ;
                score[j] += x ;
            }
        }
        int max_s = 0  , max_idx = 0 ;
        for(auto iter:score ){
            if(iter.second >= max_s ){
                max_s = iter.second;
                max_idx = iter.first;
            }
        }
        cout << max_idx+1 << endl;
    }

}

void question_b(){  // 10222 Decode the Mad man 

}

llu gcd(llu a , llu b ){
    if( b == 0 ) return a ;
    
    if ( a > b ){
        return gcd(b , a%b);
    }
    else {
        return gcd(a , b%a);
    }
}

void fraction(llu x , llu y ){
    if(x % y == 0 ) cout << x/y << endl;
    else{
        cout << x/gcd(x,y) << "/" << y/gcd(x,y) << endl;
    }
}
void question_c(){  // 12869 Alcoholic Pilots
    llu v1 , d1 , v2 , d2 , t1 , t2 ;
    int count = 1 ;
    while(cin >> v1 >> d1 >> v2 >> d2 && (v1 || d1 || v2 || d2 )){
        t1 = d1 * v2 ;
        t2 = d2 * v1 ; 
        cout << "Case #" << count++ << ": ";
        if (t2 > t1 ){
            cout << "You owe me a beer!" << endl;
        }
        else{
            cout << "No beer for the captain." << endl;
        }
        cout << "Avg. arrival time: ";
        fraction(v1*d2+v2*d1 , v1*v2*2);
    }
}


void question_d(){  // 12869 Zeroes 
    int l , h;
    while(cin >> l >> h && (l || h)){
        int count_l = l / 5 ;
        int count_h = h / 5 ; 
        cout << count_h - count_l + 1 << endl;
    }
}

void question_e(){  // 380 call forwarding 

}


void question_f(){  // 11258 string partition 
    int T ; 
    cin >> T;
    cin.ignore();
    while(T--){
        string input ;
        getline(cin,input);
        int DP[210] = {0}; // 算 0 ~ i-1 degit最大值的情況
        for (int i = 0; i < input.size(); ++i) {    
            if (input[i] == '0') {
                DP[i + 1] = max(DP[i + 1], DP[i]);
            } else {
                int sum = 0;
                for (int j = i; j < input.size(); ++j) {    // 算 digit i~j 的總和
                    sum = sum * 10 + (input[j] - '0'); 
                    if (sum > INT_MAX)  //如果大於32-bit 的話就直接停掉
                        break;                               
                    DP[j + 1] = max(DP[j + 1], DP[i] + sum); //更新這一個digit的和，要就是已經在裡面的(0~i)，或者是(0~i-1 + i~j )
                }
            }
        }
        cout << DP[input.size()] << endl; // 最後的答案就是 DP[input.size] -> 0~input.size的digit 
    }
}

void question_g(){  // 437 The Tower of Babylon

}

int32_t main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    // question_a();
    // question_b();
    // question_c();
    // question_d();
    // question_e();
    // question_f();
    // question_g();
}
