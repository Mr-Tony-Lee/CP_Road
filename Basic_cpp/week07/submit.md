第一題:
#include<iostream>
using namespace std; 

int reverse ( int n ){
    int rev = 0 ;
    while( n > 0 ){
        rev = rev * 10 + n % 10 ;
        n = n / 10 ;
    }
    return rev ;
}

bool isPalindrome ( int n ){
    return n == reverse(n) ;
}

int main(){
    int n ;
    cin >> n ;
    if( isPalindrome(n) ){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}


第二題:

#include<iostream>
using namespace std;

void climb(int curr, int target, string path){
    if(target % 3 == 0 ) {
        cout << "no solution" << endl;
        return;
    }
    if(curr == target){
        cout << path << endl;
        return ;
    }
    if(curr > target) return ;
    if((curr + 1) % 3 != 0)
        climb(curr + 1, target, path + to_string(curr + 1) + " ");
    if((curr + 2) % 3 != 0)
        climb(curr + 2, target, path + to_string(curr + 2) + " ");

}

int main(){
    int target;
    cin >> target;
    climb(0, target, "0 ");
    return 0;

}