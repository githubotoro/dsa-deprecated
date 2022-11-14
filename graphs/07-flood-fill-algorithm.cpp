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
	void floodfill(vector<vector<int>> &adj, const int &row, const int &col, const int &newColor) {
		int ROWS = adj.size();
		int COLS = adj[0].size();

		vector<vector<int>> visited(ROWS, vector<int> (COLS, 0));

		queue<pair<int, int>> q;
		visited[row][col] = 1;
		adj[row][col] = newColor;
		q.push({row, col});

		while(!q.empty()) {
			int currRow = q.front().first;
			int currCol = q.front().second;
			q.pop();

			int delrow[4] = {-1, 0, 1, 0};
			int delcol[4] = {0, 1, 0, -1};

			for(int i=0; i<4; i++) {
				int nrow = currRow + delrow[i];
				int ncol = currCol + delcol[i];

				if(nrow>=0 && nrow<ROWS && ncol>=0 && ncol<COLS &&
				   adj[nrow][ncol]==1 && !visited[nrow][ncol]) {
					visited[nrow][ncol]=1;
					adj[nrow][ncol] = newColor;
					q.push({nrow, ncol});
				}
			}
		}
	}
};

int main() {
	stayTORO();

	// n - number of rows
	// m - number of columns
	int n, m;
	cin>>n>>m;

	int newColor;
	cin>>newColor;

	// sr - starting row
	// sc - starting col
	int sr, sc;
	cin>>sr>>sc;

	vector<vector<int>> adjMatrix(n, vector<int> (m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>adjMatrix[i][j];
		}
	}

	Solution S;

	S.floodfill(adjMatrix, sr, sc, newColor);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<adjMatrix[i][j]<<" ";
		} cout<<"\n";
	}

	return 0;
}

// == IN ==
// 3 3
// 2
// 1 1
// 1 1 1
// 1 1 0
// 1 0 1

// == OUT ==
// 2 2 2 
// 2 2 0 
// 2 0 1 