#include <bits/stdc++.h>
using namespace std;

class DSU { // disjoint set union 
    private:
        vector<int> parent, rank;

    public:
        DSU(int n) {
            parent.resize(n + 1);   // 每一個點最上面的root
            rank.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) parent[i] = i;  // 初始化 
        }

        int find(int x) {
            if (parent[x] != x) {   // 只有遇到 root 的時候會停止
                parent[x] = find(parent[x]);  // 路徑壓縮    把 parent都連到 root 
            }
            return parent[x];
        }

        void unite(int x, int y) { 
            int rootX = find(x), rootY = find(y);   // 兩個的 root 
            if (rootX != rootY) {   // 如果兩個的root不一樣
                if (rank[rootX] > rank[rootY]) {    // 那就比rank，我們要把rank較小的(樹比較小的) 變成 rank較大的(樹比較大的) 子樹
                    parent[rootY] = rootX;  // 原本root的parent是自己，現在接到另外一個樹的root上
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }

        bool connected(int x, int y) {
            return find(x) == find(y);  // 只要 root 一樣，就一定有連結
        }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    string blank;
    getline(cin, blank);
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        DSU dsu(n); // create disjoint set union 
        int correct = 0, incorrect = 0;

        string line;
        while (getline(cin, line) && !line.empty()) {
            char type;
            int a, b;
            stringstream ss(line);
            ss >> type >> a >> b;

            if (type == 'c') {
                dsu.unite(a, b);
            } else if (type == 'q') {
                if (dsu.connected(a, b)) {
                    correct++;
                } else {
                    incorrect++;
                }
            }
        }
        cout << correct << "," << incorrect << endl;
        if (t) cout << endl;
    }
    return 0;
}

/*
    解題說明 : 
        使用 disjoint set union 解題，不然可能會TLE，
        我們要知道所有的連結，我們就用樹的概念，如果 1 7 有連結，
        那假設 7 是 root ， 那如果 2 7 和 3 7 也有連結， 那 1 2 3 就是 7 的子樹，那此時1 2 , 2 3 , 1 3 也有連結(同一棵樹)
        然後如果有另一棵樹要合併 ex  5, 6 , 7 , 8 (8是root)，那就比較兩棵樹的大小，小的就被合併 -> 1,2,3,5,6,7, 8 變一棵樹，且 8 是root
        最後就當 q 輸入時，判斷root是不是一樣，就能判斷有沒有連結
*/

/*
2

10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

1
q 1 1
c 1 1
q 1 1


*/