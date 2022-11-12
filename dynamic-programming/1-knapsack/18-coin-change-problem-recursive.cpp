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
	// base condition
	if(n==0) {
		if(sum==0) return 1;
		else return 0;
	}

	if(sum==0) {
		return 1;
	}

	// hypothesis and induction
	if(coins[n-1] <= sum) {
		return coinChange(coins, n, sum-coins[n-1]) + coinChange(coins, n-1, sum);
	} else {
		return coinChange(coins, n-1, sum);
	}
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