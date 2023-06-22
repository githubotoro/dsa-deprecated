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

int main() {
	stayTORO();

	const unsigned int M = 1000000007;

	int t;
	cin>>t;

	while(t--) {
		long double n;
		cin>>n;

		long ans = long(ceil(n/2)) % M;

		cout<<ans<<"\n";
	}

	return 0;
}

// == IN ==
// 3
// 2
// 5
// 197654321

// == OUT ==
// 1
// 3
// 98827161