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

// class Solution {
// public:
// 	void fillMatrix(vector<vector<int>> &adj, queue<pair<int, int>> &q) {
// 		int ROWS = adj.size();
// 		int COLS = adj[0].size();

// 		vector<vector<int>> visited(ROWS, vector<int> (COLS, 0));

// 		while(!q.empty()) {
// 			int currRow = q.front().first;
// 			int currCol = q.front().second;
//             int currFill = adj[currRow][currCol];
// 			q.pop();

// 			int delrow[4] = {-1, 0, 1, 0};
// 			int delcol[4] = {0, 1, 0, -1};

// 			for(int i=0; i<4; i++) {
// 				int nrow = currRow + delrow[i];
// 				int ncol = currCol + delcol[i];

// 				if(nrow>=0 && nrow<ROWS && ncol>=0 && ncol<COLS &&
// 				   adj[nrow][ncol]==1 && !visited[nrow][ncol]) {
// 					visited[nrow][ncol]=1;
// 					adj[nrow][ncol] = currFill;
// 					q.push({nrow, ncol});
// 				}
// 			}
// 		}
// 	}
// };

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		vector<vector<int>> adj(n, vector<int>(n, 0));

		queue<pair<int, int>> q;

		for(int i=1; i<=n-1; i++) {
			int u, v;
            cin>>u>>v;

            adj[u-1][v-1] = 1;
            adj[v-1][u-1] = 1;

			q.push({u-1, v-1});
			q.push({v-1, u-1});
        }

		// for(int i=0; i<n; i++) {
		// 	for(int j=0; j<n; j++) {
		// 		cout<<adj[i][j]<<" ";
		// 	} cout<<endl;
		// }
		// cout<<endl;

		int ROWS = adj.size();
		int COLS = adj[0].size();

		vector<vector<int>> visited(ROWS, vector<int> (COLS, 0));

		int ans2 = 0;

		while(!q.empty()) {
			

			int currRow = q.front().first;
			int currCol = q.front().second;
            int currFill = adj[currRow][currCol];

			ans2+=currFill;
			q.pop();

			int delrow[4] = {-1, 0, 1, 0};
			int delcol[4] = {0, 1, 0, -1};

			for(int i=0; i<4; i++) {
				int nrow = currRow + delrow[i];
				int ncol = currCol + delcol[i];

				if(nrow>=0 && nrow<ROWS && ncol>=0 && ncol<COLS &&
				   adj[nrow][ncol]==0 && !visited[nrow][ncol]) {
					visited[nrow][ncol]=1;
					adj[nrow][ncol] = currFill+1;
					q.push({nrow, ncol});
				}
			}
		}

		// for(int i=0; i<n; i++) {
		// 	for(int j=0; j<n; j++) {
		// 		cout<<adj[i][j]<<" ";
		// 	} cout<<endl;
		// }

		int ans = 0;

		for(int i=0; i<n; i++) {
			ans += adj[i][i];
		}

		cout<<ans<<"\n";
		cout<<ans2<<"\n";



		// Solution S;

		// S.fillMatrix(adj);
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