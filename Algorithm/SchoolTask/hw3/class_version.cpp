#include<bits/stdc++.h>
using namespace std;


class TSP{
    public:
        TSP(string);  // constructor         
        void file_in(); // file input handling 
        void file_out();    // file output handling 
        void solve_tsp();   // main function to solve 
        void plot();    // function for ploting 
        double dis(const pair<int, int>&, const pair<int, int>&); 

    private:
        string filename;
        vector<pair<int, int>> arr; // 紀錄 point 的 position 
        vector<vector<double>> point_dis;   // the distance between point(i) and point(j)
        int N;  // 總共有幾個點
        double final_distance ; // 最後的答案
        vector<int> ans_point;

};

TSP::TSP(string f ){
    filename = f ;
    N = 0 ;
}

double TSP::dis(const pair<int, int>& a, const pair<int, int>& b) {
    double x1 = a.first, y1 = a.second;
    double x2 = b.first, y2 = b.second;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void TSP::file_in(){
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << filename << endl;
        return;
    }
    
    arr.push_back({0,0});   // 不需要的 point 為了使後面的東西對齊
    int n, x, y;
    
    while (fin >> n >> x >> y && (n || x || y)) {
        arr.push_back({x,y});
        N++;
    }
    fin.close();

    for(int i = 0 ; i <= N ; i++ ){
        vector<double> row(N+1,0);
        for(int j = 1 ; j <= N ; j++ ){
            if( i == 0 ) break;
            row[j] = dis(arr[i],arr[j]);
        }
        point_dis.push_back(row);
    }
    // for(int i = 1 ; i <= N ; i++ ){
    //     for(int j = 1 ; j <= N ; j++ ){
    //         cout << point_dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void TSP::file_out(){
    string output_filename = "output_" + filename;
    ofstream fout(output_filename);
    fout << "Distance: " << final_distance << endl;
    for(int i = 0 ; i < (int)ans_point.size() ; i++ ){
        fout << ans_point[i] << endl;
    }
    fout.close();
}

void TSP::plot() {
    string dataset_name = filename.substr(0,filename.size()-4);
    // 使用 popen/pclose (適用於 Linux/WSL)
    FILE *gnuplotPipe = popen("gnuplot", "w"); 
    if (!gnuplotPipe) {
        cerr << "Error: Gnuplot popen failed for " << dataset_name << endl;
        return;
    }
    // 設置輸出為 PNG 檔案
    fprintf(gnuplotPipe, "set terminal pngcairo\n");
    fprintf(gnuplotPipe, "set output 'fig_%s.png'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set title 'TSP Nearest Neighbor Heuristic for %s'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set xrange [0:100]\n");
    fprintf(gnuplotPipe, "set yrange [0:100]\n");
    fprintf(gnuplotPipe, "unset key\n");
    
    // 繪製最佳路徑 (使用 linespoints 樣式)
    fprintf(gnuplotPipe, "plot '-' lt 7 lc -1 w lp\n"); 

    // 依據最佳路徑 ans_point (點的編號 N) 輸出座標
    for (int n_id : ans_point) {
        // 查找原始資料中編號為 n_id 的點        
        fprintf(gnuplotPipe, "%d %d\n", arr[n_id].first, arr[n_id].second);
    }
    
    // 繪製完畢後，再次輸出第一個點，形成閉合迴路 (TSP)
    if (!ans_point.empty()) {
        int first_n_id = ans_point.front();
        fprintf(gnuplotPipe, "%d %d\n", arr[first_n_id].first, arr[first_n_id].second);
    }

    fprintf(gnuplotPipe, "e\n"); 
    pclose(gnuplotPipe);
}

void TSP::solve_tsp() {
    file_in();
    vector<vector<double>> ans (N+1,vector<double>(1<<N,0));
    vector<vector<int>> ans_map(N+1,vector<int>(1<<N,0));   // 紀錄來源的狀態 
    // 用 bit-wise 的方式去看走了哪幾個點

    for(int i = 2 ; i <= N ; i++ ){
        ans[i][0] = point_dis[i][1];
        ans_map[i][0] = 1 ; 
    }
    // 一開始都先把1拿掉
    for(int k = 1 ; k <= N-2 ; k++){    // 會有 k 個 bit 啟動， K-2的原因是假設一開始有5個點 
        //-> 我最後的答案是 g(1,{2,3,4,5}) 那我只需要用到 g(2,{3,4,5}) ,g(3,{2,4,5}) , g(4,{2,3,5}), g(5,{2,3,4}) -> 只有 n-2 = k 個 bit 啟動  
        for(int i = 2 ; i <= N ;i++ ){  // start_point (必沒有 1 )
            for(int j = 0 ; j < (1<<N) ; j++ ){
                bitset<20> b(j);
                // 假設目前5個點 -> bitset = 00000 (代表54321是否啟動) 
                if( j & 1 ) continue;
                // j 右邊的第 i-1 bit 要是 0 因為她是起點 
                double min = INT_MAX;
                if((int)b.count() == k && ((1 << (i-1)) & j) == 0 ){
                    int temp = 1 ; 
                    for(int m = 1 ; m <= N ; m++ ){  // 把 第 m 個bit 屏蔽掉  ，也就是上一個start g(i,{m}) = min{c_im+g(m,{})};
                        // cout << k << " " << i << " " << j << " " << m << " "<< endl;
                        //     54321
                        // j = 11010
                        // 會拆成 
                        // 11000 , temp = 00010 , j^temp = 11000
                        // 10010 , temp = 01000
                        // 01010 , temp = 10000
                        if((j & temp) != 0 ){
                            double temp_ans = point_dis[i][m]+ans[m][temp^j];
                            if(temp_ans < min){
                                min = temp_ans ;
                                ans[i][j] = temp_ans;
                                // ans_map[i][j] = ans_map[m][temp^j];
                                ans_map[i][j] = m;
                            }
                        }
                        temp <<= 1 ;
                    }
                }
            }
        }
    }
    // cout << "pre calculate end " << endl;
    // 最後起點是 1 
    int remain_set = ((1 << N ) - 1) ^ 1 ; // remain_set = 11110 if N = 5  
    double min = INT_MAX;
    for(int j = 2 ; j <= N ; j++ ){  // j = 00010 , 00100, 01000 , 10000
        int m = remain_set ^ (1<<(j-1)) ; // m = V-{j}
        // cout << j << " " << m << endl;
        double temp_ans = point_dis[1][j] + ans[j][m];
        if(temp_ans < min ){
            min = temp_ans ;
            ans[1][remain_set] = temp_ans ;
            ans_map[1][remain_set] = j;
        }
    }
    // for(int i = 0 ; i <= N ; i++ ){
    //     for(int j = 0 ; j < (1<<N) ; j++){
    //         cout << ans[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 0 ; i <= N ; i++ ){
    //     for(int j = 0 ; j < (1<<N) ; j++){
    //         cout << ans_map[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    final_distance = ans[1][remain_set];

    int start = 1 ;
    while(ans_map[start][remain_set] != 0 ){
        ans_point.push_back(start);
        start = ans_map[start][remain_set];
        remain_set ^= (1<<(start-1));
    }
    ans_point.push_back(1);
    // reverse(ans_point.begin(), ans_point.end());
    file_out();
    plot();
}


int main(int argc, char* argv[]) {
    // 檢查是否有傳入檔案參數
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file_1> [input_file_2] ..." << endl;
        return 1;
    }

    // 迴圈處理所有傳入的檔案
    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        TSP tsp(filename);
        tsp.solve_tsp();
        cout << "Pass: " << filename << endl;
    }
    return 0;
}