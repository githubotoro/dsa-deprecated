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
// 1.  Traverse all boundaries:
// 1.1 First Row, Last Row, First Column, Last Column
// 2.  If there is 'O' and it is unvisted, then
// 2.1 Do dfs/bfs from that node and mark all connected nodes as visited
// 3.  After all 4 traversals have been done,
// 3.1 Iterate through all rows and columns except above one,
// 3.2 If there is 'O' and unvisited, then replace it with 'X', else leave it as it is

class Solution {
public:
	void doDfs(int n, int m, int sr, int sc, vector<vector<char>> &adj, vector<vector<int>> &visited) {
		stack<pair<int, int>> s;
		s.push({sr, sc});

		while(!s.empty()) {
			int currRow = s.top().first;
			int currCol = s.top().second;
			s.pop();

			int delrow[4] = {-1, 1, 0, 0};
			int delcol[4] = {0, 0, -1, 1};

			for(int i=0; i<4; i++) {
				int nrow = currRow + delrow[i];
				int ncol = currCol + delcol[i];

				if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
				   adj[nrow][ncol]=='O' && !visited[nrow][ncol]) {
					visited[nrow][ncol] = 1;
					s.push({nrow, ncol});
				}
			}
		}
	}

	void replaceOX(int n, int m, vector<vector<char>> &adj) {
		vector<vector<int>> visited(n, vector<int> (m, 0));

		// outer columns
		for(int i=0; i<n; i++) {
			// first column
			if(adj[i][0]=='O' && !visited[i][0]) doDfs(n, m, i, 0, adj, visited);

			// last column
			if(adj[i][m-1]=='O' && !visited[i][m-1]) doDfs(n, m, i, m-1, adj, visited);
		}

		// outer rows
		for(int j=0; j<m; j++) {
			// first row
			if(adj[0][j]=='O' && !visited[0][j]) doDfs(n, m, 0, j, adj, visited);

			// last row
			if(adj[n-1][j]=='O' && !visited[n-1][j]) doDfs(n, m, n-1, j, adj, visited);
		}

		// inner rows and columns
		for(int i=1; i<n-1; i++) {
			for(int j=1; j<m-1; j++) {
				if(adj[i][j]=='O' && !visited[i][j]) adj[i][j] = 'X';
			}
		}
	}   
};

int main() {
	stayTORO();

	// n - number of nodes
	// m - number of edges
	int n, m;
	cin>>n>>m;

	// adjaceny matrix
	vector<vector<char>> adj(n, vector<char> (m, 0));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>adj[i][j];
		}
	}

	Solution S;

	S.replaceOX(n, m, adj);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<adj[i][j]<<" ";
		} cout<<"\n";
	}

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