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
        vector<bool> AP();
        void APUtil(bool visited[], int disc[], int low[], int parent[], vector<bool> &ap, int u);
};

void UnweightedGraph:: APUtil(bool visited[], int disc[], int low[], int parent[], vector<bool> &ap, int u) {
    static int time = 0;
    int children = 0;
    visited[u] = true;

    // Initialize discovered and low values for a node.
    disc[u] = low[u] = ++time;

    // Loop all adjacents of node u.
    for(int v: adj[u]) {
        
        if(!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(visited, disc, low, parent, ap, v);

            low[u] = min(low[u], low[v]);

            // 1st property of root checking
            if(parent[u] == -1 && children > 1)
                ap[u] = true;
            
            // 2nd property, if vertex is not root
            if(parent[u] != -1 and low[v] >= disc[u])
                ap[u] = true;

        }
        else if (v != parent[u]) {
            // If this condition is satisfied then it means there is an back edge from (u -> v) in this case we will update low[u] values because from node u we can reach to node v .

            low[u] = min(low[u], disc[v]);
        }

    }
}

vector<bool> UnweightedGraph::AP() {
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if(!visited[i])
            APUtil(visited, disc, low, parent, ap, i);
    }

    return ap;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    UnweightedGraph g(V);
    int i = 0;
    while (i++ < E)
    {
        int v, u;
        cin >> u >> v;
        g.addEdgeUnDirected(u, v);
    }

    vector<bool> allArticulationPoints = g.AP();
    cout << "\nAll Articulation points (cut-vertices) are: ";
    for (i = 0; i < allArticulationPoints.size(); i++)
        if(allArticulationPoints[i])
            cout << i << " ";

    return 0;
}
