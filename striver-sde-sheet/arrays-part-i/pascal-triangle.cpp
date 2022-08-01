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

void display(int n, vector<vector<int>> pascal) {
    for(int i=0; i<n; i++) {
        cout<<setw(n-i);

        for(int j=0; j<=i; j++) {
            cout<<pascal[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// NOTES:
// (Indexing is 1 based in below cases)
// To find only specific index, formula is (Row-1)C(Col-1)
// To find only specific row:
// ans *= (n - col)
// ans /= (col + 1) 

// Observations:
// 1. Each row has columns equal to row index
// Ex. 2nd row has 2 cols, 3rd row has 3 cols
// 2. First & last element of each row are 1
// Logic:
// First, we create a dynamic 2D vector with n rows
// Then, we resize each row
// Then, simple add previous row's previous & current indexes
void pascalTriangle(int n) {
    vector<vector<int>> pascal(n);

    for(int row=0; row<n; row++) {
        pascal[row].resize(row+1);

        pascal[row][0] = pascal[row][row] = 1;

        for(int col=1; col<row; col++)
            pascal[row][col] = pascal[row-1][col-1] + pascal[row-1][col];
    }

    display(n, pascal);
}

int main() {
	stayTORO();
  
    pascalTriangle(5);
   
	return 0;
}

