#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
vector<int> prime;
int solve(int N ){
    int bound = sqrt(N);
    int i = 0 ;
    int sum = 1 ;
    int temp = 1 ; 
    while(prime[i] <= bound ){
        if(N % prime[i] == 0 ){
            N /= prime[i];
            sum += temp;
        }
        else{
            i++;
            temp = sum;
        }
        bound = sqrt(N);
    }
    if(N != 1 ){
        if(N != prime[i] ) sum += sum ;
        else sum += temp; 
    }  
    return sum ;
}
// 1 2 
// 1 
// x x 1 
// x x x x 1 
// ............

// 1 2 
// x 2 
// x x x 2
// x x x x x 2
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    prime.push_back(2); 
    double start = clock();
    for(int i = 3 ; i < 32000 ; i++ ){
        if(!(i & 1 )) continue;
        bool flag = false;
        for(int j = 3 ; j <= sqrt(i) ; j+=2 ){
            if(i % j == 0 ){
                flag = true;
                break;
            }
        }
        if(!flag){
            prime.push_back(i);
        }
    }
    double end = clock();
    cout << (end-start)/CLOCKS_PER_SEC << endl;
    int times; 
    cin >> times;
    while(times--){
        int L , U ;
        cin >> L >> U ;
        int ans = -1 ; 
        int max_n;
        for(int i = L ; i <= U ; i++ ){
            if((i & 1) && L != U ) continue;
            int n = solve(i);
            if( n > ans ){
                max_n = i;
                ans = n;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n" , L, U , max_n , ans );
    }
}