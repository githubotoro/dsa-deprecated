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

int minimumCoins(int L) {
    int dp[L+1][L+1];

    for(int i=0; i<=L; i++) dp[i][L] = L-i;
    for(int j=0; j<=L; j++) dp[L][j] = 0;

    for(int i=L-1; i>=0; i--) {
        for(int j=L-1; j>=0; j--) {
            int ans=INT_MAX;

            // toss 1 coin at once
            int ans1 = 1 + dp[i+1][j];
            dp[i][j] = min(ans, ans1);

            if(j != i && L-i >= 7) {
                // toss 4 coins at once
                int ans2 = 4 + dp[i][i];
                dp[i][j] = min(ans, ans2);
            }

            if(L-i-j >= 0 && j >= 3) {
                // toss 2 coins at once
                int ans3 = 2 + dp[i+j][j];
                dp[i][j] = min(ans, ans3);
            }
        }
    }

    return dp[0][0];
}

int main() {
	stayTORO();

    int cases;
    cin>>cases;

    for(int t=1; t<=cases; t++) {
        int l;
        cin>>l;

        cout<<"Case #"<<t<<": "<<minimumCoins(l)<<"\n";
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
