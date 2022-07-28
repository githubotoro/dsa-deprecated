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
// First row and first column are taken as dummmy arrays
// These dummy arrays will indicate whether arr[row][col] should be 0 or not
// Also, we will take one extra variable col0
// Why col0? Because, arr[0][0] overlaps
// First, traverse entire array and initialize the dummy arrays
// Then, traverse entire array from back and set values accordingly
void setMatrixZeroes(vector<vector<int>> &arr) {
	int rows = arr.size();
	int cols = arr[0].size();
	int col0 = -1;

    

	// first traversal
	for(int row=0; row<rows; row++) {

		if(arr[row][0] == 0) col0=0;

		for(int col=1; col<cols; col++) {
			if(arr[row][col] == 0) {
				arr[row][0] = 0;
				arr[0][col] = 0;
			}
		}
	}

	// second traversal
	for(int row=rows-1; row>=0; row--) {

		if(col0 == 0) arr[row][0]=0;

		for(int col=cols-1; col>=1; col--) {
			if(arr[row][0] == 0 || arr[0][col] == 0) {
				arr[row][col] = 0;
			}
		}
	}

}

void display(vector<vector<int>> &arr) {
	for(int i=0; i<arr.size(); i++) {
		for(int j=0; j<arr[0].size(); j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	stayTORO();

    vector<vector<int>> arr;
    arr = {
		{1, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5}
	};

    setMatrixZeroes(arr);

    display(arr);

	return 0;
}

