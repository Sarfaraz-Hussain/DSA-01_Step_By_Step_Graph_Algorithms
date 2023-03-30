/*

Bipartite Graph or Two Coloring Problem
---------------------------------------
1. we can divide all verices of the graph into 2 disjoints substets such that all edges are from set1 to set 2 or vice versa.
Example:-
		1
	  /   \
	 / 	   \
	2       3
	 \     /
	  \   /
	    4
*/

#include <bits/stdc++.h>

#define int long long int
#define pb push_back
#define F first
#define S second

using  namespace std;


bool dfs(int node, vector<int> graph[], int visited[], int color, int parent) {
	// arrive at node
	visited[node] = color;  // 1 and 2 mean visited

	for (auto nbr : graph[node]) {
		if (visited[nbr] == 0) {
			bool isBipartite = dfs(nbr, graph, visited, 3 - color, node);
			if (isBipartite == false)
				return false;
		} else if (nbr != parent and color == visited[nbr]) {
			return false;
		}
	}
	return true;
}


bool isBipartite(vector<int> graph[], int V) {
	int visited[V] {0}; // 0 Not visited, 1 mean visited and color is 1, 2 mean visited and color is 2
	int color = 1;
	return dfs(0, graph, visited, color, -1);

}



int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E;
	cin >> V >> E;
	vector<int> graph[V];
	while (E--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	// BFS or DFS, by coloring the nodes at each step (current node has color 1, nbr should have color 2)

	if (isBipartite(graph, V))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}





