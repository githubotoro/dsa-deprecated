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

// Logic:
// traverse either by dfs or bfs, here dfs is implemented
// ans: increase the number of provinces whenver a disjoint is encountered

class Solution {
public:
	int getDfs(int V, vector<int> adj[]) {
		// 0-based indexing, so size is n,
		// in 1-based, we put size as n+1
		int visited[V] = {0};

		// storing dfs
		vector<int> dfs;

		// storing provinces
		int provinces = 0;

		for(int curr=0; curr<=V; curr++) {
			if(!visited[curr]) {
				// increase provinces because it is a disjoint
				provinces++;

				// initialization
				visited[curr] = 1;
				stack<int> s;
				s.push(curr);

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
			}
		}

		return provinces;
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

	int provinces = S.getDfs(n, adj);

	cout<<provinces;

	return 0;
}

// == IN ==
// 5 3
// 0 1
// 0 3
// 2 4

// == OUT ==
// 2 