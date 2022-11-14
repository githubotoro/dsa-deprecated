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
// 1. String is divided into 2 halfs (0 to n/2 - 1, n/2 to n-1 )
// 2. Compare each half char by char, if anyone mismatchs, then NO else YES

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		string s;
		cin>>s;

		int i = 0;
		int j = n/2;
		int flag = 1;

		for(; i < n/2; i++, j++) {
			if(s[i] != s[j]) {
				flag=0;
				break;
			}
		}

		if(flag==1) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}

// == IN ==
// 4
// 6
// abcabc
// 6
// abcdef
// 4
// aaaa
// 4
// baab

// == OUT ==
// YES
// NO
// YES
// NO