#include<bits/stdc++.h>
using namespace std;

struct Ant {
    vector<int> path;
    double tour_length;
};

class TSP{
    public:
        TSP(string, string = "" ,int = 100 , int = 10000 , int = 10000 ,int = 30 , double = 1.0 , double = 3.0 , double = 0.1 , double = 100);  // constructor         
        void file_in(); // file input handling 
        void init();
        void ConstructAntSolution();
        int Roulette_Wheel_Selection(int current_node, const vector<bool>& visited);
        void Update_pheromones();
        void file_out();    // file output handling 
        void solve_tsp();   // main function to solve 
        void ApplyLocalSearch(vector<int>& path); // 2-OPT Local Search
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
        
        vector<vector<double>> phermone;
        vector<vector<double>> heuristic; 
        vector<vector<double>> heuristic_pow; // Precomputed heuristic^beta
        
        vector<Ant> ants;

        int run_times;  // Total number of algorithm runs 
        int iteration;  // Maximum iterations per run 
        int max_evaluation; // Maximum evaluation times per run 
        int population_size;    // Number of ants 
        double alpha;  // Pheromone importance factor 
        double beta ;  // Heuristic factor 
        double rho;    // Pheromone evaporation rate 
        double Q;      // Constant 

};

TSP::TSP(string f ,string out ,int run , int iter , int max_eval,int population , double a , double b , double r , double q ){
    filename = f ;
    if (out == "") 
        output_filename = "output_" + filename.substr(filename.find_last_of("/\\") + 1);
    else
        output_filename = out;

    N = 0 ;
    best_distance = 1e18;
    average_distance = 0;

    // Parameters
    run_times = run;
    iteration = iter;
    max_evaluation = max_eval;
    population_size = population;
    alpha = a;
    beta = b;
    rho = r;
    Q = q;
    cout << "------------ Now parameters ------------" << endl;
    cout << "output_name : " << output_filename << endl;
    cout << "run_times : " << run_times << endl;
    cout << "iteration : " << iteration << endl;
    cout << "max_evaluation : " << max_evaluation << endl;
    cout << "population_size : " << population_size << endl;
    cout << "alpha : " << alpha << endl;
    cout << "beta : " << beta << endl;
    cout << "rho : " << rho << endl;
    cout << "Q : " << Q << endl;
    cout << "---------------------------------------" << endl;
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
    
    arr.clear();
    arr.push_back({0,0});   // 不需要的 point 為了使後面的東西對齊
    N = 0;
    int n, x, y;
    
    while (fin >> n >> x >> y) {
        arr.push_back({x,y});
        N++;
    }
    fin.close();
}

void TSP::file_out(){
    ofstream fout(output_filename);
    fout << "Mean Distance: " << fixed << setprecision(3) << average_distance << endl;
    fout << "Distance: " << fixed << setprecision(3) << best_distance << endl;
    for(int i = 0 ; i < (int)ans_point.size() ; i++ ){
        fout << ans_point[i] << endl;
    }
    fout.close();
}

void TSP::plot() {
    string dataset_name = filename.substr(0,filename.size()-4);
    size_t last_slash = dataset_name.find_last_of("/\\");
    if (last_slash != string::npos) dataset_name = dataset_name.substr(last_slash + 1);

    FILE *gnuplotPipe = popen("gnuplot", "w"); 
    if (!gnuplotPipe) {
        // cerr << "Error: Gnuplot popen failed" << endl;
        return;
    }
    fprintf(gnuplotPipe, "set terminal pngcairo\n");
    fprintf(gnuplotPipe, "set output 'fig_%s.png'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set title 'TSP ACO for %s'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set autoscale\n");
    fprintf(gnuplotPipe, "unset key\n");
    
    fprintf(gnuplotPipe, "plot '-' lt 7 lc -1 w lp\n"); 

    for (int n_id : ans_point) {
        fprintf(gnuplotPipe, "%d %d\n", arr[n_id].first, arr[n_id].second);
    }
    
    if (!ans_point.empty()) {
        int first_n_id = ans_point.front();
        fprintf(gnuplotPipe, "%d %d\n", arr[first_n_id].first, arr[first_n_id].second);
    }

    fprintf(gnuplotPipe, "e\n"); 
    pclose(gnuplotPipe);
}

void TSP::init(){
    point_dis.assign(N + 1, vector<double>(N + 1, 0.0));
    heuristic.assign(N + 1, vector<double>(N + 1, 0.0));
    heuristic_pow.assign(N + 1, vector<double>(N + 1, 0.0));

    for(int i = 1 ; i <= N ; i++ ){
        for(int j = 1 ; j <= N ; j++ ){
            if (i == j) continue;
            point_dis[i][j] = dis(arr[i], arr[j]);
            if (point_dis[i][j] > 1e-9)
                heuristic[i][j] = 1.0 / point_dis[i][j];
            else 
                heuristic[i][j] = 1e9; 
            
            heuristic_pow[i][j] = pow(heuristic[i][j], beta);
        }
    }

    // Initialize pheromone matrix
    phermone.assign(N + 1, vector<double>(N + 1, 0.1));
    
    // Initialize ants
    ants.resize(population_size);
}

// 螞蟻在選擇下一個城市時，依據機率進行選擇
int TSP::Roulette_Wheel_Selection(int current_node, const vector<bool>& visited){
    vector<double> probs(N + 1, 0.0);
    double sum_prob = 0.0;

    for (int next = 1; next <= N; ++next) {
        if (!visited[next]) {
            double tau = phermone[current_node][next];
            // Optimized: use precomputed heuristic_pow and avoid pow(tau, 1.0)
            double p = tau * heuristic_pow[current_node][next]; 
            if (alpha != 1.0) p = pow(tau, alpha) * heuristic_pow[current_node][next];
            
            probs[next] = p;
            sum_prob += p;
        }
    }

    if (sum_prob == 0) {
        for (int i = 1; i <= N; ++i) if (!visited[i]) return i;
        return -1;
    }

    double r = (double)rand() / RAND_MAX * sum_prob;
    double p = 0.0;
    for (int next = 1; next <= N; ++next) {
        if (!visited[next]) {
            p += probs[next];
            if (p >= r) return next;
        }
    }
    
    for (int i = 1; i <= N; ++i) if (!visited[i]) return i;
    return -1;
}


void TSP::ConstructAntSolution(){
    // Reuse existing ants vector
    for (int k = 0; k < population_size; ++k) {
        vector<bool> visited(N + 1, false);
        ants[k].path.clear();
        double length = 0.0;
        
        // 每隻螞蟻從隨機城市出發
        int start_node = rand() % N + 1;
        int current_node = start_node;
        ants[k].path.push_back(current_node);
        visited[current_node] = true;

        for (int step = 1; step < N; ++step) {
            // 使用 Roulette_Wheel_Selection ，根據機率選擇下一個城市
            int next_node = Roulette_Wheel_Selection(current_node, visited);
            ants[k].path.push_back(next_node);
            length += point_dis[current_node][next_node];
            visited[next_node] = true;
            current_node = next_node;
        }
        length += point_dis[current_node][start_node];
        
        ants[k].tour_length = length;
    }
}

void TSP::Update_pheromones(){
    // 所有路徑上的費洛蒙乘以 (1−ρ)，模擬費洛蒙隨時間消散。
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            phermone[i][j] *= (1.0 - rho);
        }
    }

    // 根據每隻螞蟻走過的路徑長度，在路徑上增加費洛蒙
    for (const auto& ant : ants) {
        double delta = Q / ant.tour_length;
        for (size_t i = 0; i < ant.path.size(); ++i) {
            int u = ant.path[i];
            int v = ant.path[(i + 1) % ant.path.size()];
            phermone[u][v] += delta;
            phermone[v][u] += delta; 
        }
    }
}

// ACO 找到最佳解後，使用 2-OPT 演算法進一步優化路徑
// 若交換兩條邊能縮短路徑長度 -> 交換
void TSP::ApplyLocalSearch(vector<int>& path) {
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 2; j < N; ++j) {
                // Check if edge (i, i+1) and (j, j+1) can be swapped
                // Indices in path
                int u_idx = i;
                int v_idx = (i + 1) % N;
                int x_idx = j;
                int y_idx = (j + 1) % N;

                // Avoid adjacent edges in cycle (already handled by j loop range, but check wrap around)
                if (y_idx == u_idx) continue; 

                int u = path[u_idx];
                int v = path[v_idx];
                int x = path[x_idx];
                int y = path[y_idx];

                double d1 = point_dis[u][v];
                double d2 = point_dis[x][y];
                double d3 = point_dis[u][x];
                double d4 = point_dis[v][y];

                if (d1 + d2 > d3 + d4 + 1e-9) {
                    // Reverse segment from v_idx to x_idx
                    reverse(path.begin() + i + 1, path.begin() + j + 1);
                    improved = true;
                }
            }
        }
    }
}

void TSP::solve_tsp() {
    file_in();
    srand(time(NULL));
    
    double total_best = 0;
    best_distance = 1e18;
    max_evaluation *= N ;

    for (int run = 0; run < run_times; ++run) {
        init(); 
        
        double run_best = 1e18;
        vector<int> run_best_path;
        int stagnation = 0;

        for (int iter = 0; iter < iteration; ++iter) {
            ConstructAntSolution();

            for (auto& ant : ants) {
                ApplyLocalSearch(ant.path);
                double length = 0.0;
                for (size_t i = 0; i < ant.path.size(); ++i) {
                    length += point_dis[ant.path[i]][ant.path[(i + 1) % ant.path.size()]];
                }
                ant.tour_length = length;
            }

            Update_pheromones();
            
            // 在這次 iteration 中找到最佳解
            double current_iter_best = 1e18;
            vector<int> current_iter_best_path;

            for (const auto& ant : ants) {
                if (ant.tour_length < current_iter_best) {
                    current_iter_best = ant.tour_length;
                    current_iter_best_path = ant.path;
                }
            }

            if (current_iter_best < run_best) {
                run_best = current_iter_best;
                run_best_path = current_iter_best_path;
                stagnation = 0;
            } else {
                stagnation++;
            }

            if (stagnation > 50) break; // Early stopping
        }
        // 更新 總路徑長 跟 最佳解
        total_best += run_best;
        if (run_best < best_distance) {
            best_distance = run_best;
            ans_point = run_best_path;
        }
    }

    average_distance = total_best / run_times;

    // Apply Local Search to the best solution found
    ApplyLocalSearch(ans_point);
    
    // Recalculate best_distance after local search
    best_distance = 0;
    for(size_t i = 0; i < ans_point.size(); ++i) {
        int u = ans_point[i];
        int v = ans_point[(i + 1) % ans_point.size()];
        best_distance += point_dis[u][v];
    }

    file_out();
    plot();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <dataset> <output_name> <run_times> <evaluation_max> <population_size> <alpha> <beta> <rho> <Q>" << endl;
        return 1;
    }
    string filename = argv[1];
    string outfile = "" ;
    int run_times = 30;  // Total number of algorithm runs 
    int iteration = 10000;  // Maximum iterations per run 
    int max_evaluation = 10000; // Maximum evaluation times per run 
    int population_size = 30 ;    // Number of ants 
    double alpha = 1.0;  // Pheromone importance factor 
    double beta = 3.0;  // Heuristic factor 
    double rho = 0.1;    // Pheromone evaporation rate 
    double Q = 100;      // Constant 
    for(int i = 1 ; i < argc ; i++ ){
        if ( i == 1 ) filename = argv[i];
        if ( i == 2 ) outfile = argv[i];
        if ( i == 3 ) run_times = stoi(argv[i]);
        if ( i == 4 ) iteration= stoi(argv[i]);
        if ( i == 5 ) max_evaluation = stoi(argv[i]);
        if ( i == 6 ) population_size = stoi(argv[i]);
        if ( i == 7 ) alpha = stod(argv[i]);
        if ( i == 8 ) beta = stod(argv[i]);
        if ( i == 9 ) rho = stod(argv[i]);
        if ( i == 10 ) Q = stod(argv[i]);
    }

    int s = clock();
    TSP tsp(filename, outfile, run_times, iteration, max_evaluation, population_size, alpha, beta, rho, Q);
    tsp.solve_tsp();
    int e = clock();
    cout << "Pass: " << filename << endl;
    cout << "Time: " << (double)(e - s) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << endl;
    return 0;
}