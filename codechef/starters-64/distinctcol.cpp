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
// 1. Find max number in array as ans only depends on that

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int max = INT_MIN;
		int n;
		cin>>n;

		int num;
		
		while(n--) {
			cin>>num;
			if(num > max) max=num;
		}

		cout<<max<<"\n";
	}

	return 0;
}

// IN
// 3
// 2
// 8 5
// 3
// 5 10 15
// 4
// 4 4 4 4
// OUT
// 8
// 15
// 4