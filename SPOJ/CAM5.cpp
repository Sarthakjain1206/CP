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

void DFSUtil(vector<int> adj[], vector<bool> &visited, int u) {
    visited[u] = true;
    for(int v: adj[u]) {
        if(!visited[v])
            DFSUtil(adj, visited, v);
    }
}
int DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if(!visited[i]) {
            count++;
            DFSUtil(adj, visited, i);
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        int V, E;
        cin >> V >> E;
        UnweightedGraph g(V);
        int i = 0;
        while(i++ < E) {
            int u, v;
            cin >> u >> v;
            // --u;
            // --v;
            g.addEdgeUnDirected(u, v);
        }
        cout << DFS(g.adj, g.V) << "\n";

    }
    return 0;
}
