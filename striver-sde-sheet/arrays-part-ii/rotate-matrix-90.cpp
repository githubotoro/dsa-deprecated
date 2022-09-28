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

void displayMatrix(const vector<vector<int>> &mat) {
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[0].size(); j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}

// Algorithm:
// 1. Find Transpose
// 2. Reverse all the rows
// Result: Matrix is rotated by 90 degree in clockwise direction

// Time Complexity: O(n*n)
// Space Complexity: O(1)
void rotate(vector<vector<int>> &mat) {
	for(int i=0; i<mat.size(); i++)
		for(int j=0; j<i; j++)
			swap(mat[i][j], mat[j][i]);
		
	for(int i=0; i<mat.size(); i++)
		reverse(mat[i].begin(), mat[i].end());
}

int main() {
	stayTORO();
  
	int n;
	cin>>n;

	vector<vector<int>> v(n, vector<int> (n, 0));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>v[i][j];
	
	rotate(v);

	displayMatrix(v);
   
	return 0;
}

// IN
// 3
// 1 2 3 
// 4 5 6
// 7 8 9
// OUT
// 7 4 1 
// 8 5 2 
// 9 6 3 
