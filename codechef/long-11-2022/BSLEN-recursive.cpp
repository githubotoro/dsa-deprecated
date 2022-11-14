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

class Solution {
public:
	void getBfs(int V, vector<vector<int>> &adj, vector<pair<int, pair<int, int>>> &bfs) {
		// 1-based indexing, so size is V+1,
		// in 0-based, we put size as V
		int visited[V+1] = {0};

		// initialization
		visited[1] = 1;
        queue<pair<int,int>> q;
        q.push({1, 0});

        vector<int> temp(V+1, 0);

		// algorithm
		while(!q.empty()) {
			// taking last node
			int currNode = q.front().first;
			int currHeight = q.front().second;

            // temp[currNode]++;
            // cout<<"temp["<<currNode<<"] = "<<temp[currNode]<<endl;

			q.pop();
            bfs.push_back({currNode,{currHeight, adj[currNode].size()}});

			// visiting all neighbors of the current node
			for(auto neighbor : adj[currNode]) {
				if(!visited[neighbor]) {
                   
					visited[neighbor] = 1;
					q.push({neighbor, currHeight+1});

                    // temp[currNode]++;

                    // distances[currNode][neighbor] += 1;
                    // distances[neighbor][currNode] += 1;
				} 
			}
		}
	}

    int getDist2(int V, vector<vector<int>> &adj, int a, int b) {
		// 1-based indexing, so size is V+1,
		// in 0-based, we put size as V
		int visited[V+1] = {0};

		// initialization
		visited[a] = 1;
        queue<int> q;
        q.push(a);

        int dist=0;

		// algorithm
		while(!q.empty()) {
			// taking last node
			int currNode = q.front();
			q.pop();
            dist++;
            
			// visiting all neighbors of the current node
			for(auto neighbor : adj[currNode]) {
				if(!visited[neighbor]) {
					visited[neighbor] = 1;
					q.push(neighbor);
                    
                    if(neighbor == b) return dist;
				} 
			}
		}
	}
};

bool custom(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b) {
    if(a.second.first == b.second.first) {
        return (a.second.second < b.second.second);
    } else {
        return (a.second.first < b.second.first);
    }
}

int main() {
	stayTORO();

    int t;
    cin>>t;
    
    while(t--) {
        // n - number of nodes and edges
        int n;
        cin>>n;

        // adjaceny list for storing the graph
        vector<vector<int>> adj(n+1, vector<int>(0, 0));

        vector<vector<int>> distances(n+1, vector<int> (n+1, INT_MAX/2));

        // temporary variables for inputing edge nodes
        int u, v;

        // taking 1-based indexing
        for(int i=1; i<=n-1; i++) {
            cin>>u>>v;

            distances[u][v] = 1;
            distances[v][u] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]); 
                }
            }
        }

        Solution S;

        vector<pair<int, pair<int, int>>> bfs;
        S.getBfs(n, adj, bfs);

        // for(int i=1; i<distances.size(); i++) {
        //     for(int j=1; j<distances[0].size(); j++) {
        //         cout<<distances[i][j]<<" ";
        //     } cout<<endl;
        // }

        sort(bfs.begin(), bfs.end(), custom);

        int dist = 0;

        for(int i=0; i<n-1; i++) {
            int currNode = bfs[i].first;
            int toVisit = bfs[i+1].first;

            dist+=distances[currNode][toVisit];

        }

        cout<<dist<<"\n"; 

        // cout<<S.getDist(n, adj, 3, 5);       
    }

	return 0;
}

// == IN ==
// 1
// 5
// 1 2
// 1 3
// 2 4
// 2 5

// == OUT ==
// 6

// == IN ==
// 2
// 5
// 1 2
// 1 3
// 2 4
// 2 5
// 9
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 7
// 3 8
// 7 9

// == OUT ==
// 6
// 13