#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

// int dsfind(int x, vector<int> &parent) {
//     if(x == parent[x])
//         return x;
//     parent[x] = dsfind(parent[x], parent);
//     return parent[x];
// }

// void dsUnion(int x, int y, vector<int> &parent, vector<int> &rank) {
//     int x_rep = dsfind(x, parent), y_rep = dsfind(y, parent);
//     // cout << "X_rep: " << x_rep << "\nY_rep: " << y_rep;
//     if(x_rep == y_rep)
//         return;
    
//     if(rank[x_rep] < rank[y_rep])
//         parent[x_rep] = y_rep;
//     else if(rank[y_rep] < rank[x_rep])
//         parent[y_rep] = x_rep;
//     else {
//         parent[y_rep] = x_rep;
//         rank[x_rep]++;
//     }
// }


// int main(int argc, char const *argv[])
// {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<int> parent(n);
//         vector<int> rank(n);
//         for (int i = 0; i < n; i++) {
//             rank[i] = 0;
//             parent[i] = i;
//         }
//         for (int i = 0; i < m; i++)
//         {
//             int a, b;
//             cin >> a >> b;
//             dsUnion(a-1, b-1, parent, rank);
//         }
//         // for (int i = 0; i < n; i++)
//         //     cout << parent[i];
//         // cout << "\n\n\n";
//         unordered_map<int, int> map;
//         for (int i = 0; i < n; i++) {
//             map[parent[i]]++;
//         }
//         int a=0, b=1;
//         for (auto i = map.begin(); i != map.end(); i++) {
//             a++;
//             b = b * i->second % 1000000007;
//         }
//         cout << a << " " << b << endl;
//     }

//     return 0;
// }


// class UnweightedGraph {
//     int V;
//     vector<int> *adj;
//     public:
//         UnweightedGraph(int V) {
//             this->V = V;
//             adj = new vector<int>[V];
//         }
//         void addEdgeDirected(int u, int v) {
//             adj[u].push_back(v);
//         }
//         void addEdgeUnDirected(int u, int v) {
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         // bool BFS();
//         void DFS(vector<bool> &visited, int u, int &count);
// };

// void UnweightedGraph::DFS(vector<bool> &visited, int u, int &count) {
//     visited[u] = true;
//     count++;
//     for (int v: adj[u]){
//         if(!visited[v])
//             DFS(visited, v, count);
//     }

// }
void DFS(vector<int> adj[], vector<bool> &visited, int u, int &count) {
    visited[u] = true;
    count++;
    for (int v: adj[u]){
        if(!visited[v])
            DFS(adj, visited, v, count);
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        // UnweightedGraph g(n);
        vector<int> *adj;
        adj = new vector<int>[n];

        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);

            // g.addEdgeUnDirected(a-1, b-1);
        }
        vector<bool> visited(n, false);
        int total = 0;
        int ways = 1;
        for (int i = 0; i < n; i++) {
            if(!visited[i]){
                int count = 0;
                total++;
                // g.DFS(visited, i, count);
                DFS(adj, visited, i, count);
                ways = ((ways % mod) * (count % mod))%mod;
            }
        }
        cout << total <<  " " << ways << endl;
    }
    return 0;
}
