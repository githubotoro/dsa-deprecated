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