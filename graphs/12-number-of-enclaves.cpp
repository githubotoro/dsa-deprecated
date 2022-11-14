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
// 1.  Traverse all boundaries:
// 1.1 First Row, Last Row, First Column, Last Column
// 2.  If there is "1" and it is unvisted, then
// 2.1 Do dfs/bfs from that node and mark all connected nodes as visited
// 3.  After all 4 traversals have been done,
// 3.1 Iterate through all rows and columns except above ones,
// 3.2 If there is "1" and unvisited, and increase the number of enclaves

class Solution {
public:
	void doBfs(int n, int m, int sr, int sc, vector<vector<int>> &adj, vector<vector<int>> &visited) {
		queue<pair<int, int>> q;
		q.push({sr, sc});

		while(!q.empty()) {
			int currRow = q.front().first;
			int currCol = q.front().second;
			q.pop();

			int delrow[4] = {-1, 1, 0, 0};
			int delcol[4] = {0, 0, -1, 1};

			for(int i=0; i<4; i++) {
				int nrow = currRow + delrow[i];
				int ncol = currCol + delcol[i];

				if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
				   adj[nrow][ncol]==1 && !visited[nrow][ncol]) {
					visited[nrow][ncol] = 1;
					q.push({nrow, ncol});
				}
			}
		}
	}

	int getEnclaves(int n, int m, vector<vector<int>> &adj) {
		vector<vector<int>> visited(n, vector<int> (m, 0));

		// outer columns
		for(int i=0; i<n; i++) {
			// first column
			if(adj[i][0]==1 && !visited[i][0]) doBfs(n, m, i, 0, adj, visited);

			// last column
			if(adj[i][m-1]==1 && !visited[i][m-1]) doBfs(n, m, i, m-1, adj, visited);
		}

		// outer rows
		for(int j=0; j<m; j++) {
			// first row
			if(adj[0][j]==1 && !visited[0][j]) doBfs(n, m, 0, j, adj, visited);

			// last row
			if(adj[n-1][j]==1 && !visited[n-1][j]) doBfs(n, m, n-1, j, adj, visited);
		}

		int enclaves = 0;

		// inner rows and columns
		for(int i=1; i<n-1; i++) {
			for(int j=1; j<m-1; j++) {
				if(adj[i][j]==1 && !visited[i][j]) enclaves++;
			}
		}

		return enclaves;
	}   
};

int main() {
	stayTORO();

	// n - number of nodes
	// m - number of edges
	int n, m;
	cin>>n>>m;

	// adjaceny matrix
	vector<vector<int>> adj(n, vector<int> (m, 0));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>adj[i][j];
		}
	}

	Solution S;

	int ans = S.getEnclaves(n, m, adj);

	cout<<ans<<"\n";

	return 0;
}

// == IN ==
// 5 4
// X X X X
// X O X X
// X O O X
// X O X X
// X X O O

// == OUT ==
// X X X X 
// X X X X 
// X X X X 
// X X X X 
// X X O O 