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

int main(int argc, char const *argv[])
{
    int V;
    cin >> V;

    return 0;
}
