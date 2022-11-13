#include <bits/stdc++.h>

using namespace std;

void stayTORO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}

// BFS - Breadth First Search
// Principle - FIFO (First In First Out)

class Solution {
public:
	vector<int> getBfs(int V, vector<int> adj[]) {
		// 0-based indexing, so size is n,
		// in 1-based, we put size as n+1
		int visited[V] = {0};

		// storing bfs
		vector<int> bfs;

		for(int curr=0; curr<=V; curr++) {
			if(!visited[curr]) {
				// initialization
				visited[curr] = 1;
				queue<int> q;
				q.push(curr);

				// algorithm
				while(!q.empty()) {
					// taking first node
					int node = q.front();
					q.pop();
					bfs.push_back(node);

					// visiting all neighbors of the current node
					for(auto neighbor : adj[node]) {
						if(!visited[neighbor]) {
							visited[neighbor] = 1;
							q.push(neighbor);
						}
					}
				}
			}
		}

		return bfs;
	}
};

int main() {
	stayTORO();

	// n - number of nodes
	// m - number of edges
	int n, m;
	cin>>n>>m;

	// adjaceny list for storing the graph
	vector<int> adj[n];

	// temporary variables for inputing edge nodes
	int u, v;

	// taking 0-based indexing
	for(int i=0; i<m; i++) {
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Solution S;

	vector<int> ans = S.getBfs(n, adj);

	for(auto ele: ans) cout<<ele<<" ";

	return 0;
}

// == IN ==
// 5 3
// 0 1
// 0 3
// 2 4

// == OUT ==
// 0 1 3 2 4 