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

void search(_txt, _pat) {
    vector<char> txt(_txt.begin(), _txt.end());
    vector<char> pat(_pat.begin(), _pat.end());

    
}

int main() {
	stayTORO();

    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";

    search(txt, pat);

	return 0;
}

// IN
// 9
// 1 2 3 4 5 6 7 8 9
// OUT
// 9 8 7 6 4 3 2 1 