/**
 * March 2013 Long Challenge at Codechef
 *
 * Problem:     FIRESC - Fire Escape Routes
 * Author:      Anton Lunyov (Tester)
 * Complexity:  O(N + M) per test
 * Timing:      0.23 out of 3.00
 *
 * Description:
 * We build a graph having employees as vertexes,
 * where each pair of friends is connected by an edge
 * Then the maximum number of escape routes 
 * coincides with the number of connected components
 * and the number of ways to choose captains 
 * coincides with the product of sizes of connected components
 * So we run DFS to identify connected components
 * and their sizes in this graph,
 * and then find both values directly
 */
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> VI;

// the graph representation
// as a list of adjacent vertexes for each vertex
vector<VI> a;
VI mark; // we mark visited vertexes here
int cnt; // contains the size of the current connected component

// traverse the graph in depth first order
void dfs(int u) {
	++cnt; // increase size of the component
	mark[u] = 1; // mark vertex as visited
	// loop over adjacent vertexes
	for (VI::iterator v = a[u].begin(); v != a[u].end(); ++v) {
		// *v is the adjacent vertex itself
		if (!mark[*v]) {
			// if it was not visited before we move to it
			dfs(*v);
		}
	}
}

int main() {
	// input number of tests
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		// input number of vertexes and edges
		int N, M;
		scanf("%d%d", &N, &M);
		// initializing graph
		a = vector<VI> (N);
		for (int i = 0; i < M; ++i) {
			// input ends of the current edge
			int u, v;
			scanf("%d%d", &u, &v);
			// adjust them to be in the range [0,n)
			// since it is more convenient
			--u; --v;
			// add v to the list of u, and u to the list of v
			a[u].push_back(v);
			a[v].push_back(u);
		}		
		int res = 0; // the number of fire escape routes
		int ways = 1; // the number of ways to choose drill captains
		mark = VI(N, 0); // initially mark all vertexes as unvisited  
		// loop over vertexes
		for (int u = 0; u < N; ++u) {
			// skip visited vertex
			if(mark[u]) {
				continue;
			}
			// if vertex was not visited it starts a new component
			++res; // so we increase res
			cnt = 0; // init cnt
			dfs(u); // and calculate it through the dfs, marking visited vertexes
			// we multiply ways by cnt modulo 1000000007
			ways = (long long)cnt * ways % 1000000007;
		}
		printf("%d %d\n", res, ways);
	}
	return 0;
}
