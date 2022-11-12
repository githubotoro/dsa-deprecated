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

int rodCutting(int len[], int price[], int n, int L) {
	int dp[n+1][L+1];

	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int j=0; j<=L; j++) dp[0][j] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=0; j<=L; j++) {
			if(len[i-1] <= j) {
				dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][L];
}

int main() {
	stayTORO();

	int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(len) / sizeof(len[0]);
	int L = n;
	
	int maxProfit = rodCutting(len, price, n, L);
	cout<<maxProfit;

	return 0;
}