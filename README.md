![logo](https://raw.githubusercontent.com/kdn251/interviews/master/images/dijkstra.gif)
# **This is the Graph Playlist in C++**
### _Language used_ --> C++
### _Editor used_ --> Sublime Text 4
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
### 3. Single Source Shortest Path 
- Code
```java
void singleSourceShortestPath(int src, int dest = -1) {
		queue<int> q;
		q.push(src);
		bool visited[V] {false};
		visited[src] = true;
		int parent[V] { -1};
		parent[src] = src;
		int distance[V] {0};

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					parent[nbr] = node;
					distance[nbr] = distance[node] + 1;
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		for (int i = 0; i < V; i++) {
			cout << "Distance from src " << src << " to " << i << " is " << distance[i] << endl;
		}
		if (dest != -1) {
			int temp = dest;
			cout << temp << " --> ";
			while (temp != src) {
				temp = parent[temp];
				cout << temp << " --> ";
			}
			cout << src << endl;
		}
	}
```

- input.txt
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
- output.txt
```text
Distance from src 1 to 0 is 1
Distance from src 1 to 1 is 0
Distance from src 1 to 2 is 1
Distance from src 1 to 3 is 2
Distance from src 1 to 4 is 2
Distance from src 1 to 5 is 3
Distance from src 1 to 6 is 4
6 --> 5 --> 3 --> 2 --> 1 --> 1
```
### 4. Depth First Search Algorithm(DFS)
_It is a recursive algorithm_

- Code for DFS
```java
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
```

- input.txt
```text
7
8
1
0 1
1 2
2 3
3 5
5 6
4 5
0 4
3 4
```
- output.txt
```text
1 0 4 5 3 2 6 
```


