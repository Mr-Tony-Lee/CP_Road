#include<bits/stdc++.h>
using namespace std;

// 計算兩點之間的歐幾里得距離
double dis(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    double x1 = get<1>(a), y1 = get<2>(a);
    double x2 = get<1>(b), y2 = get<2>(b);
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// 繪圖函式 (使用 gnuplot 輸出 PNG)
void plot(const vector<int>& ans_point, const vector<tuple<int, int, int>>& original_arr, const string& dataset_name) {
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
        for (const auto& p : original_arr) {
            if (get<0>(p) == n_id) {
                fprintf(gnuplotPipe, "%d %d\n", get<1>(p), get<2>(p));
                break;
            }
        }
    }
    
    // 繪製完畢後，再次輸出第一個點，形成閉合迴路 (TSP)
    if (!ans_point.empty()) {
        int first_n_id = ans_point.front();
        for (const auto& p : original_arr) {
            if (get<0>(p) == first_n_id) {
                fprintf(gnuplotPipe, "%d %d\n", get<1>(p), get<2>(p));
                break;
            }
        }
    }

    fprintf(gnuplotPipe, "e\n"); 
    pclose(gnuplotPipe);
}

void solve_tsp(const string& filename) {

    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << filename << endl;
        return;
    }

    string output_filename = "output_" + filename;
    ofstream fout(output_filename);

    vector<tuple<int, int, int>> arr; // 儲存 (N, X, Y)，N 為編號
    int n, x, y;
    while (fin >> n >> x >> y && (n || x || y)) {
        arr.push_back({n, x, y});
    }
    fin.close();

    if (arr.empty()) {
        fout << "File: " << filename << endl;
        fout << "No data points found." << endl;
        fout.close();
        return;
    }
    
    int N = arr.size(); 
    
    double ans = numeric_limits<double>::max(); //一開始 ans 是無限大
    vector<int> ans_point; // 儲存最佳路徑的點編號 (N)

    for (int i = 0; i < N; i++) { 
        vector<int> current_path;    
        double total_dis = 0; 
        
        int now_id = get<0>(arr[i]); 
        
        set<int> record; // 記錄已訪問的點的 "編號"
        record.insert(now_id);
        current_path.push_back(now_id);
        
        while (record.size() != N) {
            int min_index_id = 0;
            double min_dis = numeric_limits<double>::max();
            
            for (int j = 1; j <= N; j++) { 
                if (!record.count(j)) { 
                    
                    int now_idx = -1;
                    int j_idx = -1;
                    for(int k = 0; k < N; ++k) {
                        if (get<0>(arr[k]) == now_id) now_idx = k;
                        if (get<0>(arr[k]) == j) j_idx = k;
                    }
                    
                    if (now_idx != -1 && j_idx != -1) {
                         double p_dis = dis(arr[now_idx], arr[j_idx]);
                         if (p_dis < min_dis) {
                            min_index_id = j; 
                            min_dis = p_dis;
                        }
                    }
                }
            }
            
            if (min_index_id != 0) {
                record.insert(min_index_id);
                total_dis += min_dis;
                now_id = min_index_id;
                current_path.push_back(now_id);
            } 
            else {
                break;
            }
        }
        
        // 最後一個點回到起點
        int start_idx = -1;
        int last_idx = -1;
        for(int k = 0; k < N; ++k) {
            if (get<0>(arr[k]) == current_path.front()) start_idx = k;
            if (get<0>(arr[k]) == current_path.back()) last_idx = k;
        }

        if (start_idx != -1 && last_idx != -1) {
             total_dis += dis(arr[last_idx], arr[start_idx]);
        }
        
        // 檢查是否為目前找到的最佳解
        if (total_dis < ans) {
            ans_point = current_path;
            ans = total_dis;
        }
    }
    
    fout << "Distance: " << ans << endl;
    for(int i = 0 ; i < (int)ans_point.size() ; i++ ){
        fout << ans_point[i] << endl;
    }
    fout.close();

    plot(ans_point, arr, filename);
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
        solve_tsp(filename);
    }
    return 0;
}