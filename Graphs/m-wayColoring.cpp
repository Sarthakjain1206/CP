#include<bits/stdc++.h>
using namespace std;

class UnweightedGraph {
    public:
        int V;
        vector<int> *adj;
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

class WeightedGraph {
    int V;
    vector<pair<int, int>> *adj;
    // vector<vector<int>> *adj;    // Or this. (but better is with pair<>)

    public:
        WeightedGraph(int V) {
            this->V = V;
            adj = new vector<pair<int, int>>[V];
        }
        void addEdgeDirected(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
        }
        void addEdgeUnDirected(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        // bool BFS();
        // bool DFS();
        vector<int> dijkastra(int S);
};

//HEADLINE: BFS based solution: O(V + E). If we need to find in total how many ways we can solve the m-way coloring problem then, we need to solve it using Backtracking approach which takes exponential time.
bool ans = true;
void graphColoringUtil(vector<int> adj[], vector<bool> &visited, vector<int> &color, int m, int src, int V) {
    // cout<<"SRC: "<<src<<endl;
    queue<int> q;
    visited[src] = true;    
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            // cout<<j<<endl;
            if(color[v] == color[u])    color[v]++;
            
            if(color[v] > m or color[u] > m){
                // cout<<"Im in\n";
                ans = false;
                return;
            }
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool graphColoring(vector<int> adj[], int m, int V) {
    // your code here
    vector<int> color(V, 1);
    vector<bool> visited(V, false);
    // for(int i = 1; i <= V; i++) {
    //     for(int j = 1; j <= V; j++) {
    //         cout<<graph[i-1][j-1]<<" ";
    //     }
    //     cout<<endl;
    // }    
    // cout<<endl;
    for(int i = 0; i < V; i++) {
        if(!visited[i]){
            graphColoringUtil(adj, visited, color, m, i, V);
            if(!ans) return false;
        }
    }
    return true;
}




int main(int argc, char const *argv[])
{
    int V,E;
    cin >> V >> E;
    UnweightedGraph g(V);
    int m;
    cin >> m;

    int i = 0;
    while(i++ < E) {
        int u, v;
        cin >> u >> v;
        g.addEdgeUnDirected(u - 1, v - 1);
    }

    cout<< graphColoring(g.adj, m, V);

    return 0;
}
