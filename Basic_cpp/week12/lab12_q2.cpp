#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

void reverseArray(int *left , int* right ){
    while(left < right){
        swap(*left,*right);
        left++;
        right--;
    }
    
}

int main(){
    int N ;
    cin >> N ;
    int *arr = new int(N);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    reverseArray(arr, arr+N-1);
    for(int i = 0 ; i < N ; i++){
        if(i != 0 )
            cout << " " << arr[i] ;
        else
            cout << arr[i];
    }
    cout << endl;
}