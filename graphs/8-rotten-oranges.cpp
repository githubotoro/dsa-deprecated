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
	int doBfs(queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &adj, vector<vector<int>> &visited) {
		int ROWS = adj.size();
		int COLS = adj[0].size();
		
		int totalTime = 0;

		while(!q.empty()) {
			int currRow = q.front().first.first;
			int currCol = q.front().first.second;
			int currTime = q.front().second;

			q.pop();

			totalTime = max(totalTime, currTime);

			int delrow[4] = {-1, 0, 1, 0};
			int delcol[4] = {0, 1, 0, -1};

			for(int i=0; i<4; i++) {
				int nrow = currRow + delrow[i];
				int ncol = currCol + delcol[i];

				if(nrow>=0 && nrow<ROWS && ncol>=0 && ncol<COLS &&
				   adj[nrow][ncol]==1 && !visited[nrow][ncol]) {
					visited[nrow][ncol] = 2;
					adj[nrow][ncol] = 2;
					q.push({{nrow, ncol}, currTime+1});
				}
			}
		}

		return totalTime;
	}

	int getTime(vector<vector<int>> &adj) {
		int ROWS = adj.size();
		int COLS = adj[0].size();

		vector<vector<int>> visited(ROWS, vector<int> (COLS, 0));

		queue<pair<pair<int, int>, int>> q;

		for(int i=0; i<ROWS; i++) {
			for(int j=0; j<COLS; j++) {
				if(adj[i][j]==2) {
					visited[i][j] = 1;
					q.push({{i, j}, 0});
				}
			}
		}

		int totalTime = doBfs(q, adj, visited);

		for(int i=0; i<ROWS; i++) {
			for(int j=0; j<COLS; j++) {
				if(adj[i][j]==1) return -1;
			}
		}

		return totalTime;	
	}
};

int main() {
	stayTORO();

	// n - number of rows
	// m - number of columns
	int n, m;
	cin>>n>>m;

	vector<vector<int>> adjMatrix(n, vector<int> (m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>adjMatrix[i][j];
		}
	}

	Solution S;

	int ans = S.getTime(adjMatrix);

	cout<<ans;

	return 0;
}

// == IN ==
// 3 3
// 0 1 2
// 0 1 2
// 2 1 1

// == OUT ==
// 1