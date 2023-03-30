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


	void topologicalSort() {
		// will create the dependency or indegree array
		vector<int> indegree(V, 0);
		for (int u = 0; u < V; u++) {
			for (auto v : l[u])
				indegree[v]++;
		}

		// will apply the BFS here

		queue<int> q;
		for (int i = 0; i < V; i++)
			if (indegree[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					q.push(nbr);
			}
		}
	}


};


int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
	Topological Sorting is possible only in DAG.

	*/

	int V, E;
	cin >> V >> E;

	Graph graph(V);
	while (E--) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(u, v, false);
	}


	graph.topologicalSort();
	return 0;

}