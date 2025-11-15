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