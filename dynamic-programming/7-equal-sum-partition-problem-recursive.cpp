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
	// base condition
	if(n == 0) {
		if(sum1 == sum2) return true;
		else return false;
	}

	// hypothesis and induction
	return (equalSumPartition(arr, n-1, sum1+arr[n-1], sum2) ||
			equalSumPartition(arr, n-1, sum1, sum2+arr[n-1]));
}

int main() {
	stayTORO();

	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum1 = 0;
	int sum2 = 0;
	
	bool partitionPossible = equalSumPartition(arr, n, sum1, sum2);
	cout<<partitionPossible;

	return 0;
}