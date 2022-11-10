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

int knapsack(int wt[], int val[], int W, int n) {
	// base condition
	if(W==0 || n==0) return 0;

	// hypothesis and induction
	if(wt[n-1] <= W) {
		// return maximum of (include, exclude)
		return max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
	} else {
		// we cannot include the element, so only one case - exclude
		return knapsack(wt, val, W, n-1);
	}
}

int main() {
	stayTORO();

	int wt[] = {60, 100, 120};
	int val[] = {10, 20, 30};
	int W = 500;
	int n = sizeof(wt) / sizeof(wt[0]);

	int maxProfit = knapsack(wt, val, W, n);
	cout<<maxProfit;

	return 0;
}