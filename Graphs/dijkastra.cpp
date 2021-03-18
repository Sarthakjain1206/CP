#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair; 


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

// Overriding the comparator class's operator fn to meet our requirement for min heap.
class myComparator
{
public:
    int operator() (iPair&v1, iPair&v2)
    {
        return v1.second > v2.second;
    }
};


void printPath(vector<int> parent, int j) 
{ 
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
    
    printPath(parent, parent[j]);
    printf("%d ", j); 
}

void printSolution(vector<int> dist, int V, vector<int> parent) 
{ 
    int src = 0; 
    printf("Vertex\t Distance\tPath"); 
    for (int i = 1; i < V; i++) 
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",src, i, dist[i], src); 
        printPath(parent, i); 
    } 
}

vector<int> WeightedGraph::dijkastra(int S) {
    // Create min heap ----
    priority_queue< iPair, vector<iPair>, myComparator > pq;
    // initialize dist vector with infinity
    vector<int> dist(this->V, INT_MAX);
    vector<int> parent(this->V, -1);
    
    // push source vertex with dist 0 to min heap;
    pq.push(make_pair(S, 0));
    
    dist[S] = 0;
    
    // LOOP until min heap becomes empty ==> all vertex are finalized (relaxed)
    while(!pq.empty()) {
        // Get the vertex which has the minimum distance.
        int u = pq.top().first;
        // cout << "Popping: "<<u<<": "<<pq.top()[1]<<endl;
        pq.pop();
        // Loop over all the adjacents of that vertex.
        for(auto x: this->adj[u]) {

            int v = x.first;
            int weight = x.second;
            
            // If relaxation is needed, then relax the adj ans also push them to heap.
            if(dist[u] + weight < dist[v]) {
                // For printing the shortest paths-----
                parent[v] = u;
                dist[v] = dist[u] + weight;
                // cout<<"Pushing: "<<vec[0]<<": "<<vec[1]<<endl;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    // To print the shortest path of each vertex--
    printSolution(dist, V, parent);
    cout<<endl;
    return dist;

}

int main(int argc, char const *argv[])
{
    int V, E;
    cout << "Enter Total Vertices: ";
    cin >> V;
    cout << "\nEnter Total Edges: ";
    cin >> E;

    WeightedGraph g(V);
    
    bool directed = false;
    cout << "\nIs graph directed ? (yes/no): ";
    string sl;
    cin >> sl;
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
    if(sl == "yes")
        directed = true;

    cout << "\nNow start entering u, v, and weight(u, v): \n";
    int i = 0;
    while (i++ < E) {
        int u, v, w;
        cin >> u >> v >> w;
        (directed) ? g.addEdgeDirected(u, v, w) : g.addEdgeUnDirected(u, v, w);
    }
    int S;
    cout << "Enter Source Vertex: ";
    cin >> S;
    vector<int> dijkastraDist = g.dijkastra(S);
    for (int l = 0; l < dijkastraDist.size(); l++)
        cout << dijkastraDist[l] << " ";

    return 0;
}
