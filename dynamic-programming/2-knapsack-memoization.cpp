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

int dp[100][1000];
memset(dp, -1, sizeof(dp));

int knapsack(int wt[], int val[], int n, int W) {
	// base condition
	if(n==0 || W==0) return 0;

	// hypothesis and induction
	if(wt[n-1] <= W) {
		// return maximum of (include, exclude)
		return max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
	} else {
		// we cannot include the element, so only one case - exclude
		return knapsack(wt, val, n-1, W);
	}
}

int main() {
	stayTORO();

	int wt[] = {60, 100, 120};
	int val[] = {10, 20, 30};
	int n = sizeof(wt) / sizeof(wt[0]);
	int W = 500;
	
	int maxProfit = knapsack(wt, val, n, W);
	cout<<maxProfit;

	return 0;
}