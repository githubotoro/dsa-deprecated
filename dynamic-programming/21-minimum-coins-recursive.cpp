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

int minimumCoins(int coins[], int n, int sum) {
	// base condition

	// when sum required is 0, we need 0 coins,
	// so it is independent of the number of coins (n)
	if(sum==0) return 0;
	
	// when number of coins available are 0,
	// then there are 2 cases:
	// 1. if sum is 0, then 0 coins
	// 2. if sum is not 0, then infinite coins
	// -> now, first case is handled automatically,
	// because if(sum==0) statement has been placed first
	// -> to avoid overflow, INT_MAX-1 is used as infinite coins
	if(n==0) return INT_MAX-1;
	
	// hypothesis and induction
	if(coins[n-1]<=sum) {
		// include and exclude
		return min(1 + minimumCoins(coins, n, sum-coins[n-1]),
				   minimumCoins(coins, n-1, sum));
	} else {
		// exclude
		return minimumCoins(coins, n-1, sum);
	}
}

int main() {
	stayTORO();

	int coins[] = {25, 15, 5};
	int sum = 100;
	int n = sizeof(coins) / sizeof(coins[0]);
	
	int ways = minimumCoins(coins, n, sum);
	cout<<ways;

	return 0;
}