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

int L;

map<pair<int, int>, bool> track_mp;
map<pair<int, int>, int> mp;

int minimumCoins(int tossed, int noted) {
    // base condition
    if(tossed>=L) return 0;
    if(track_mp[{tossed, noted}] == true) return mp[{tossed, noted}];

    // hypothesis and induction
    int ans=INT_MAX;

    // toss 1 coin at once
    int ans1 = 1 + minimumCoins(tossed+1, noted);
    ans=min(ans, ans1);

    if(noted != tossed && L-tossed >= 7) {
        // toss 4 coins at once
        int ans2 = 4 + minimumCoins(tossed, tossed);
        ans=min(ans, ans2);
    }

    if(L-tossed-noted >= 0 && noted >= 2) {
        // toss 2 coins at once
        int ans3 = 2 + minimumCoins(tossed+noted, noted);
        ans=min(ans, ans3);
    }

    track_mp[{tossed, noted}] = true;
    mp[{tossed, noted}] = ans;

    return ans;
}

int main() {
	stayTORO();

    int cases;
    cin>>cases;

    for(int t=1; t<=cases; t++) {
        cin>>L;

        track_mp.clear();
        mp.clear();
        cout<<"Case #"<<t<<": "<<minimumCoins(0, 0)<<"\n";
    }

	return 0;
}

// == IN ==
// 2
// 5
// 20

// == OUT ==
// Case #1: 5
// Case #2: 15
