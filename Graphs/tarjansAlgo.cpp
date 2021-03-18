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
        void SCC(vector<vector<int>> &sccList);
        void SCCUtil(bool inStack[], int disc[], int low[], stack<int> &st, int u, vector<vector<int>> &sccList);
};

void UnweightedGraph:: SCCUtil(bool inStack[], int disc[], int low[], stack<int> &st, int u, vector<vector<int>> &sccList) {
    static int time = 0;
    inStack[u] = true;
    st.push(u);

    disc[u] = low[u] = ++time;

    for(int v: adj[u]) {
        // If not visited
        if(disc[v] == -1) {
            SCCUtil(inStack, disc, low, st, v, sccList);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v] == true) {
            low[u] = min(low[u], disc[v]);
        }
    }
    vector<int> sccTempList;
    if(low[u] == disc[u]) {
        while(st.top() != u) {
            int w = st.top();
            st.pop();
            inStack[w] = false;
            sccTempList.push_back(w);
        }
        int w = st.top();
        st.pop();
        inStack[w] = false;
        sccTempList.push_back(w);
        sccList.push_back(sccTempList);
    }

}

void UnweightedGraph:: SCC(vector<vector<int>> &sccList) {
    bool *inStack = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    stack<int> st;

    for (int i = 0; i < V; i++){
        inStack[i] = false;
        // We are initializg with -1 as we can avoid visited array by doing this.
        disc[i] = -1;
    }
    for (int i = 0; i < V; i++){
        if(disc[i] == -1)
            SCCUtil(inStack, disc, low, st, i, sccList);
    }

}


// Tarjan's algorithm is slight variation of finding articulation points algo. 
//INFO: It is used to find all SCC(strongly connected components) but in single DFS traversal, unlike kosaraju's algo which takes two DFS traversal and one traversal to transpose the graph.

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
        g.addEdgeDirected(u, v);
    }
    vector<vector<int>> sccList;
    g.SCC(sccList);

    cout << "\nStrongly Connected Components are:\n";
    for (i = 0; i < sccList.size(); i++) {
        for (int j = 0; j < sccList[i].size(); j++)
            cout << sccList[i][j] << " ";
        cout << endl;
    }
    return 0;
}
