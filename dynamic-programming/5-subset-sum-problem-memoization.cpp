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

int dp[100][100];

int subsetSum(int arr[], int n, int sum) {
	// base condition
    if(dp[n][sum] != -1) return dp[n][sum];

	// hypothesis and induction
	if(arr[n-1] <= sum) {
		return dp[n][sum] = (subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum));
	} else {
		return dp[n][sum] = subsetSum(arr, n-1, sum);
	}
}

int main() {
	stayTORO();

    memset(dp, -1, sizeof(dp));

	int arr[] = {3, 34, 4, 12, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 9;
	
	bool subsetExists = subsetSum(arr, n, sum);
	cout<<subsetExists;

	return 0;
}