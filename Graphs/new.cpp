#include<bits/stdc++.h>
using namespace std;

class UnweightedGraph {
    int V;
    vector<int> *adj;
    public:
        UnweightedGraph(int V) {
            this->V = V;
            adj = new vector<int>[V];
        }
        void addEdgeDirected(int u, int v) {
            adj[u].push_back(v);
        }
        void addEdgeUnDirected(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // bool BFS();
        // bool DFS();
};
bool isSafe(vector<vector<int>> &grid, int i, int j) {
    if(i>= 0 and i < grid.size() and j >= 0 and j < grid[0].size() && grid[i][j] != 0) {
        return true;
    }
    return false;
}
int solve(vector<vector<int>> &grid) {
    // queue<pair<int, int>> q;
    // q.push({0, 0);

    // while(!q.empty()) {
    //     pair<int, int> p = q.front();
    //     q.pop();
    //     int i = p.first;
    //     int j = p.second;
    //     if(isSafe(grid, i, j + 1))
    //         q.push({i, j+1});
    //     if(isSafe(grid, i+1, j))
    //         q.push({i+1, j});
    //     if(isSafe(grid, i, j - 1))
    //         q.push({i, j-1});
    //     if(isSafe(grid, i - 1, j))
    //         q.push({i - 1, j});
        
    // }
    
}

int main(int argc, char const *argv[])
{
    int 
    return 0;
}
