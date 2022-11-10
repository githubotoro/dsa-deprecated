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

bool equalSumPartition(int arr[], int n, int sum1, int sum2) {
    int maxSum = 0;
    for(int i=0; i<n; i++) maxSum+=arr[i];

    int dp[n+1][maxSum+1][maxSum+1];
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;

    for(int j=1; j<=sum1; j++) {
        dp[0][j][0] = false;
    }

    for(int k=1; k<=sum2; k++) {
        dp[0][0][k] = false;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum1; j++) {
            for(int k=1; k<=sum2; k++) {
                dp[i][j][k] = ( dp[i-1][j+arr[i-1]][k] || dp[i-1][j][k+arr[i-1]] );
            }
        }
    }

	for(int m=1; m<=maxSum; m++) {
        if(dp[n][m][m] == 1) return true;
    }

    return false;
}

int main() {
	stayTORO();

	int arr[] = {1, 5, 24, 20};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum1 = 0;
	int sum2 = 0;
	
	bool partitionPossible = equalSumPartition(arr, n, sum1, sum2);
	cout<<partitionPossible;

	return 0;
}