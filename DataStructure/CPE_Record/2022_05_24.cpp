#include<bits/stdc++.h>
using namespace std;
#define int long long 

void question_a(){  // 10190 Divide, But Not Quite Conquer!

}

void question_b(){  // 11000 Bee
    int N ;
    while(cin >> N && ( N != -1 )){
        int now_male = 0  , now_female = 0 ;
        int total_male = 0 , total_female = 0 ;
        for(int i = 0 ; i < N ; i++ ){
            total_female = now_male;
            total_male = (now_male+now_female);
            // magic female
            total_male++;
            now_male = total_male;
            now_female = total_female;
        }
        cout << total_male << " " << total_male+total_female+1 << endl;
    }
}

void question_c(){  // 	12592 Slogan Learning of Princess
    int N , Q ;
    cin >> N ;
    cin.ignore();
    map<string,string> a ;
    for(int i = 0 ; i < N ; i++ ){
        string first, second ;
        getline(cin, first);
        getline(cin, second);
        a[first] = second;
    }
    cin >> Q;
    cin.ignore();
    while(Q--){
        string input; 
        getline(cin, input);
        cout << a[input] << endl;
    }
}

void question_d(){  // 1640 The Counting Problem
    int a , b ;
    while(cin >> a >> b && ( a || b )){
            
    }

}

int32_t main(){
   cin.tie(0);
   cout.tie(0) ;
   ios::sync_with_stdio(false);
   //question_b();
   //question_c();
   question_d();
}  