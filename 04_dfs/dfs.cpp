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
		if (undir) {
			l[v].push_back(u);
		}
	}

	void dfs(int src, bool visited[]) {
		int flag = 1;
		for (auto nbr : l[src]) {
			if (visited[nbr] == false) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			return;
		}
		for (auto nbr : l[src]) {
			if (!visited[nbr]) {
				cout << nbr << " ";
				visited[nbr] = true;
				dfs(nbr, visited);
			}
		}
	}
};

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E, src;
	cin >> V >> E >> src;
	Graph graph(V);
	while (E--) {
		int u, v;
		cin >> u >> v;
		graph.addEdge(u, v);
	}
	bool visited[V] {false};
	visited[src] = true;
	cout << src << " ";
	graph.dfs(src, visited);

}