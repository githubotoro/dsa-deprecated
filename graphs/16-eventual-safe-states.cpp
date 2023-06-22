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
	bool detectCycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &safeNodes, int currNode) {
		stack<int> s;
		s.push(currNode);

		while(!s.empty()) {
			currNode = s.top();
			s.pop();

			for(auto neighbor : graph[currNode]) {
				if(!visited[neighbor]) {
					s.push(neighbor);
					break;
				} else if(safeNodes[neighbor] == true) {
					return false;
				}
			}
		}

		return false;
	}

    vector<bool> eventualSafeNodes(vector<vector<int>> &graph) {
        int V = graph.size();

		vector<bool> visited(V, false);
		vector<bool> safeNodes(V, false);

		for(int i=0; i<V; i++) {
			if(!visited[i]) {
				bool isCycle = detectCycle(graph, visited, safeNodes, i);

				if(!isCycle) {
					safeNodes[i] = true;
				}
			}
		}

		return safeNodes;
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
	}

	Solution S;

	vector<bool> ans = S.eventualSafeNodes(adj);

	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}

// == IN ==
// 7 7
// 0 1
// 0 2
// 1 2
// 1 3
// 2 5
// 3 0
// 4 5

// == OUT ==
