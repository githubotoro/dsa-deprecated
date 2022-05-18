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

int traverse(stack <node> &s, const int &ele) {
	// If stack is empty, return -1
	// else if top of stack is greater than given element
	// then, return the index stored in top of stack
	if (s.size() == 0) return -1;
	else if (s.top().value > ele) return s.top().index;
	
	// If base condition is false,
	// pop from stack
	// and call traverse function again
	s.pop();
	traverse(s, ele);
}

int main() {
	stayTORO();

	int n;
	cin>>n;

	int arr[n];
	int ans[n];

	stack <node> s;

	// Taking input array
	for(int i=0; i<n; i++) cin>>arr[i];

	// Traverse array from left side
	for(int i=0; i<n; i++) {
		// Calling recursive function
		int temp = traverse(s, arr[i]);
		
		// If we get -1, means there is no greater element on LHS
		// so, ans will be 1
		// else ans will be: current_index - greater_element_index
		if(temp == -1) ans[i] = 1;
		else ans[i] = i - temp;

		// creating new node
		node newNode;
		newNode.index = i;
		newNode.value = arr[i];

		// At last, push node into the stack
		s.push(newNode);
	}

	// Displaying output array
	for(int i=0; i<n; i++) cout<<ans[i]<<" ";
	
	return 0;
}

// IN
// 8
// 90 50 60 40 80 70 30 80
// OUT
// 1 1 2 1 4 1 1 7 