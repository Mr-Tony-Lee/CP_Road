#include<iostream>
using namespace std;

int* findPtr(int* arr, int N , int target){
    for(int i = 0 ; i < N ; i++ ){
        if(*(arr+i) == target){
            return arr+i;
        }
    }
    return nullptr ;
}

int main(){
    int N ;
    cin >> N ;
    int *arr = new int(N);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    int target ;
    cin >> target; 
    int* result = findPtr(arr, N , target);
    if(result != nullptr){
        cout << "Found at index "<< result-arr << endl;
    }
    else{
        cout << "Not found" << endl;
    }
}