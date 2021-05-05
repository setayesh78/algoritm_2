#include <bits/stdc++.h>

using namespace std;


void add_edge(vector<int> adj[], int src, int dest){
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

bool dfs(vector<int> adj[], int src, int dest, int v,int pred[], int dist[]){
	list<int> queue;

	bool visited[v];

	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

void printShortestDistance(vector<int> adj[], int s,int dest, int v){
	int pred[v], dist[v];

	if (dfs(adj, s, dest, v, pred, dist) == false) {
		return;
	}

	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
}

int main(){
	
	int v;
	cin >> v;
	int source = 1, dest = v;
	
	vector<int> adj[v+1];

	
	for(int i = 2; i <= v; i++){
		int input;
		cin >> input;
		add_edge(adj,input, i);
	}

	
	printShortestDistance(adj, source, dest, v);
	return 0;
}

