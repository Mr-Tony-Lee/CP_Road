#include<iostream>
#include<cmath>
using namespace std;

long long int reverse( long long int number ){
    long long int ans = 0 ;
    while(number > 0 ){
        ans = ans*10 + number % 10 ;
        number /= 10 ;
    }
    return ans ;
}

bool check_prime( long long int number ){
    for(int i = 2 ; i <= sqrt(number) ; i++ ){
        if(number % i == 0 ){
            return false ;
        }
    }
    return true;
}

int main(){
    long long int number ;
    while(cin >> number ){
        if(check_prime(number) && check_prime(reverse(number)) && reverse(number ) != number ){
            cout << number << " is emirp." << endl;
        }
        else if ((check_prime(number) && !check_prime(reverse(number))) || (check_prime(number) && check_prime(reverse(number)))  ){
            cout << number << " is prime." << endl;
        }
        else if (!check_prime(number)){
            cout << number << " is not prime." << endl;
        }
    }
}
//35ms, 324KB