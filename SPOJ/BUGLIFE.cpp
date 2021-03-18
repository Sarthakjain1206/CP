/*
This problem is simple Bipartite Graph checking problem.
If bipartite graph:
    No suspicious bug found
else:
    Suspicious bug found
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

        bool isBipartite();
        bool isBipartiteUtil(int u, vector<int> &color, vector<bool> &visited);
        // bool BFS();
        // bool DFS();
};

bool UnweightedGraph::isBipartiteUtil(int u, vector<int> &color, vector<bool> &visited) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    color[u] = 1;

    while(!q.empty()) {
        int src = q.front();
        q.pop();

        for(int v: adj[src]) {
            if(color[v] == -1) {
                color[v] = color[src] == 1 ? 0 : 1;
            }
            else if(color[v] == color[src])
                return false;
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return true;
}

bool UnweightedGraph::isBipartite() {
    vector<bool> visited(V, false);
    vector<int> color(V, -1);

    for(int i = 0; i < V; i++) {
        if(!visited[i])
        if(!isBipartiteUtil(i, color, visited)) return false;
    }
    return true;

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int itr = 1; itr <= t; itr++)
    {
        int V, E;
        cin >> V >> E;
        UnweightedGraph g(V);
        int i = 0;
        while(i++ < E) {
            int v, u;
            cin >> u >> v;
            --u;
            --v;
            g.addEdgeUnDirected(u, v);
        }
        cout << "Scenario #" << itr << ":\n";
        if(g.isBipartite())
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
    return 0;
}
