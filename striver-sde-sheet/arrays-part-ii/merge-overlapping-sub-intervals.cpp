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

void display(const vector<vector<int>> &mat) {
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[0].size(); j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}

// Algorithm:
// 1. Sort the intervals
// 2. Merge them by comparing 2nd ele of prev with first ele of next
// If can be merged, select max of 2nd ele of prev and next

// Time Complexity: O(n*logn) + O(n)
// O(n*logn) -> Sorting, O(n) -> Traversal
// Space Complexity: O(n)
vector<vector<int>> merge(vector<vector<int>> &mat) {
	sort(mat.begin(), mat.end());

	vector<vector<int>> ans;
	ans.push_back(mat[0]);

	for(int i=1; i<mat.size(); i++) {
		if(ans[ans.size()-1][1] >= mat[i][0])
			ans[ans.size()-1][1] = max(ans[ans.size()-1][1], mat[i][1]);
		else
			ans.push_back(mat[i]);
	}

	return ans;
}

int main() {
	stayTORO();
  
	int n;
	cin>>n;

	vector<vector<int>> v(n, vector<int> (2, 0));
	vector<vector<int>> ans;

	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++)
			cin>>v[i][j];
	
	ans = merge(v);

	display(ans);

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
