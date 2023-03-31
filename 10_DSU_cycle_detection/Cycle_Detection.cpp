#include <bits/stdc++.h>

#define int long long int
#define pb push_back
#define F first
#define S second

using  namespace std;

class Graph {
	int V;
	list<pair<int, int>> l;
public:
	Graph(int V) {
		this -> V = V;
	}

	void addEdge(int u, int v) {
		l.push_back(make_pair(u, v));
	}

	// DSU
	int findSet(int i, int parent[]) {
		if (parent[i] != -1)
			return i;
		return findSet(parent[i], parent);
	}

	// union
	void union_set(int i, int j, int parent[]) {
		int s1 = findSet(i, parent);
		int s2 = findSet(j, parent);
		if (s1 != s2)
			parent[s2] = s1;
	}

	// Cycle detection using DSU(Disjoint Set Union)
	bool isContainsCycle(int V) {
		int parent[V];
		fill(parent, parent + V, -1);

		for (auto edge : l) {
			int s1 = findSet(edge.first, parent);
			int s2 = findSet(edge.second, parent);
			if (s1 != s2)
				parent[s2] = s1;
			else
				return true;
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
		graph.addEdge(u, v);
	}

	if (graph.isContainsCycle(V))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}