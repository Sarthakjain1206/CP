/*
Algorithm to check if a graph is Bipartite: 
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem. 
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS). 
1. Assign RED color to the source vertex (putting into set U). 
2. Color all the neighbors with BLUE color (putting into set V). 
3. Color all neighbor’s neighbor with RED color (putting into set U). 
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 
*/
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
        bool DFSIsBipartite();
        void DFSForBipartite(int u, vector<int> &color, vector<int> &visited);
        
        bool BFSIsBipartite();
        bool BFSForBipartite(int src, vector<int> &color, vector<int> &visited)        
        // bool BFS();
        // bool DFS();
};

// BFS based Solution ===========>

bool BFSForBipartite(int src, vector<int> &color, vector<int> &visited) {
    queue <int> q;
    q.push(src);
    visited[src] = true;
    color[src] = 1;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v: adj[u]) {
            if(color[v] == 0)
                color[v] = color[u] == 1 ? -1 : 1;
            // If we try to color the neighbour of u and we found that it is already colored same as u then bipartite is not possible
            else if(color[v] == color[u]) return false;
            if(!visited[v]) q.push(v);
            visited[v] = true;
        }
    }
    return true;
}
bool BFSIsBipartite(){
    vector<int> color(V, 0);
    vector<int> visited(V, 0);
    
    // color -> 1 (Red Color)
    // color -> -1 (Blue color)
    // color -> 0 (No color)

    for(int i = 0; i < V; i++) {
        if(!visited[i])
        if(!BFSForBipartite(V, i, adj, color, visited)) return false;
    }
    return true;
}
    
// DFS based Solution ======>
bool bipartite = true;
void UnweightedGraph:: DFSForBipartite(int u, vector<int> &color, vector<int> &visited) {
    visited[u] = true;
    
    for(int v: adj[u]) {
        if(color[v] == 0)
            color[v] = color[u] == 1 ? -1 : 1;
        else if(color[v] == color[u]) {
            bipartite = false;
            return;
        }
        if(!visited[v])
            DFSForBipartite(v, color, visited);
    }
}

bool UnweightedGraph::DFSIsBipartite() {
    vector<int> color(V, 0);
    vector<int> visited(V, 0);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]){
            color[i] = 1; // Red color
            DFSForBipartite(i, color, visited);
            if(!bipartite) return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    int i = 0;
    UnweightedGraph g(V);
    while (i++ < E)
    {
        int u, v;
        cin >> u >> v;
        g.addEdgeUnDirected(u, v);
    }
    bool ans = g.isBipartite();
    cout << ans;
    return 0;
}
