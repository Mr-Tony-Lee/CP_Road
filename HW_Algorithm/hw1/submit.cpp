#include<bits/stdc++.h>
using namespace std;


double dis(tuple<int,int,int> a , tuple<int,int,int> b ){
    double x1 = get<1>(a) , y1 = get<2>(a);
    double x2 = get<1>(b) , y2 = get<2>(b);
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}


void plot(const vector<int>& ans_point, const vector<tuple<int,int,int>>& original_arr, const string& dataset_name ){
    
    FILE *gnuplotPipe = popen("gnuplot","w"); 
    if(!gnuplotPipe) {
        cerr << "Error: Gnuplot popen failed for " << dataset_name << endl;
        return;
    }

    fprintf(gnuplotPipe, "set terminal pngcairo\n");
    fprintf(gnuplotPipe, "set output 'fig_%s.png'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set xrange [0:100]\n");
    fprintf(gnuplotPipe, "set yrange [0:100]\n");
    fprintf(gnuplotPipe, "unset key\n");
    fprintf(gnuplotPipe, "plot '-' lt 7 lc -1 w lp\n");

    // 依據最佳路徑 ans_point (點的編號) 輸出座標
    for(int n_id : ans_point){
        // 從原始點列表 (original_arr) 中找到編號為 n_id 的點
        for(const auto& p : original_arr){
            if(get<0>(p) == n_id){
                fprintf(gnuplotPipe, "%d %d\n", get<1>(p), get<2>(p));
                break;
            }
        }
    }
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

    // 設定輸出檔案名稱
    string output_filename = "output_" + filename;
    ofstream fout(output_filename);
    
    // original_arr 儲存所有點的數據 (N, X, Y)
    vector<tuple<int,int,int>> original_arr; 
    int n , x , y ;
    
    while( fin >> n >> x >> y && (n || x || y) ){
        original_arr.push_back({n,x,y});
    }
    fin.close();

    if (original_arr.empty()) {
        fout << "File: " << filename << endl;
        fout << "No data points found." << endl;
        fout.close();
        return;
    }

    vector<int> indices(original_arr.size(), 0);
    for(int i = 0 ; i < indices.size() ; i++ ){
        indices[i] = i ;
    }
    
    double ans = numeric_limits<double>::max() ;
    vector<int> ans_point; 

    do{
        double sum_dis = 0 ; 
        
        for(size_t i = 0 ; i < indices.size() ; i++ ){
            int current_idx = indices[i];
            int next_idx = indices[(i + 1) % indices.size()];
            
            sum_dis += dis(original_arr[current_idx], original_arr[next_idx]);
        }
        
        if(sum_dis < ans){
            ans_point.clear();
            for(int idx : indices){
                ans_point.push_back(get<0>(original_arr[idx])); 
            }
            ans = sum_dis;
        }
    }while(next_permutation(indices.begin(), indices.end())); 

    fout << "Distance: "<< ans << endl;
    for(int i = 0 ; i < (int)ans_point.size() ; i++ ){
        fout << ans_point[i] << endl;
    }
    fout.close();

    // 繪圖
    plot(ans_point, original_arr, filename);
}

int main(int argc, char* argv[]){
    if(argc < 2){
        cerr << "Usage: " << argv[0] << " <input_file_1> [input_file_2] ..." << endl;
        return 1;
    }

    for(int i = 1; i < argc; ++i) {
        string filename = argv[i];
        solve_tsp(filename);
    }
    
    return 0;
}