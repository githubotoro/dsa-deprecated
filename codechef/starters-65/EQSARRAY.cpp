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
		int n, k;
		cin>>n>>k;

		int arr[n];

		bool kPresent = false;
		int kIndex = -1;

		for(int i=0; i<n; i++) {
			cin>>arr[i];

			if(arr[i] == k && kPresent == false) {
				kPresent = true;
				kIndex = i;
			}
		}

		if(n==1 && arr[0]==k) {
			cout<<"Yes\n";
		} else if(kPresent == true && kIndex != (n-1)) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}

	return 0;
}

// == IN ==
// 4
// 4 10
// 1 2 3 4
// 3 1
// 1 2 3
// 5 5
// 7 -5 5 -2 5
// 4 9
// -9 -9 8 0

// == OUT ==
// No
// Yes
// Yes
// No
