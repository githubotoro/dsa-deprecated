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

int minimumCoins(int coins[], int n, int sum) {
	// base condition
	if(sum==0) return 0;
	if(n==0) return INT_MAX-1;
	if(dp[n][sum] != -1) return dp[n][sum];
	
	// hypothesis and induction
	if(coins[n-1]<=sum) {
		// include and exclude
		return dp[n][sum] = min(1 + minimumCoins(coins, n, sum-coins[n-1]),
				   minimumCoins(coins, n-1, sum));
	} else {
		// exclude
		return dp[n][sum] = minimumCoins(coins, n-1, sum);
	}
}

int main() {
	stayTORO();

	memset(dp, -1, sizeof(dp));

	int coins[] = {25, 15, 5};
	int sum = 50;
	int n = sizeof(coins) / sizeof(coins[0]);
	
	int ways = minimumCoins(coins, n, sum);
	cout<<ways;

	return 0;
}