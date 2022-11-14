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

	char c;

	while(t--) {
		int n;
		cin>>n;

		if(n%2 == 0) {
			map<char, int>track;
			int flag = 1;

			for(int i=0; i<n; i++) {
				cin>>c;
				track[c]++;
			}

			for(auto ele : track) {
				if(ele.second%2 != 0) {
					flag=0;
					break;
				}
			}

			if(flag==1) cout<<"YES\n";
			else cout<<"NO\n";
		} else {
			string s;
			cin>>s;
			cout<<"NO\n";
		}
	}

	return 0;
}

// == IN ==
// 4
// 4
// abab
// 5
// cbcba
// 4
// abcd
// 6
// pqprqr

// == OUT ==
// YES
// NO
// NO
// YES