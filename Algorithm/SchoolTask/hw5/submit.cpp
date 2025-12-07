#include<bits/stdc++.h>
using namespace std;

struct Node {
    double x, y;
};

class TSP{
    public:
        TSP(string, string, int, int, int, double, double, double);  // constructor         
        void file_in(); // file input handling 
        void file_out();    // file output handling 
        void solve_tsp();   // main function to solve 
        void plot();    // function for ploting 
        double dis(const pair<int, int>&, const pair<int, int>&); 

    private:
        string filename;
        string output_filename;
        vector<pair<int, int>> arr; // 紀錄 point 的 position 
        vector<vector<double>> point_dis;   // the distance between point(i) and point(j)
        int N;  // 總共有幾個點
        double best_distance;
        double average_distance ;
        vector<int> ans_point;

        // Elastic Net helpers
        double dist_sq(const Node& a, const pair<int, int>& b);
        vector<int> get_tour(const vector<Node>& network);
        double calculate_tour_distance(const vector<int>& tour);
        void create_gif(const vector<vector<Node>>& history);

        // parameters 
        int runs;  // Total number of algorithm runs
        int max_iter;   // Maximum iterations per run
        int M ;  // Number of nodes in the elastic net
        double K;   // Elasticity coefficient
        double alpha;   // Learning rate
        double beta;    // Smoothing factor
        
};

TSP::TSP(string f , string out , int run , int iter , int m , double k , double a , double b  ){
    filename = f ;
    if (out == "") 
        output_filename = "output_" + filename.substr(filename.find_last_of("/\\") + 1);
    else
        output_filename = out;
    runs = run;
    max_iter = iter;
    M = m ; // number of nodes in the elastic net
    K = k ;
    alpha = a ;
    beta = b ;

    N = 0 ; // number of points
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
    ofstream fout(output_filename);
    fout << "Mean Distance: " << average_distance << endl;
    fout << "Distance: " << best_distance << endl;
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
    fprintf(gnuplotPipe, "set title 'TSP Elastic Net Result for %s'\n", dataset_name.c_str());
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
    
    double global_best_dist = 1e18;
    vector<int> global_best_tour;
    vector<vector<Node>> global_best_history;
    double sum_best_dist = 0;
    
    if (M == 0 ){
        M = max((int)(N * 2.5), 20); 
    }
    
    // 計算 城市的重心
    double cx = 0, cy = 0;
    for (int i = 1; i <= N; ++i) {
        cx += arr[i].first;
        cy += arr[i].second;
    }
    cx /= N;
    cy /= N;


    for (int run = 0; run < runs; ++run) {
        vector<Node> network(M);

        // 在中心點周圍建立一個圓形的彈性網路，包含 M 個節點
        for (int j = 0; j < M; ++j) {
            // 增加一些擾動，讓每次初始化都不一樣
            double angle = 2.0 * acos(-1) * j / M;
            double r = 10.0 + ((double)rand() / RAND_MAX) * 2.0; // Radius varies slightly
            double noise_angle = ((double)rand() / RAND_MAX - 0.5) * 0.1; // Angle varies slightly
            network[j] = {cx + r * cos(angle + noise_angle), cy + r * sin(angle + noise_angle)};
        }
        
        // 參數傳入
        double run_K = K; 
        double run_alpha = alpha;
        double run_beta = beta;
        int run_max_iter = max_iter; 
        
        // 記錄每次迭代的網路狀態以便後續製作 GIF
        vector<vector<Node>> current_history;
        
        for (int iter = 0; iter < run_max_iter; ++iter) {
            
            // 50 個iteration 記錄一次網路狀態
            if (iter % 50 == 0) {
                current_history.push_back(network);
            }
            
            // 計算每個點對每個節點的影響力 w_ij
            vector<vector<double>> w(N + 1, vector<double>(M));
            for (int i = 1; i <= N; ++i) {
                double sum_phi = 0;
                for (int j = 0; j < M; ++j) {
                    double d2 = dist_sq(network[j], arr[i]);
                    // exp(-d^2 / (2*K^2))
                    double phi = exp(-d2 / (2 * run_K * run_K));
                    w[i][j] = phi;
                    sum_phi += phi;
                }
                // 正規化 w_ij
                for (int j = 0; j < M; ++j) {
                    if (sum_phi > 1e-9) w[i][j] /= sum_phi;
                    else w[i][j] = 1.0 / M;
                }
            }
            
            // 更新網路節點位置
            vector<Node> new_network = network;
            for (int j = 0; j < M; ++j) {
                double delta_x = 0, delta_y = 0;
                
                // 吸引力 -> 城市將節點拉向自己
                for (int i = 1; i <= N; ++i) {
                    delta_x += w[i][j] * (arr[i].first - network[j].x);
                    delta_y += w[i][j] * (arr[i].second - network[j].y);
                }
                delta_x *= run_alpha;
                delta_y *= run_alpha;
                
                // 彈性力 -> 相鄰節點彼此拉近，試圖縮短路徑長度
                int prev = (j - 1 + M) % M;
                int next = (j + 1) % M;
                delta_x += run_beta * run_K * (network[next].x - 2 * network[j].x + network[prev].x);
                delta_y += run_beta * run_K * (network[next].y - 2 * network[j].y + network[prev].y);
                
                new_network[j].x += delta_x;
                new_network[j].y += delta_y;
            }
            network = new_network;
            // 每次迭代後降低溫度 K，讓變動越來越小 -> 收斂
            run_K = max(0.01, run_K * 0.99);
        }
        
        // 迭代結束後，將每個城市指派給網路上距離最近的節點，形成最終路徑
        vector<int> tour = get_tour(network);
        double dist = calculate_tour_distance(tour);
        
        // 累積各次運行的最佳距離以計算平均值
        // 並更新全局最佳解
        sum_best_dist += dist;
        if (dist < global_best_dist) {
            global_best_dist = dist;
            global_best_tour = tour;
            global_best_history = current_history;
        }
    }
    
    best_distance = global_best_dist;
    average_distance = sum_best_dist / runs;
    ans_point = global_best_tour;
    
    file_out();
    plot();
    create_gif(global_best_history);
}

double TSP::dist_sq(const Node& a, const pair<int, int>& b) {
    return (a.x - b.first) * (a.x - b.first) + (a.y - b.second) * (a.y - b.second);
}

// 根據彈性網路的節點位置，為每個城市分配最近的節點，形成一條巡迴路徑
vector<int> TSP::get_tour(const vector<Node>& network) {
    vector<int> tour;
    vector<pair<int, int>> city_node_map; 
    for (int i = 1; i <= N; ++i) {
        double min_d = 1e18;
        int best_node = -1;
        for (int j = 0; j < (int)network.size(); ++j) {
            double d = dist_sq(network[j], arr[i]);
            if (d < min_d) {
                min_d = d;
                best_node = j;
            }
        }
        city_node_map.push_back({best_node, i});
    }
    sort(city_node_map.begin(), city_node_map.end());
    for (auto p : city_node_map) tour.push_back(p.second);
    return tour;
}

double TSP::calculate_tour_distance(const vector<int>& tour) {
    double d = 0;
    if (tour.empty()) return 0;
    for (size_t i = 0; i < tour.size(); ++i) {
        d += dis(arr[tour[i]], arr[tour[(i + 1) % tour.size()]]);
    }
    return d;
}

void TSP::create_gif(const vector<vector<Node>>& history) {
    string dataset_name = filename.substr(0, filename.size() - 4);
    FILE *gnuplotPipe = popen("gnuplot", "w");
    if (!gnuplotPipe) {
        cerr << "Error: Gnuplot popen failed for GIF" << endl;
        return;
    }
    fprintf(gnuplotPipe, "set terminal gif animate delay 10 size 800,800\n");
    fprintf(gnuplotPipe, "set output 'evolution_%s.gif'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set xrange [0:100]\n");
    fprintf(gnuplotPipe, "set yrange [0:100]\n");
    fprintf(gnuplotPipe, "unset key\n");
    
    for (const auto& net : history) {
        fprintf(gnuplotPipe, "plot '-' with lines lc rgb 'blue', '-' with points pt 7 lc rgb 'red'\n");
        for (const auto& node : net) fprintf(gnuplotPipe, "%f %f\n", node.x, node.y);
        if (!net.empty()) fprintf(gnuplotPipe, "%f %f\n", net[0].x, net[0].y);
        fprintf(gnuplotPipe, "e\n");
        for (int i = 1; i <= N; ++i) fprintf(gnuplotPipe, "%d %d\n", arr[i].first, arr[i].second);
        fprintf(gnuplotPipe, "e\n");
    }
    pclose(gnuplotPipe);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <dataset> <output_name> <run_times> <max_iteration> <M> <K> <alpha> <beta>" << endl;
        return 1;
    }
    string filename = argv[1];
    string outfile = "" ;
    int run_times = 30;  // Total number of algorithm runs
    int max_iter = 1000;   // Maximum iterations per run
    int M = 0;  // Number of nodes in the elastic net
    double K = 20.0;   // Elasticity coefficient
    double alpha = 0.2;   // Learning rate
    double beta = 0.01;    // Smoothing factor
    for(int i = 1 ; i < argc ; i++ ){
        if ( i == 2 ) outfile = argv[i];
        if ( i == 3 ) run_times = stoi(argv[i]);
        if ( i == 4 ) max_iter= stoi(argv[i]);
        if ( i == 5 ) M = stoi(argv[i]); 
        if ( i == 6 ) K = stod(argv[i]);
        if ( i == 7 ) alpha = stod(argv[i]);
        if ( i == 8 ) beta = stod(argv[i]);
    }
    srand(time(NULL));

    cout << "------------ Now parameters ------------" << endl;
    cout << "output_name : " << outfile << endl;
    cout << "run_times : " << run_times << endl;
    cout << "max_iteration : " << max_iter << endl;
    cout << "M : " << M << endl;
    cout << "K : " << K << endl;
    cout << "alpha : " << alpha << endl;
    cout << "beta : " << beta << endl;
    cout << "---------------------------------------" << endl;

    int s = clock();
    TSP tsp(filename, outfile, run_times, max_iter, M, K, alpha, beta);
    tsp.solve_tsp();
    int e = clock();
    cout << "Time: " << (double)(e - s) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Pass: " << filename << endl;

    return 0;
}
