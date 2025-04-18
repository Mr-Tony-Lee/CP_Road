#include<bits/stdc++.h>
using namespace std;
class DSU{ 
    public:
        vector<int> parent ;
        vector<int> rank;
        DSU(int n ){
            parent.resize(n+1,0);
            rank.resize(n+1,0);
            for(int i = 0 ; i < n+1 ; i++ ){
                parent[i] = i ;
            }
        }
        int find( int x ){
            if(parent[x] != x ){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x , int y ){
            int rootx = find(x) , rooty = find(y);
            if(rootx != rooty){
                if(rank[rootx] > rank[rooty]){
                    parent[rooty] = rootx;
                }
                else if (rank[rootx] < rank[rooty]){
                    parent[rootx] = rooty;
                }
                else{
                    parent[rooty] = rootx;
                    rank[rootx] ++ ;
                }
            }
        }
        bool connect(int x , int y ){
            return find(x) == find(y);
        }
};

int main(){
    cin.tie(0) ; cout.tie(0); ios::sync_with_stdio(0);
    int kase = 1 ; 
    while(1){
        bool flag = false ;
        int x , y ;
        bool state = true ;
        vector<bool> used(100000,false);
        DSU dsu(100000);
        while(cin >> x >> y ){
            if( x == y && y == 0 ){
                break;
            }
            if(x == y && y == -1 ){
                flag = true ;
                break ;
            }
            if(dsu.connect(x,y)){
                state = false ;
            }
            if(state){
               used[x] = used[y] = true ;
               dsu.unite(x,y); 
            }
        }
        if(flag) break;
        if(state){
            bool two_root = false;
            for(int i = 0 ; i < 100000 ; i++ ){
                if(used[i] && dsu.parent[i] == i ){
                    if(two_root){
                        state = false;
                        break;
                    }
                    two_root = true ;
                }
            }
        }   
        cout << "Case " << kase++ << " ";
        if(state) cout << "is a tree." << endl;
        else cout << "is not a tree." << endl;
    }
}

/*

6 8 5 3 5 2 6 4
5 6 0 0
8 1 7 3 6 2 8 9 7 5
7 4 7 8 7 6 0 0
3 8 6 8 6 4
5 3 5 6 5 2 0 0 -1 -1
*/
/**
 * @file 00615.cpp
 * @brief Determines if a given set of edges forms a tree for multiple test cases.
 * 
 * This program reads multiple test cases where each test case consists of pairs of integers
 * representing directed edges in a graph. The program determines if the graph formed by these
 * edges is a tree. A tree is defined as a connected acyclic graph with exactly one root.
 * 
 * The program uses a Disjoint Set Union (DSU) data structure to efficiently manage connected
 * components and detect cycles in the graph.
 * 
 * @details
 * - Input:
 *   - Each test case consists of pairs of integers (x, y) representing directed edges.
 *   - A pair (0, 0) marks the end of a test case.
 *   - A pair (-1, -1) marks the end of input.
 * - Output:
 *   - For each test case, the program outputs whether the graph is a tree or not.
 * 
 * @class DSU
 * @brief A Disjoint Set Union (Union-Find) data structure with path compression and union by rank.
 * 
 * @method DSU::DSU(int n)
 * Initializes the DSU with `n` elements.
 * 
 * @method int DSU::find(int x)
 * Finds the representative (root) of the set containing `x` with path compression.
 * 
 * @method void DSU::unite(int x, int y)
 * Unites the sets containing `x` and `y` using union by rank.
 * 
 * @method bool DSU::connect(int x, int y)
 * Checks if `x` and `y` belong to the same set.
 * 
 * @function main
 * The main function reads input, processes each test case, and determines if the graph is a tree.
 * 
 * @variables
 * - `kase`: Tracks the test case number.
 * - `flag`: Indicates if the end of input is reached.
 * - `state`: Tracks whether the current graph satisfies the tree properties.
 * - `used`: A boolean vector to track which nodes are used in the graph.
 * - `dsu`: An instance of the DSU class to manage connected components.
 * 
 * @example
 * Input:
 * 6 8 5 3 5 2 6 4
 * 5 6 0 0
 * 8 1 7 3 6 2 8 9 7 5
 * 7 4 7 8 7 6 0 0
 * 3 8 6 8 6 4
 * 5 3 5 6 5 2 0 0 -1 -1
 * 
 * Output:
 * Case 1 is a tree.
 * Case 2 is not a tree.
 * Case 3 is not a tree.
 * Case 4 is a tree.
 */