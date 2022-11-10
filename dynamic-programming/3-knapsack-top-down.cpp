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

int knapsack(int wt[], int val[], int n, int W) {
	int dp[n+1][W+1];
	memset(dp, -1, sizeof(dp));

	for(int i=0; i<=n; i++) dp[i][0]=0;
	for(int j=0; j<=W; j++) dp[0][j]=0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=W; j++) {
			if(wt[n-1] <= W) {
				dp[i][j] = max( val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j] );
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][W];
}

int main() {
	stayTORO();

	int wt[] = {1, 2, 4, 9, 10, 20};
	int val[] = {4, 20, 8, 36, 20, 80};
	int n = sizeof(wt) / sizeof(wt[0]);
	int W = 20;
	
	int maxProfit = knapsack(wt, val, n, W);
	cout<<maxProfit;

	return 0;
}