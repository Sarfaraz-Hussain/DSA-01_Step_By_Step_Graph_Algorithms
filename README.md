![logo](https://raw.githubusercontent.com/kdn251/interviews/master/images/dijkstra.gif)
# **This is the Graph Playlist in C++**
## _Here in this repository I will upload the coding solution for graph algorithms on a daily basis._

---
### 1. Graph Representation
- Coding Adjacency List 
```cpp
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
```
- Input file
```text
7
8
1 2
1 0
2 3
0 4
3 4
3 5
4 5
5 6
```
- Output file 
```text
0 --> 1 4 
1 --> 2 0 
2 --> 1 3 
3 --> 2 4 5 
4 --> 0 3 5 
5 --> 3 4 6 
6 --> 5 
```
---
### 2. BFS Algorithm
- Coding BFS algo
```c++
void bfs(int src = 0) {
		queue<int> q;
		q.push(src);
		bool visited[V] {false};
		visited[src] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
```
- Input file
```text
7
8
1
1 2
1 0
2 3
0 4
3 4
3 5
4 5
5 6
```
- Output file
```text
1 2 0 3 4 5 6 
```

