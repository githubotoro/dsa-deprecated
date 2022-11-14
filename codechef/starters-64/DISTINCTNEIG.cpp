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
// The maximum number of a times an element can occur is n + floor[(n+1)/2]

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		int arr[2 * n];

		int flag = 1;
		map<int, int> mp;

		// C++ will automatically take floor beacuse of int typecasting,
		// but still writing floor for better readability
		int limit = floor(n + (n+1) / 2);
		
		for(int i=0; i<2*n; i++) {
			cin>>arr[i];

			mp[arr[i]]++;
			if(mp[arr[i]] > limit) flag=0;
		}

		if(flag==1) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}

// == IN ==
// 3
// 2
// 1 1 1 1
// 3
// 1 1 2 2 3 3
// 2
// 1 1 2 2

// == OUT ==
// NO
// YES
// YES