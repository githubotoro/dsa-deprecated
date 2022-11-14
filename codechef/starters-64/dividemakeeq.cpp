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

// Logic:
// 1.  Let initial gcd, prevGcd = currGcd = arr[0]
// 2.  Traverse the remaining elements of the array
// 2.1 Find new gcd of previous gcd (prevGcd) and current array element (arr[i])
// 2.2 Update previous gcd (prevGcd) to new gcd (currGcd)
// 3.  Traverse the array again
// 3.1 If array element (arr[i]) is not equal to current gcd (currGcd), 
//     then we would need to change the number which would require 1 step,
//     so we will add 1 to answer (ans) 

int getGcd(int a, int b) {
	if(b == 0) {
		return a;
	} else {
		return getGcd(b, a % b);
	}
}

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int ans = 0;

		int n;
		cin>>n;

		int arr[n];
		cin>>arr[0];

		int prevGcd = arr[0];
		int currGcd = prevGcd;

		for(int i=1; i<n; i++) {
			cin>>arr[i];

			currGcd = getGcd(prevGcd, arr[i]);
			prevGcd = currGcd;
		}

		for(int i=0; i<n; i++) {
			if(arr[i] != currGcd ) ans++;
		}

		cout<<ans<<"\n";
	}

	return 0;
}

// == IN ==
// 4
// 2
// 11 22
// 5
// 38 38 38 38 38
// 4
// 4 4 16 8
// 4
// 11 13 17 19

// == OUT ==
// 1
// 0
// 2
// 4