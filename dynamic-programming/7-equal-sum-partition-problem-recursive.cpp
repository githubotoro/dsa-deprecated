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

bool subsetSum(int arr[], int n, int sum) {
	// base condition
	if(n==0) {
		if(sum == 0) return true;
		else return false;
	}
	
	if(sum==0) {
		return true;
	}

	// hypothesis and induction
	if(arr[n-1] <= sum) {
		return (subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum));
	} else {
		return subsetSum(arr, n-1, sum);
	}
}

int main() {
	stayTORO();

	int arr[] = {1, 5, 12, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	int maxSum = 0;
	for(int i=0; i<n; i++) maxSum+=arr[i];
	
	if(maxSum%2 == 1) cout<<false;
	else {
		int sum = maxSum/2;
		bool partitionPossible = subsetSum(arr, n, sum);
		cout<<partitionPossible;
	}

	return 0;
}