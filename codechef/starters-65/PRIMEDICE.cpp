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

	int t;
	cin>>t;

	map<int, int> mp;
	int primes[5] = {2, 3, 5, 7, 11};

	for(int i=0; i<5; i++) {
		mp[primes[i]] = 1;
	}

	while(t--) {
		int a, b;
		cin>>a>>b;

		if(mp[a+b] == 1) cout<<"Alice\n";
		else cout<<"Bob\n";
	}

	return 0;
}

// == IN ==
// 3
// 2 1
// 1 1
// 2 2

// == OUT ==
// Alice
// Alice
// Bob