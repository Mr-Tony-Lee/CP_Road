#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> Find_Max_Crossing_Subarray(vector<int> A , int low , int mid , int high ){
    int left_sum = INT32_MIN;
    int sum = 0 ; 
    int max_left;
    for(int i = mid ; i >= low ; i-- ){
        sum = sum + A[i];
        if (sum > left_sum ){
            left_sum = sum ;
            max_left = i ;
        }
    }
    int right_sum = INT32_MIN;
    sum = 0 ; 
    int max_right;
    for(int i = mid+1 ; i <= high ; i++ ){
        sum = sum + A[i];
        if (sum > right_sum ){
            right_sum = sum ;
            max_right = i ;
        }
    }
    return {max_left, max_right, left_sum+right_sum};
}

int main(){

}
