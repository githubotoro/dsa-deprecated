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

	const long long M = 998244353;

	int t;
	cin>>t;

	long long num;

	while(t--) {
		long long n;
		cin>>n;

		long long ones=0;

		for(long long i=0; i<n; i++) {
			cin>>num;
			ones+=num;
			ones = ones%M;
		}

		ones = (ones*(ones-1))%M;

		cout<<ones<<"\n";
	}

	return 0;
}

// == IN ==
// 2
// 2
// 1 2
// 2
// 1 3

// == OUT ==
// 6
// 12