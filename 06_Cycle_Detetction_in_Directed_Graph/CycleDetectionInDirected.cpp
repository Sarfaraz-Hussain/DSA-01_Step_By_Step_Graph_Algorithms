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

	bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
		// Arrive at a node will mark it visited and will push into the stack
		visited[node] = true;
		stack[node] = true;


		// check weather the graph contains a backedge or not
		for (auto nbr : l[node]) {
			if (stack[nbr] == true)  // this code directly found the backedge
				return true;
			else if (!visited[nbr]) {
				bool isNbrFoundCycle = dfs(nbr, visited, stack);    // the nbr is getting backedge recursively from its nbr is nbrs
				if (isNbrFoundCycle)
					return true;
			}
		}

		// Going back to the parent pop from stack
		stack[node] = false;
		return false;

	}

	bool cycleContains(int V) {
		vector<bool> visited(V, false);
		vector<bool> stack(V, false);
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				if (dfs(i, visited, stack))
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
		graph.addEdge(u, v, false);
	}


	if (graph.cycleContains(V))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

}