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
// 1.  We will fo bfs/dfs traversal from all disjoint nodes
// 2.  We will create a vector of pairs (row, column)
// 2.1 While inserting element in vector of pairs,
//     we will subract base row and base col each time
// 2.2 Base's Row, Col = Row, Col of node from where we started the bfs/dfs traversal
// 3.  We will push each bfs/dfs traversal in a map
// 4.  In the end, size of the map will give us the number of distinct islands

class Solution {
public:
	vector<pair<int, int>> doBfs(int sr, int sc, vector<vector<int>> &adj, vector<vector<int>> &visited) {
		int n = adj.size();
		int m = adj[0].size();

		visited[sr][sc] = 1;
		queue<pair<int, int>> q;
		q.push({sr, sc});

		pair<int, int> base = {sr, sc};

		vector<pair<int, int>> bfs;
		bfs.push_back({sr - base.first, sc - base.second});
		
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
					bfs.push_back({nrow - base.first, ncol - base.second});
					q.push({nrow, ncol});
				}
			}
		}

		return bfs;
	}

	int getDistinctIslands(vector<vector<int>> &adj) {
		int n = adj.size();
		int m = adj[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));

		map<vector<pair<int, int>>, int> mp;

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!visited[i][j] && adj[i][j]==1) {
					vector<pair<int, int>> island = doBfs(i, j, adj, visited);
					mp[island] = 1;
				}
			}
		}

		return mp.size();
	}
};

int main() {
	stayTORO();

	// n - number of rows
	// m - number of columns
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

	int ans = S.getDistinctIslands(adj);

	cout<<ans<<"\n";

	return 0;
}

// == IN ==
// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 0 1 1
// 0 0 0 1 1

// == OUT ==
// 1