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
// ans: increase the number of islands whenver a disjoint is encountered

class Solution {
public:
	void doDfs(int row, int col, vector<vector<char>> &adj, vector<vector<int>> &visited) {
		int ROWS = adj.size();
		int COLS = adj[0].size();
		
		visited[row][col] = 1;
		stack<pair<int, int>> s;
		s.push({row, col});

		while(!s.empty()) {
			int currRow = s.top().first;
			int currCol = s.top().second;
			s.pop();

			// visiting all neighbors of current row and col
			for(int delrow=-1; delrow<=1; delrow++) {
				for(int delcol=-1; delcol<=1; delcol++) {
					int nrow = row + delrow;
					int ncol = col + delcol;

					if(nrow>=0 && nrow<ROWS && ncol>=0 && ncol<COLS &&
					   adj[nrow][ncol]=='1' && !visited[nrow][ncol]) {
						visited[nrow][ncol] = 1;
						s.push({nrow, ncol});
					}
				}
			}
		}
	}

	int getIslands(vector<vector<char>> &adj) {
		int rows = adj.size();
		int cols = adj[0].size();

		vector<vector<int>> visited(rows, vector<int> (cols, 0));

		int islands = 0;

		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				if(!visited[i][j] && adj[i][j] == '1') {
					islands++;
					doDfs(i, j, adj, visited);
				}
			}
		}

		return islands;
	}
};

int main() {
	stayTORO();

	// n - number of rows
	// m - number of columns
	int n, m;
	cin>>n>>m;

	vector<vector<char>> adjMatrix(n, vector<char> (m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>adjMatrix[i][j];
		}
	}

	Solution S;

	int islands = S.getIslands(adjMatrix);

	cout<<islands;

	return 0;
}

// == IN ==
// 2 7
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 

// == OUT ==
// 3