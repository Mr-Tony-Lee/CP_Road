#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<vector<int>> matrix(26);
    int n ; 
    cin >> n ;
    while(n--){
        char name ;
        int r , c;
        cin >> name;
        cin >> r >> c ;
        matrix[name-'A'].push_back(r);
        matrix[name-'A'].push_back(c); 
    }         
    cin.ignore();
    string input ;
    while( getline(cin,input) ){
        stack<int> line ;
        long long int sum = 0 ; 
        bool flag = true ;
        for(int i = 0 ; i < (int)input.size() ; i++ ){
            if(input[i] == '('){
                line.push(-1);   
            }
            else if (input[i] == ')'){
                vector<int> temp ;
                while(line.top() != -1 ){
                    temp.push_back(line.top());
                    line.pop();
                }
                line.pop();
                int row2 = matrix[temp[0]][0];
                int col2 = matrix[temp[0]][1];
                int row1 = matrix[temp[1]][0];
                int col1 = matrix[temp[1]][1];
                if(col1 != row2 ){
                    flag = false ;
                    break;
                }
                else{
                    sum += row1*row2*col2 ;
                    matrix.push_back({row1,col2});
                    line.push(matrix.size()-1);
                }
            }
            else{
                line.push(input[i] - 'A' );
            }
        }
        if(!flag){
            cout << "error" << endl;
        }
        else{
            cout << sum << endl;
        }
    }   
}
//  Accepted online judge.