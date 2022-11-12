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

int knapsack(int wt[], int val[], int n, int W) {
	// base condition
	if(dp[n][W] != -1) return dp[n][W];

	// hypothesis and induction
	if(wt[n-1] <= W) {
		// include or exclude
		return dp[n][W] = max(val[n-1] + knapsack(wt, val, n, W-wt[n-1]),
				   knapsack(wt, val, n-1, W));
	} else {
		// exclude
		return dp[n][W] = knapsack(wt, val, n-1, W);
	}
}

int main() {
	stayTORO();

	memset(dp, -1, sizeof(dp));

	int wt[] = {1, 2, 4, 9, 10, 20};
	int val[] = {4, 20, 8, 36, 20, 80};
	int n = sizeof(wt) / sizeof(wt[0]);
	int W = 20;
	
	int maxProfit = knapsack(wt, val, n, W);
	cout<<maxProfit;

	return 0;
}