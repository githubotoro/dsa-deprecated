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
// print(n) will print n to 1
// Logic:
// I will print the nth element,
// then print(n-1) will print from n-1 to 1
void print(int n) {
	// Base Condition
	if(n==0) return;

	// Induction Step
	cout<<n<<endl;

	// Hypothesis
	print(n-1);
}


int main() {
	stayTORO();

	int n = 5;

	print(n);

	return 0;
}

// OUT
// 5
// 4
// 3
// 2
// 1