#include<stdio.h>
#include<math.h>
int prime[3500] ;
int solve(int N ){
    int i = 0 ;
    int sum = 1 ;
    int temp = 1 ; 
    while(prime[i] * prime[i] <= N ){
        while(N % prime[i] == 0 ){
            N /= prime[i];
            sum += temp;
        }
        i++;
        temp = sum;
    }
    if( N != 1 ){
        if(N != prime[i] ) sum += sum ;
        else sum += temp; 
    }  
    return sum ;
}

int main(){
    int count = 1 ; 
    prime[0] = 2 ;
    for(int i = 3 ; i < 32000 ; i++ ){
        int flag = 0 ;
        if(!(i & 1 )) continue;
        for(int j = 0 ; j < count && prime[j]*prime[j] <= i ; j++ ){
            if(i % prime[j] == 0 ){
                flag = 1 ; 
            }
        }
        if(!flag) prime[count++] = i;
    }
    int times; 
    scanf("%d",&times);
    while(times--){
        int L , U ;
        scanf("%d %d", &L , &U);
        int ans = -1 ; 
        int max_n ;        
       for(int i = L ; i <= U ; i++ ){
            if((i & 1) && L != U ) continue;
            int n = solve(i);
            if( n > ans ){
                max_n = i;
                ans = n;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n" , L, U , ans , ans );
    } 
}