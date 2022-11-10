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

// Matrix Properties (Row-wise and Column-wise sorted Matrix)
// 1. Row elements are sorted from left to right
// 2. First element of each row is greater than previous row

// Algorithm (Use Case of Binary Search)
// 1. Make 2 pointers - Low points to 

bool search(const vector<vector<int>> &mat, const int target) {
	bool ans = false;

	return ans;
}

int main() {
	stayTORO();
  
	int rows, cols, target;
	bool ans;
	cin>>rows>>cols;

	vector<vector<int>> v(rows, vector<int> (cols, 0));

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			cin>>v[i][j];
	
	cin>>target;
	
	ans = search(v, target);

	cout<<ans;

	return 0;
}

// IN
// 8
// 1 3
// 2 4
// 2 6
// 8 9
// 8 10
// 9 11
// 15 18
// 16 17
// OUT
// 1 6 
// 8 11 
// 15 18 
