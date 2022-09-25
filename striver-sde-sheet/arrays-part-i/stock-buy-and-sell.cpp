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

// Problem can be reduced to:
// Find the maximum possible difference between 2 numbers in an array
// such that the smaller number appears before the larger number

// Algorithm:
// 1. Maintain two variables diff (0) and currMin (INT_MAX)
// 2. Traverse array from left to right
// 3. Update currMin if array element is less than currMin
// 4. Update diff if array element - currMin is greater than diff

// Time Complexity: O(n)
// Space Complexity: O(1)
int stonks(const int arr[], const int n) {
    int diff = 0;
    int currMin = INT_MAX;

	for(int i=0; i<n; i++) {
        currMin = min(currMin, arr[i]);
        diff = max(diff, arr[i] - currMin);
    }

	return diff;
}

int main() {
	stayTORO();
  
	int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<stonks(arr, n);
   
	return 0;
}

// IN
// 6
// 7 1 5 3 6 4
// OUT
// 5