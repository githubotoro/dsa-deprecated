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

class Solution {
public:
	bool detectCycle(int root, vector<vector<int>> &adj, vector<bool> &visited) {
		visited[root] = true;
		stack<pair<int, int>> s;
		s.push({root, -1});

		while(!s.empty()) {
			int currNode = s.top().first;
			int parent = s.top().second;
			s.pop();

			for(auto neighbor : adj[currNode]) {
				if(!visited[neighbor]) {
					visited[neighbor] = true;
					s.push({neighbor, currNode});
				} else {
					if(neighbor != parent) return true;
				}
			}
		}

		return false;
	}

	bool isCycle(int V, vector<vector<int>> &adj) {
		vector<bool> visited(V, false);

		for(int i=0; i<V; i++) {
			if(!visited[i]) {
				if(detectCycle(i, adj, visited)) return true;
			}
		}

		return false;
	}
};

int main() {
	stayTORO();

	// n - number of nodes
	// m - number of edges
	int n, m;
	cin>>n>>m;

	vector<vector<int>> adj(n, vector<int>(0, 0));

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Solution S;

	cout<<S.isCycle(n, adj);

	return 0;
}

// == IN ==
// 5 5
// 0 1
// 1 2
// 1 4
// 2 3
// 4 3

// == OUT ==
// 1 