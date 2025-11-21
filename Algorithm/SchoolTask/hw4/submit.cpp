#include<bits/stdc++.h>
using namespace std;


class TSP{
    public:
        TSP(string);  // constructor         
        void file_in(); // file input handling 
        void init();
        void ConstructAntSolution();
        int Roulette_Wheel_Selection();
        void Evaluation();
        void Update_pheromones();
        void file_out();    // file output handling 
        void solve_tsp();   // main function to solve 
        void plot();    // function for ploting 
        double dis(const pair<int, int>&, const pair<int, int>&); 

    private:
        string filename;
        vector<pair<int, int>> arr; // 紀錄 point 的 position 
        vector<vector<double>> point_dis;   // the distance between point(i) and point(j)
        int N;  // 總共有幾個點
        double best_distance;
        double average_distance ;
        vector<int> ans_point;
        
        vector<vector<double>> phermone;
        vector<vector<double>> heuristic; 
        
        int run_times;  // Total number of algorithm runs 
        int iteration;  // Maximum iterations per run 
        int population_size;    // Number of ants 
        int alpha;  // Pheromone importance factor 
        int beta ;  // Heuristic factor 
        int rho;    // Pheromone evaporation rate 
        int Q;      // Constant 

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
}

void TSP::file_out(){
    string output_filename = "output_" + filename;
    ofstream fout(output_filename);
    fout << "Best Distance: " << best_distance << endl;
    fout << "Average Distance: " << average_distance << endl;
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

void TSP::init(){
    // initialize distance matrix and heuristic 
    for(int i = 0 ; i <= N ; i++ ){
        vector<double> row_dis(N+1,0);
        vector<double> row_heuristic(N+1,0);
        for(int j = 1 ; j <= N ; j++ ){
            if( i == 0 ) break;
            row_dis[j] = dis(arr[i],arr[j]);
            row_heuristic[j] = 1/row_dis[j];
        }
        point_dis.push_back(row_dis);
        heuristic.push_back(row_heuristic);
    }

    // initialize pheromone matrix


    
}
int TSP::Roulette_Wheel_Selection(){

}
void TSP::ConstructAntSolution(){
    
}
void TSP::solve_tsp() {
    file_in();
    init();    

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