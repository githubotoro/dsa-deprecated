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

int minimumSubsetSumDifference(int arr[], int n) {
	int maxSum = 0;
	for(int i=0; i<n; i++) maxSum+=arr[i];

	bool dp[n+1][maxSum+1];

	for(int i=0; i<=n; i++) dp[i][0] = true;
	for(int j=1; j<=maxSum; j++) dp[0][j] = false;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=maxSum; j++) {
			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int diff = INT_MAX;
	for(int j=0; j<=maxSum; j++) {
		if(dp[n][j] == true) {
			diff = min(abs(maxSum - 2 * j), diff);
		}
	}

	return diff;
}

int main() {
	stayTORO();

	int arr[] = {1, 6, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout<<minimumSubsetSumDifference(arr, n);

	return 0;
}