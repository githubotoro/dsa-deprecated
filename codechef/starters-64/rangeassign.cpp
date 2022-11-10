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
// There can only be two cases:
// 1. 0 to n-1 (1 number series, where first == last)
// 2. 0 to k, k+1 to n-1 (2 number series, where first equals to kth and (k+1)th equals to last)

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		int arr[n];
		
		for(int i=0; i<n; i++) {
			cin>>arr[i];
		}

		int flag = 0;

		int first = arr[0];
		int last = arr[n-1];

		if(first == last) flag=1;

		for(int i=0; i<n-1; i++) {
			if(arr[i] == first && arr[i+1] == last) {
				flag = 1;
			}
		}

		if(flag==1) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}

// IN
// 4
// 5
// 5 9 5 5 5
// 3
// 1 2 3
// 4
// 1 2 1 3
// 4
// 1 2 3 1
// OUT
// YES
// NO
// YES
// YES