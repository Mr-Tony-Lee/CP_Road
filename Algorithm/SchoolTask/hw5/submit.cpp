#include<bits/stdc++.h>
using namespace std;

struct Node {
    double x, y;
};

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
        double best_distance;
        double average_distance ;
        vector<int> ans_point;
        
};

TSP::TSP(string f ){
    filename = f ;
    N = 0 ;
    best_distance = 0;
    average_distance = 0;
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
    string output_filename = "output_" + filename.substr(filename.find_last_of("/\\") + 1);
    ofstream fout(output_filename);
    fout << "Best Distance: " << fixed << setprecision(3) << best_distance << endl;
    fout << "Average Distance: " << fixed << setprecision(3) << average_distance << endl;
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
    fprintf(gnuplotPipe, "set title 'TSP Elastic Net for %s'\n", dataset_name.c_str());
    fprintf(gnuplotPipe, "set autoscale\n");
    fprintf(gnuplotPipe, "unset key\n");
    
    // Plot the tour
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

void TSP::solve_tsp() {
    file_in();  
   
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
        int s = clock();
        string filename = argv[i];
        TSP tsp(filename);
        tsp.solve_tsp();
        int e = clock();
        cout << "Time: " << (double)(e - s) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Pass: " << filename << endl;
    }
    return 0;
}