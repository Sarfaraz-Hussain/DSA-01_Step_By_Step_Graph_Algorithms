#include <bits/stdc++.h>

#define int long long int
#define pb push_back
#define F first
#define S second

using  namespace std;

class Graph {
	int V;
	list<int> *l;

public:
	Graph(int V) {
		this -> V = V;
		l = new list<int>[V];
	}

	void addEdge(int u, int v, bool undir = true) {
		l[u].push_back(v);
		if (undir)
			l[v].push_back(u);
	}


	bool dfs(int node, bool visited[], int parent) {
		// Mark the node as visited
		visited[node] = true;

		// Do some work
		for (auto nbr : l[node]) {
			if (!visited[nbr])
			{
				bool isNbrFoundCycle = dfs(nbr, visited, node);
				if (isNbrFoundCycle)
					return true;
			} else if (nbr != parent)
				return true;
		}
		return false;

	}

	// Wrapper function for dfs
	bool cycleDetection(int V) {
		bool visited[V] {false};
		// The graph may and may not be connected
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				if (dfs(i, visited, -1))
					return true;
			}
		}
		return false;
	}
};

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E;
	cin >> V >> E;
	Graph graph(V);
	while (E--) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(u , v);
	}
	if (graph.cycleDetection(V))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;

}