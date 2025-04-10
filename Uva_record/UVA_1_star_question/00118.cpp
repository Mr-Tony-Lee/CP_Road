#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
class Direc{
    public:
        Direc(int = 0 , int = 0 );
        int x ;
        int y ;
};
Direc::Direc(int x_now , int y_now ): x(x_now),y(y_now){}
int main(){
    int board_x , board_y;
    cin >> board_x >> board_y;
    map<int,Direc*> dir_state;
    Direc* temp_N = new Direc(0,1);
    Direc* temp_E = new Direc(1,0);
    Direc* temp_S = new Direc(0,-1);
    Direc* temp_W = new Direc(-1,0);
    dir_state[0] = temp_N ;
    dir_state[1] = temp_E ;
    dir_state[2] = temp_S ;
    dir_state[3] = temp_W ;
    vector<int> drop_x;
    vector<int> drop_y;
    int initial_x , initial_y;
    char initial_direction;
    while(cin >> initial_x >> initial_y >> initial_direction){        
        cin.ignore();
        string order_set ;
        getline(cin, order_set);
        int now;
        if(initial_direction == 'N'){
            now = 0;
        }
        else if (initial_direction == 'E'){
            now = 1 ;
        }
        else if (initial_direction == 'S'){
            now = 2 ;
        }
        else if (initial_direction == 'W'){
            now = 3 ;
        }
        int x = dir_state[now%4]->x;  
        int y = dir_state[now%4]->y ;     // 0 代表不會動 1代表下次走會+ -1代表下次走會減
        bool flag = true ;
        for(int i = 0 ; i < (int)order_set.size(); i++ ){
            if(order_set[i] == 'R'){
                now++;
                if(now > 3){
                    now = 0 ;
                }
                x = dir_state[now%4]->x;
                y = dir_state[now%4]->y;
            }
            else if (order_set[i] == 'L'){
                now--;
                if(now < 0 ){
                    now = 3 ;
                }
                x = dir_state[now%4]->x;
                y = dir_state[now%4]->y;
            }
            else{
                if(initial_x+x > board_x || initial_y+y > board_y || initial_x+x < 0 || initial_y+y < 0 ){
                    bool jump = false ;
                    for(int i = 0 ; i < (int)drop_x.size() ; i++ ){
                        if(drop_x[i] == (initial_x) && drop_y[i] == (initial_y)){
                            jump = true ;
                            break;
                        }
                    }
                    if(!jump){
                        drop_x.push_back(initial_x);
                        drop_y.push_back(initial_y);
                        flag = false ;
                        break;
                    }
                }
                else{
                    initial_x += x ;
                    initial_y += y ;
                }
            }
        }
        if(now % 4 == 0 ){
            initial_direction = 'N';
        }
        else if (now % 4 == 1 ){
            initial_direction = 'E';
        }
        else if (now % 4 == 2 ){
            initial_direction = 'S';
        }
        else if (now % 4 == 3 ){
            initial_direction = 'W';
        }
        if(flag){ 
            cout << initial_x << " " << initial_y << " " << initial_direction << endl;
        }
        else{
            cout << initial_x << " " << initial_y << " " << initial_direction << " LOST" << endl;
        }
    }
}
//2ms, 300KB