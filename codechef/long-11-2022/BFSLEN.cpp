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

        int ans = 1;

        int visitedNodes = 1;

		
		// algorithm
		while(!q.empty()) {
			// taking last node
			int currNode = q.front().first;
			int currHeight = q.front().second;

			q.pop();
            bfs.push_back({currNode,{currHeight, adj[currNode].size()}});

			// visiting all neighbors of the current node
			for(auto neighbor : adj[currNode]) {
				if(!visited[neighbor]) {
					visited[neighbor] = 1;
					q.push({neighbor, currHeight+1});
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

        // temporary variables for inputing edge nodes
        int u, v;

        // taking 1-based indexing
        for(int i=1; i<=n-1; i++) {
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution S;

        vector<pair<int, pair<int, int>>> bfs;
        S.getBfs(n, adj, bfs);

        sort(bfs.begin(), bfs.end(), custom);

        bfs.push_back({0, {0,0}});

        int visited = 1;
        int currNode = bfs[0].first;
        int toVisit = bfs[1].first;
        int dist = 0;
        int bfsTracker = 1;
        vector<int> path;
        path.push_back(currNode);

        for(auto ele : bfs) {
            cout<<"Node "<<ele.first<<" - Height "<<ele.second.first<<" - Neighbors "<<ele.second.second<<endl;
        }



        while(visited != n) {
            bool notVisited = true;

            for(int i=0; i<adj[currNode].size(); i++) {
                if(adj[currNode][i] == toVisit) {
                    cout<<"Curr Node is "<<currNode<<endl;
                    cout<<"Currently visiting "<<toVisit<<endl;

                    currNode = toVisit;

                    cout<<"Updated curr node is "<<currNode<<endl;
                    path.push_back(toVisit);
                    dist++;
                    bfsTracker++;
                    toVisit = bfs[bfsTracker].first;
                    cout<<"Next node to visit is "<<toVisit<<endl;
                    
                    cout<<endl;
                    notVisited = false;
                    visited++;
                    break;
                }
            }

            if(notVisited == true) {
                dist = dist + bfs[currNode].second.first + bfs[toVisit].second.first;
                currNode = toVisit;
                
                bfsTracker++;
                toVisit = bfs[bfsTracker].first;
                visited++;

                // cout<<"Path last element is "<<path[path.size()-1]<<endl;
                // path.pop_back();
                // currNode = path[path.size()-1];
                // dist++;
            }
        }

        cout<<dist<<"\n";
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