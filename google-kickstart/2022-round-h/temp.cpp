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

    int cases;
    cin>>cases;

    for(int t=1; t<=cases; t++) {
        int l, n;
        cin>>l>>n;

        long long int d[n];
        char c[n];

        cin>>d[0]>>c[0];

        long long int totalLaps = floor(d[0]/l);
        long long int currLaps = totalLaps;
        long long int currDist = d[0] % l;
        char currDirect = c[0];

        for(int i=1; i<n; i++) {
            cin>>d[i]>>c[i];

            if(currDirect == c[i]) {
                currDist += d[i];
                currLaps = floor(currDist/l);
                totalLaps += currLaps;
                currDist = currDist % l;
            } else {
                currDist = -1 * currDist;
                currDist += d[i];
                if(currDist >= 0) {
                    currLaps = floor(currDist/l);
                    totalLaps += currLaps;
                    currDist = currDist % l;
                }
                currDirect = c[i];
            }
        }

        cout<<"Case #"<<t<<": "<<totalLaps<<"\n";
    }


	return 0;
}

// == IN ==
// 2
// 5 3
// 8 C
// 3 C
// 6 C
// 8 4
// 5 C
// 9 C
// 8 C
// 20 C

// == OUT ==
// Case #1: 3
// Case #2: 5