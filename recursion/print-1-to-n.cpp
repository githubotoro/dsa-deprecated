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
// print(n) will print 1 to n
// Logic:
// print(n-1) will print from 1 to n-1,
// then I will print nth element
void print(int n) {
	// Base Condition
	if(n==0) return;

	// Hypothesis
	print(n-1);

	// Induction Step
	cout<<n<<endl;
}


int main() {
	stayTORO();

	int n = 5;

	print(n);

	return 0;
}

// OUT
// 1
// 2
// 3
// 4
// 5