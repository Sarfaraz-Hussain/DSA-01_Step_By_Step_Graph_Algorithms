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


	void dfs(int node, vector<bool> &visited, list<int> &ansList) {
		// Arrive at a node will mark it visited
		visited[node] = true;

		for (auto nbr : l[node]) {
			if (!visited[nbr]) {
				dfs(nbr, visited, ansList);
			}
		}
		ansList.push_front(node);
	}


	void topologicalSort() {
		vector<bool> visited(V, false);
		list<int> ansList;
		for (int src = 0; src < V; src++) {
			if (!visited[src])
				dfs(src, visited, ansList);
		}
		for (auto node : ansList) {
			cout << node << " ";
		}
		cout << endl;
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
		graph.addEdge(u, v, false);
	}

	graph.topologicalSort();
}