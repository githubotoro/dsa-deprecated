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

int countSubsetSum(int arr[], int n, int sum) {
	int dp[n+1][sum+1];

	for(int i=0; i<=n; i++) dp[i][0] = 1;
	for(int j=1; j<=sum; j++) dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

int main() {
	stayTORO();

	int arr[] = {1, 1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int diff = 1;

	int arrSum = 0;
	for(int i=0; i<n; i++) arrSum+=arr[i];

	int sum = (diff + arrSum) / 2;
	
	cout<<countSubsetSum(arr, n, sum);

	return 0;
}