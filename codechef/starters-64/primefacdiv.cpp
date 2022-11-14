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
// 1. We need to find whether all prime factors of b exist in a or not.
// 2. So, we will find gcd of a and b
// 3. If gcd is 1 and b is also 1, that means all b has no extra prime factors left, so YES
// 4. Else if gcd is 1 but b is not 1, that means b has some extra prime factors that are not in a, so NO
// 5. Else we will update b by dividing it with gcd(a, b) and go back to step 2

long int getGcd(long int a, long int b) {
	if(b == 0) {
		return a;
	} else {
		return getGcd(b, a % b);
	}
}

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		long int a, b;
		cin>>a>>b;
		long int gcd = -1;

		while(1) {
			gcd = getGcd(a, b);

			if(gcd == 1 && b == 1) {
				cout<<"YES\n";
				break;
			} else if(gcd == 1 && b != 1) {
				cout<<"NO\n";
				break;
			} else {
				b = b/gcd;
			}
		}
	}

	return 0;
}

// == IN ==
// 3
// 21 63
// 72 72
// 25 20

// == OUT ==
// YES
// YES
// NO