// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;
// int power[21] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
// int main(){
//     int times ;
//     cin >> times;
//     while(times--){
//         std::ios::sync_with_stdio(false);
//         std::cin.tie(0);
//         int D , I ;
//         cin >> D >> I ;
//         if( I % 2 == 0 ){
//             cout << power[D-1] * 3 / 2 + I / 2 - 1<< endl;
//         }
//         else{
//             cout << power[D-1] + I / 2  << endl;
//         }
//         // array.push_back(pow(2,D)-1);
//         // cout << array[(I-1) % bound] << endl;
//     }
// }

#include<stdio.h>

int main(){
    int times;
    scanf("%d", &times);
    while(times--){
        int D , I;
        scanf("%d %d", &D , &I);
        I--;
        int ans = 1 ;
        int i;
        for(i = 1 ; i < D ; i++ ){
            if( I & 1 ) ans = ans * 2 + 1;
            else ans = ans * 2;
            I >>= 1 ;
        }        
        printf("%d\n",ans);
    }
}
          