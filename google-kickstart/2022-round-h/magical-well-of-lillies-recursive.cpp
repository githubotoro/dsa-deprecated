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

// int minimumCoins(int l, int tossed, int noted) {
//     // base condition
//     if(l<=0) return 0;

//     // hypothesis and induction
//     int ans=INT_MAX;

//     // toss 1 coin at once
//     int ans1 = 1 + minimumCoins(l-1, tossed+1, noted);
//     ans=min(ans, ans1);

//     if(noted != tossed) {
//         // toss 4 coins at once
//         int ans2 = 4 + minimumCoins(l, tossed, tossed);
//         ans=min(ans, ans2);
//     }

//     if(l-noted >= 0 && noted >= 2) {
//         // toss 2 coins at once
//         int ans3 = 2 + minimumCoins(l-noted, tossed+noted, noted);
//         ans=min(ans, ans3);
//     }

//     return ans;
// }

int minimumCoins(int tossed, int noted) {
    // base condition
    if(tossed>=L) return 0;

    // hypothesis and induction
    int ans=INT_MAX;

    // toss 1 coin at once
    int ans1 = 1 + minimumCoins(tossed+1, noted);
    ans=min(ans, ans1);

    if(noted != tossed) {
        // toss 4 coins at once
        int ans2 = 4 + minimumCoins(tossed, tossed);
        ans=min(ans, ans2);
    }

    if(L-tossed-noted >= 0 && noted >= 2) {
        // toss 2 coins at once
        int ans3 = 2 + minimumCoins(tossed+noted, noted);
        ans=min(ans, ans3);
    }

    return ans;
}

int main() {
	stayTORO();

    int cases;
    cin>>cases;

    for(int t=1; t<=cases; t++) {
        cin>>L;

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
