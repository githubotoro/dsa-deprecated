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

// Logic:
// 1. Take a vector of all vertices which will store their correponding colors
// 2. We will do BFS/DFS traversal of the graph 
// 3. During the traversal, we will colour each vertex with
//    the opposite colour as that of its parent
// 4. If the vertex is already coloured, check it has colour
//    the same colour which we are trying to fill
// 5. Whenever the step 4 fails, return false as the graph isn't bipartite

class Solution {
public:
	bool doBfs(vector<vector<int>> &adj, vector<int> &colored, queue<int> &q) {
		int V = adj.size();

		while(!q.empty()) {
			int currNode = q.front();
			int currColor = colored[currNode];
			q.pop();

			int neighborColor;
			if(currColor == 0) neighborColor = 1;
			else neighborColor = 0;

			for(auto neighbor : adj[currNode]) {
				if(colored[neighbor] == -1) {
					colored[neighbor] = neighborColor;
					q.push(neighbor);
				} else {
					if(colored[neighbor] != neighborColor) return false;
				}
			}
		}

		return true;
	}

	bool isBipartite(vector<vector<int>> &adj) {
		int V = adj.size();

		// We don't need visited vector here
		// WHY?
		// -- Because if node would be visited,
		//    it will be colored and vice-versa.
		//    So, just keeping one vector of colored
		//    is enough to solve the problem.
		vector<int> colored(V, -1);

		queue<int> q;

		for(int i=0; i<V; i++) {
			if(colored[i] == -1) {
				q.push(i);
				colored[i] = 0;
				bool ans = doBfs(adj, colored, q);
				if(ans == false) return false;
			}
		}

		return true;
	}
};

int main() {
	stayTORO();

	// n - number of nodes
	// m - number of edges
	int n, m;
	cin>>n>>m;

	// adjaceny list
	vector<vector<int>> adj(n, vector<int> (0, 0));

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Solution S;

	bool ans = S.isBipartite(adj);

	if(ans == true) cout<<"Bipartite"<<endl;
	else cout<<"Not Bipartite"<<endl;

	return 0;
}

// == IN ==
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3

// == OUT ==
// Not Bipartite