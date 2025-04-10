#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y, s;
    state(int x, int y, int s): x(x), y(y), s(s) {}
};

vector<vector<char>> maze;  // 用來存迷宮的
bool invalidState(state ss, char dir) { // 判斷是否超出邊界 
    int n = maze.size(), m = maze.front().size();
    if (dir == 'N') {
        if (ss.x < ss.s) return true;
        for (int i = 1; i <= ss.s; i++) {
            if (maze[ss.x-i][ss.y] == '#') return true;
        }
    } else if (dir == 'S') {
        if (ss.x > n - ss.s - 1) return true;
        for (int i = 1; i <= ss.s; i++) {
            if (maze[ss.x+i][ss.y] == '#') return true;
        }
    } else if (dir == 'E') {
        if (ss.y > m - ss.s - 1) return true;
        for (int i = 1; i <= ss.s; i++) {
            if (maze[ss.x][ss.y+i] == '#') return true;
        }
    } else if (dir == 'W') {
        if (ss.y < ss.s) return true;
        for (int i = 1; i <= ss.s; i++) {
            if (maze[ss.x][ss.y-i] == '#') return true;
        }
    }
    return false;
}

int t, vis[302][302][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string directions = "NSEW";
int BFS(state initState) {
    queue<state> q;
    q.push(initState);  // push 起點 

    int dpth = 0, sz = 1;   // sz 表示下一步走幾種可能可以走 
    state crnt = q.front(); 
    vis[crnt.x][crnt.y][crnt.s] = t;    // 紀錄 x , y 跟現在的步伐
    while(!q.empty()){
        sz = q.size();
        while (sz--) {
            crnt = q.front(); q.pop();  
            for (int i = 0; i < 4; i++) {
                if (!invalidState(crnt, directions[i])) {
                    state tmp = crnt;
                    tmp.x += dx[i] * tmp.s; // 下一步的 x 
                    tmp.y += dy[i] * tmp.s; // 下一步的 y 
                    tmp.s = (tmp.s < 3 ? tmp.s + 1 : 1);    // 1 -> 2 -> 3 -> 1 -> 2 ... 

                    if (maze[tmp.x][tmp.y] == 'E') return dpth + 1; // 因為是 bfs -> 走到E的步數一定是最少的
                    
                    if (vis[tmp.x][tmp.y][tmp.s] != t) {    // 如果還沒用這個步伐走過
                        q.push(tmp);    // 就走到這個點
                        vis[tmp.x][tmp.y][tmp.s] = t;   // 並記錄  
                    }
                }
            }
       }
       dpth++;
    }
    return -1;  // 沒有走到 E 就 return -1 
}

int main() {
    char c;
    int n, m, x, y;
    scanf("%d", &t);
    memset(vis, -1, sizeof (vis));
    while (t--) {
        scanf("%d %d", &n, &m);
        maze.clear(); maze.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("\n");
            for (int j = 0; j < m; j++) {
                scanf("%c", &c), maze[i].push_back(c);
                if (c == 'S') x = i, y = j;
            }
        }

        int steps = BFS(state(x, y, 1));
        if (steps == -1) printf("NO\n");
        else printf("%d\n", steps);
    }
}
/*
    2
    5 4
    S...
    .#.#
    .#..
    .##.
    ...E
    6 6
    .S...E
    .#.##.
    .#....
    .#.##.
    .####.
    ......
*/