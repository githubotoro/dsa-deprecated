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

int coinChange(int coins[], int n, int sum) {
	int dp[n+1][sum+1];

	for(int i=0; i<=n; i++) dp[i][0] = 1;
	for(int j=1; j<=sum; j++) dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			if(coins[i-1] <= j) {
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

int main() {
	stayTORO();

	int coins[] = {1, 2, 5};
	int sum = 4;
	int n = sizeof(coins) / sizeof(coins[0]);
	
	int ways = coinChange(coins, n, sum);
	cout<<ways;

	return 0;
}