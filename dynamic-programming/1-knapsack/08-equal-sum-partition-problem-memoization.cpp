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

bool subsetSum(int arr[], int n, int sum) {
	// base condition
	if(n==0) {
		if(sum == 0) return true;
		else return false;
	}
	
	if(sum==0) {
		return true;
	}

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

	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	int maxSum = 0;
	for(int i=0; i<n; i++) maxSum+=arr[i];
	
	if(maxSum%2 == 1) cout<<false;
	else {
		int sum = maxSum/2;
		bool partitionPossible = subsetSum(arr, n, sum);
		cout<<partitionPossible;
	}

	return 0;
}