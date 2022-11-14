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

	long long int n, k, l;

	while(t--) {
		cin>>n>>k>>l;

        long long int total = k+l;

        if(total > n) {
            long long int overlapping = total-n;
            n = n - overlapping;
            k = k - overlapping;
            l = l - overlapping;
        }

		long long int sourceToVertex = k * (n-k);
        long long int vertexToSink = (n-(k+l))*l;
        long long int vertexToVertex = ((n - (k+l) - 1) * (n - (k+l))) / 2;

        long long int ans = sourceToVertex + vertexToSink + vertexToVertex;
        
        cout<<ans<<"\n";
	}

	return 0;
}

// == IN ==
// 2
// 3 1 1
// 5 3 3

// == OUT ==
// 3
// 4