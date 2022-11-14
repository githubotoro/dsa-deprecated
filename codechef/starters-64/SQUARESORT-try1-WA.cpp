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

long long int squareSort(long long int arr[], long long int n) {
	// base condition
	if(n==0 || n==1) return 0;

	// hypothesis and induction
	if(arr[n-2] > arr[n-1]) {
		long long int ans1 = INT_MAX;
		long long int ans2 = INT_MAX;

		if(pow(arr[n-1], 2) > arr[n-1]) {
			arr[n-1] = pow(arr[n-1], 2);
			ans1 = 1 + squareSort(arr, n);
		}

		if(floor(pow(arr[n-2], 0.5)) < arr[n-2]) {
			arr[n-2] = floor(pow(arr[n-2], 0.5));
			ans2 = 1 + squareSort(arr, n);
		}

		return min(ans1, ans2);
	} else {
		return squareSort(arr, n-1);
	}
}

int main() {
	stayTORO();

	long long int t;
	cin>>t;

	while(t--) {
		long long int n;
        cin>>n;

        long long int arr[n];

        for(long long int i=0; i<n; i++) {
            cin>>arr[i];
        }

		cout<<squareSort(arr, n)<<"\n";
	}

	return 0;
}

// IN
// 3
// 4
// 1 3 9 9
// 4
// 1 9 3 9
// 3
// 4 2 1
// OUT
// 0
// 1
// 3