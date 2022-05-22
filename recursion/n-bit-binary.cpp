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

// Hypothesis:
// nBitBinary will print all numbers whose all prefixes
// have number of 1s greater than or equal to number of 0s
// Logic:
// If n==0, that means all spaces have been filled, so print the answer
// Else, we have an empty space to fill
// If number of ones > number of zeroes, then we have 2 choices
// We can put either "0" or "1"
// Else, we have only 1 choice, put "1"
void nBitBinary(string ans, int ones, int zeroes, int n) {
	// Base Condition
	if(n == 0) {
		cout<<ans<<endl;
		return;
	}

	// Hypothesis and Induction
	if(ones > zeroes) {
		nBitBinary(ans+"1", ones+1, zeroes, n-1);
		nBitBinary(ans+"0", ones, zeroes+1, n-1);
	} else {
		nBitBinary(ans+"1", ones+1, zeroes, n-1);
	}
}

int main() {
	stayTORO();

	int n=3;

	nBitBinary("", 0, 0, n);

	return 0;
}

// OUT 
// 111
// 110
// 101