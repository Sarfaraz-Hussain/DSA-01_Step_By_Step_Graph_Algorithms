#include <bits/stdc++.h>
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

	void printAdjList() {
		for (int i = 0; i < this -> V; i++) {
			cout << i << " --> ";
			for (auto nbr : l[i]) {
				cout << nbr << " ";
			}
			cout << "\n";
		}
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E;
	cin >> V >> E;
	Graph graph(V);
	while (E--) {
		int x, y;
		cin >> x >> y;
		graph.addEdge(x, y);
	}
	graph.printAdjList();
	return 0;
}