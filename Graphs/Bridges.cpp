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
        vector<pair<int, int>> bridges();
        void bridgesUtil(bool visited[], int disc[], int low[], int parent[], vector<pair<int, int>> &bridgesList, int u);

        // bool BFS();
        // bool DFS();
};

void UnweightedGraph:: bridgesUtil(bool visited[], int disc[], int low[], int parent[], vector<pair<int, int>> &bridgesList, int u) {
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
            bridgesUtil(visited, disc, low, parent, bridgesList, v);

            low[u] = min(low[u], low[v]);
            
            // 2nd property, if vertex is not root
            if(low[v] > disc[u])
                bridgesList.push_back({u, v});
        }
        else if (v != parent[u]) {
            // If this condition is satisfied then it means there is an back edge from (u -> v) in this case we will update low[u] values because from node u we can reach to node v .

            low[u] = min(low[u], disc[v]);
        }

    }
}

vector<pair<int, int>> UnweightedGraph::bridges() {
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    vector<pair<int, int>> bridgesList;

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if(!visited[i])
            bridgesUtil(visited, disc, low, parent, bridgesList, i);
    }

    return bridgesList;
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

    vector<pair<int, int>> bridgesList = g.bridges();
    for (i = 0; i < bridgesList.size(); i++)
        cout << "Bridge: " << bridgesList[i].first << "->" << bridgesList[i].second << endl;
    return 0;
}
