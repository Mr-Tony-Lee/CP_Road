#include<bits/stdc++.h>
using namespace std;

class Pokemon{
    public:
        Pokemon(string n , int r , double c ){
            name = n ;
            Rarity = r ;
            CatchRate = c ;
        }
        bool success(int ballPower){
            double CatchScore = ballPower * CatchRate;
            return CatchScore >= Rarity;
        }
        string name;
        int Rarity ;
        double CatchRate;
};

int main(){
    int N;
    cin >> N;
    cin.ignore();
    vector<Pokemon> arr;
    for(int i = 0 ; i < N ; i++ ){
        string n ; int r; double c ;
        cin >> n >> r >> c ;
        arr.push_back(Pokemon(n,r,c));
        cin.ignore();
    }
    int ballPower ;
    cin >> ballPower;
    cin.ignore();

    string target;
    cin >> target;

    for(int i = 0 ; i < N ; i++ ){
        if(arr[i].name == target){
            if(arr[i].success(ballPower)){
                cout << "Caught " << arr[i].name << endl;
            }
            else{
                cout << arr[i].name << " escaped" << endl;
            }
        }
    }
}