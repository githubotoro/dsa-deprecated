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

long long arr[1000001];

int main() {
	stayTORO();

	const long long M = 1000000007;

	int t;
	cin>>t;

	long long num;
	
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;

	for(long long i=3; i<=1000001; i++) {
		arr[i] = i * arr[i-1];
		arr[i] = arr[i] % M;
	}

	while(t--) {
		long long n;
		cin>>n;

		long long ans=0;

		for(long long i=0; i<n; i++) {
			cin>>num;
			ans+=arr[num];
			ans = ans%M;
		}

		cout<<ans<<"\n";
	}

	return 0;
}

// == IN ==
// 3
// 1
// 2
// 2
// 1 2
// 3
// 3 1 3

// == OUT ==
// 2
// 3
// 13