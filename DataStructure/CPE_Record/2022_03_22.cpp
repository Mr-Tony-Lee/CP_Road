#include<bits/stdc++.h>
using namespace std;
using ll = long long ;


void question_a(){
    ll s ;
    vector<int> table ;
    for(int i = 0 ; i <= 20000 ; i++ ){
        table.push_back((i*(i+1))/2);
    }
    while( cin >> s ){
        if(!s) return;
        auto iter = upper_bound(table.begin(), table.end() , s);
        cout << *iter-s << " " << iter-table.begin() << endl;
    }
}

void question_b(){  // 10642 - Can You Solve It?
    int n ;
    cin >> n ;
    int count = 1 ;
    while(n--){
        int x1 , y1 , x2 , y2;
        ll ans = 0 ;
        cin >> x1 >> y1 >> x2 >> y2 ;

        for(int i = x1+y1+1 ; i < x2+y2 ; i++ ){    //中間
            ans += i ; 
        }
        if(x1+y1 == x2+y2) ans += x2-x1 ; 
        else{
            ans += x2+y2 - x1-y1 ; 
            ans += x2 ; 
            ans += y1 ;
        }
        cout << "Case " << count << ": " << ans << endl;
        count ++;
    }
}

void question_c(){  // 13171 Pixel Art
    int n ;
    cin >> n ;
    while(n--){
        int m , y , c ;
        cin >> m >> y >> c;
        string need;
        cin >> need;
        map<char, vector<int>> table; 
        table['M'] = {1,0,0};
        table['Y'] = {0,1,0};
        table['C'] = {0,0,1};
        table['R'] = {1,1,0};
        table['V'] = {1,0,1};
        table['G'] = {0,1,1};
        table['B'] = {1,1,1};
        table['W'] = {0,0,0};

        for(int i = 0 ; i < (int)need.size() ; i++){
            m -= table[need[i]][0];
            y -= table[need[i]][1];
            c -= table[need[i]][2];
        }
        if( m < 0 || y < 0 || c < 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES " << m << " " << y << " " << c << endl;
        }   
    }
}

void question_d(){  // 11360 Having Fun with Matrices
    int n ;
    cin >> n ;
    int count = 1; 
    while(n--){
        int N ;
        cin >> N ; 
        vector<vector<int>> matrix;
        for(int i = 0 ; i < N ; i++ ){
            vector<int> row; 
            string input;
            cin >> input ;
            for(int j = 0; j < N ; j++ ){
                row.push_back(input[j]-'0') ;
            }
            matrix.push_back(row);
        }
        int M ;
        cin >> M ; 
        while(M--){
            fflush(stdin);
            string input ;
            cin >> input ;
            if(input[0] == 'r'){
                int a , b ;
                cin >> a >> b ;
                for(int i = 0 ; i < N ; i++ ){
                    swap(matrix[a-1][i], matrix[b-1][i]);
                }
            }
            else if ( input[0] == 't'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < i ; j++ ){
                        swap(matrix[i][j] , matrix[j][i]);
                    }
                }
            }
            else if (input[0] == 'i'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < N ; j++ ){
                        matrix[i][j]++;
                        matrix[i][j] %= 10 ;
                    }
                }
            }
            else if (input[0] == 'd'){
                for(int i = 0 ; i < N ; i++ ){
                    for(int j = 0 ; j < N ; j++ ){
                        matrix[i][j]--;
                        if(matrix[i][j] < 0 ){
                            matrix[i][j] += 10 ;
                        }
                    }
                }
            }
            else if (input[0] == 'c'){
                int a , b ;
                cin >> a >> b ;
                for(int i = 0 ; i < N ; i++ ){
                    swap(matrix[i][a-1], matrix[i][b-1]);
                }
            }
        }
        cout << "Case #" << count << endl;
        for(int i = 0 ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j++ ){
                cout << matrix[i][j];
            }
            cout << endl;
        }
        cout<< endl;
        count ++ ;
    }
}
map<ll,ll> solve(map<ll,ll> base , map<ll,ll> multi){
    map<ll,ll> ans ; 
    for(auto iter1:multi){
        for(auto iter2:base){
            ans[iter1.first+iter2.first] += iter1.second*iter2.second;
        }
    }
    return ans ; 
}
void question_e(){
    int n ;
    while(cin >> n ){
        vector<int> root ;
        for(int i = 0 ; i < n ; i++ ){
            int x ;
            cin >> x ;
            root.push_back(-x);
        }
        map<ll,ll> now;
        now[1] = 1 ;
        now[0] = root[0];

        map<ll,ll> pow_coe; 
        for(int i = 1 ; i < n ; i++ ){
            pow_coe[1] = 1 ;
            pow_coe[0] = root[i];
            now = solve(now , pow_coe);
        }
        
        for(auto iter = now.rbegin(); iter != now.rend() ; iter++  ){
            if(iter->first != 0 && iter->second == 0 ){
                continue;
            }
            else if (iter->first == 0 ){
                if(iter->second == 0 ){
                    cout << "+ 0 " ;
                }
                else{
                    if(iter->second < 0 ){
                        cout << "- " << abs(iter->second) << " ";
                    }
                    else{
                        cout << "+ " << abs(iter->second) << " ";
                    }
                }
            }
            else if (iter->first == n ){
                if(n == 1 ){
                    cout << "x" << " ";
                }
                else{
                    cout << "x^" << iter->first << " ";
                }
            }
            else if (iter->first == 1 ){
                if(iter->second < 0 ){
                    if(abs(iter->second) == 1 ){
                        cout << "- " << "x " ;
                    }
                    else{
                        cout << "- " << abs(iter->second) << "x " ;
                    }
                }
                else{
                    if(abs(iter->second) == 1 ){
                        cout << "+ " << "x " ;
                    }
                    else{
                        cout << "+ " << abs(iter->second) << "x " ;
                    }
                }
            }

            else if (iter->second != 0 ){
                if(iter->second < 0 ){
                    if(abs(iter->second) == 1 ){
                        cout << "- " << "x^" << iter->first << " " ;
                    }
                    else {
                        cout << "- " << abs(iter->second) << "x^" << iter->first << " " ;
                    }
                }
                else{
                    if(abs(iter->second) == 1 ){
                        cout << "+ " << "x^" << iter->first << " " ;
                    }
                    else {
                        cout << "+ " << abs(iter->second) << "x^" << iter->first << " " ;
                    }
                }
            }
        }
        cout << "= 0" << endl;
    }
}

ll solve_f(int K , int row ){
    if (row == 0 ){ 
        return 0;
    }

    if(K == 0 ){
        return 1 ;
    }
    if(row > pow(2,K-1)){
        return solve_f( K-1 , row-pow(2 , K-1)) + 2 * pow(3,K-1) ;
    }
    else{
        return 2 * solve_f(K-1 , row);
    }
}

void question_f(){  // 12627 Erratic Expansion
    int T;
    cin >> T;
    int count = 1 ;
    while(T--){
        int K , A , B ; 
        cin >> K >> A >> B ;
        cout << "Case " << count << ": " << solve_f(K,B) - solve_f(K,A-1) << endl;  
        count++;
    }
}

int main(){
    // question_a();
    // question_b();
    // question_c();
    // question_d();
    // question_e();
    // question_f();
}
