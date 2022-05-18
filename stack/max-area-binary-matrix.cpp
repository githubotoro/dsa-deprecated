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

struct node {
	int index;
	int value;
};

struct answer {
	int nextSmaller;
	int precedingSmaller;
};

int traverse(stack <node> &s, const int &ele) {
	// If stack is empty, return -1
	// else if top of stack is less than given element
	// then, return the index stored in top of stack
	if (s.size() == 0) return -1;
	else if (s.top().value < ele) return s.top().index;
	
	// If base condition is false,
	// pop from stack
	// and call traverse function again
	s.pop();
	traverse(s, ele);
}

int getMaxArea(const int arr[], const int &n) {
	answer ans[n];

	stack <node> stNext, stPreceding;

	// Functionality of next smaller and preceding smaller have been combined
	for(int i=0, j=n-1; i<n, j>=0; i++, j--) {
		// Calling recursive function
		int precedingSmaller = traverse(stPreceding, arr[i]);
		int nextSmaller = traverse(stNext, arr[j]);

		// If we get -1, means there is no smaller element on LHS
		// since, we are already returning -1, there would be no adjustments here
		// ans will be index of precedingSmalle
		ans[i].precedingSmaller =  precedingSmaller;

		// If we get -1, means there is no smaller element on RHS
		// so, nextSmaller will be n
		// else ans will be index of nextSmaller
		if(nextSmaller == -1) ans[j].nextSmaller = n;
		else ans[j].nextSmaller =  nextSmaller;

		// Creating new nodes
		node precedingNode, nextNode;

		precedingNode.index = i;
		precedingNode.value = arr[i];

		nextNode.index = j;
		nextNode.value = arr[j];

		// At last, push nodes into the stack
		stPreceding.push(precedingNode);
		stNext.push(nextNode);
	}

	int maximumArea = 0;

	// Displaying maximum area
	for(int i=0; i<n; i++) maximumArea = max(maximumArea, arr[i] * (ans[i].nextSmaller - ans[i].precedingSmaller - 1));
	
	return maximumArea;
}

int main() {
	stayTORO();

	int n, m;
	cin>>n>>m;

	// Taking input matrix
	int matrix[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>matrix[i][j];
	
	// Initalizing a zero array
	int arr[m] = {0};
	
	int maxArea = 0;
	
	// We will be traversing each row, then initialize the declared array arr
	// After initializing, we will pass it to getMaxArea()
	// After every row iteration, we will update value of maxArea
	for(int row=0; row<n; row++) {
		for(int col=0; col<m; col++) {
			if(matrix[row][col] == 0) arr[col] = 0;
			else arr[col] += matrix[row][col];
		}

		maxArea = max(maxArea, getMaxArea(arr, m));
	}

	cout<<maxArea;

	return 0;
}

// IN
// 4 4
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// OUT
// 8