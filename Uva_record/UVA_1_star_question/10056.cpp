#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int times ;
    cin >> times;
    while(times--){
        int N ;
        double p ;
        int win;
        cin >> N >> p >> win ; 
        double initial_ans = p; //最一開始的機率
        for(int i = 0 ; i < win-1 ; i++ ){  //比他前面的都必須失敗
            initial_ans *= (double)1-p;
        }
        double next_ans = initial_ans ; //開始計算更精確的機率
        
        double scale = 1 ;  //用來計算一輪全部失敗的機率
        for(int i = 0 ; i < N ; i++ ){  
            scale *= (double)1-p;
        }

        next_ans += scale*initial_ans; //下一次就是上一輪輪全部失敗 + 前一次的機率
        double now_ans = initial_ans;
        while(now_ans != next_ans){ //利用double精確到第6位的特性，如果第六位前都一樣，那就代表第五位已經固定
            now_ans = next_ans ;    
            initial_ans *= scale ;
            next_ans += scale * initial_ans;
        }
        cout << fixed << setprecision(4) << (double)now_ans << endl;    //fixed讓output只控制小數點後，setprecision控制只要4位
    }
}
//3ms, 324KB