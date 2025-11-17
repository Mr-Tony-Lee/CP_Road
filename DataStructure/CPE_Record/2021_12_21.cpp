#include<bits/stdc++.h>
using namespace std;
#define int long long   //之後的int都是Long long 的範圍

void question_a(){  // 1260 Sales
    int t;
    cin >> t ;
    while(t-- ){
        int n ; 
        cin >> n ;
        vector<int> array ;
        for(int i = 0 ; i < n ; i++){
            int x;
            cin >> x ;
            array.push_back(x);
        }
        int sum = 0 ;
        for(int i = 1 ; i < n ; i++ ){
            for(int j = 0 ; j < i ; j++ ){
                if(array[j] <= array[i]){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
}

void question_b(){  // 11728 Alternate Task
    int S ; 
    map<int,int> array;
    for(int i = 1000 ; i >= 1 ; i-- ){
        int sum = 0 ; 
        for(int j = 1 ; j <= i ; j++ ){
            if( i % j == 0 ){
                sum += j ; 
            }
        }
        array[i] = sum ; 
    }
    int count = 1 ; 
    while(cin >> S && S ){
        bool flag = true;
        for(auto iter = array.rbegin() ; iter != array.rend() ; iter++ ){
            if(iter->second == S ){
                cout << "Case " << count << ": " << iter->first << endl;
                flag = !flag;
                break;
            }
        }      
        if(flag)  cout << "Case " << count << ": " << -1 << endl;      
        ++count;
    }
}

void question_c(){  // 118 Mutant Flatworld Explorers

}

void question_d(){  // 11078 Open Credit System
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        vector<int> array;
        for(int i = 0 ; i < n ; i++ ){
            int x ;
            cin >> x;
            array.push_back(x);
        }
        int max = array[0];
        int ans = INT_MIN;
        for(int i = 1 ; i < n ; i++ ){
            if(max - array[i] > ans ){
                ans = max-array[i];
            }
            if( array[i] > max ){
                max = array[i];
            }
        }
        cout << ans << endl;
    }
}

void question_e(){  // 10800 Not That Kind of Graph
    char table[106][55];

  int now, up, down, len;
  int N, cnt = 0;
  cin >> N;
  string s;

  while (N--) {
    cin >> s;
    now = up = down = 53;
    len = s.length();
    for (int i = 0; i < 106; ++i) {
      for (int j = 0; j < 54; ++j)
        table[i][j] = ' ';
      table[i][54] = '\0';
    }

    for (int i = 0; i < len; ++i) {
      switch (s[i]) {
      case 'R':
        if (i && s[i - 1] == 'R')
          ++now;
        table[now][i] = '/';
        break;
      case 'F':
        if (i && s[i - 1] != 'R')
          --now;
        table[now][i] = '\\';
        break;
      case 'C':
        if (i && s[i - 1] == 'R')
          ++now;
        table[now][i] = '_';
        break;
      }
      if (now > up)
        up = now;
      if (now < down)
        down = now;
    }
    //消後面空白
    for (int i = up; i >= down; --i) {
      for (int j = len; j > 0; --j) {
        if (table[i][j] == ' ')
          table[i][j] = '\0';
        else
          break;
      }
    }

    cout << "Case #" << ++cnt << ":" << endl;
    for (int i = up; i >= down; --i) {
      cout << "| ";
      cout << table[i] << endl;
    }
    cout << '+';
    for (int i = 0; i < len + 2; ++i)
      cout << '-';
    cout << endl << endl;
  }
}

void question_f(){  // 11792 Krochanska is Here! // 真的不會QQ

}

void question_g(){  // 12911 Subset sum
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int N, T, si[41];
    map<int , int> Ca, Cb;
    while (cin >> N >> T){

        for (int i = 0; i < N; i++) cin >> si[i];
        
        // 把 進來的數列拆成兩個部分， 前半部分是Na，後半部分是Nb 

        int Na = N / 2;
        if (Na == 0) Na++;  //如果Na是0 代表陣列只有一個，那就只跑Ca就好了
        int Nb = N - Na;
        
        Ca.clear(); //先clear Ca 
        for (int i = 1; i < (1 << Na); i++) {   // 我們要窮舉出所有集合的總和 >> 如果前半部分有Na個，那就是2^Na次方種組合
            long long sum = 0;
            for (int j = 0; j < Na; j++)    // 我們現在 i = 5 , 代表我們會用到101 >> 陣列中的第0個 跟陣列中的第2個元素去組成一種集合
                if (i & (1 << j))       // 那我們用 j 跑過整個Na ， 如果 j = 001(第0個) 和 100(第二個)，我們就相加 
                    sum += si[j];
            Ca[sum]++;  
        }
        
        Cb.clear();
        for (int i = 1; i < (1 << Nb); i++){    //從1開始是因為沒有000 ( 全部都沒用 ) 
            long long sum = 0;
            for (int j = 0; j < Nb; j++)
                if (i & (1 << j))
                    sum += si[Na + j];  //陣列的後半段
            Cb[sum]++;
        }
        
        long long cnt = 0;
        for (auto p : Ca)
            if (Cb.count(T - p.first))  
                cnt += 1LL * p.second * Cb[T - p.first];

        cout << cnt + Ca[T] + Cb[T] << endl;    //看有沒有剛好等於這個數的集合
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    // question_a();
    // question_b();
    // question_c();
    // question_d();
    // question_e();
    // question_f();
    // question_g();
}