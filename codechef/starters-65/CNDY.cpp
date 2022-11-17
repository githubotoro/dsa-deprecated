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

	while(t--) {
		int n;
		cin>>n;

		map<int, int> mp;
		int flag = 1;

		int num;
		for(int i=0; i<2*n; i++) {
			cin>>num;
			mp[num]++;
			if(mp[num] == 3) flag=0;
		}

		if(flag==1) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}

// == IN ==
// 4
// 3
// 4 8 4 6 7 3
// 3
// 4 8 6 8 7 8
// 2
// 2 4 5 3
// 4
// 8 7 9 8 4 6 2 8

// == OUT ==
// Yes
// No
// Yes
// No
