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

// DFS - Depth First Search
// Principle - LIFO (Last In First Out)

class Solution {
public:
	vector<int> getDfs(int V, vector<int> adj[]) {
		// 0-based indexing, so size is n,
		// in 1-based, we put size as n+1
		int visited[V] = {0};

		// initialization
		visited[0] = 1;
		stack<int> s;
		s.push(0);

		// storing dfs
		vector<int> dfs;

		// algorithm
		while(!s.empty()) {
			// taking last node
			int node = s.top();
			s.pop();
			dfs.push_back(node);

			// visiting all neighbors of the current node
			for(auto neighbor : adj[node]) {
				if(!visited[neighbor]) {
					visited[neighbor] = 1;
					s.push(neighbor);
				}
			}
		}

		return dfs;
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

	vector<int> ans = S.getDfs(n, adj);

	for(auto ele: ans) cout<<ele<<" ";

	return 0;
}

// == IN ==
// 5 4
// 0 1
// 0 2
// 0 3
// 2 4

// == OUT ==
// 0 3 2 4 1 