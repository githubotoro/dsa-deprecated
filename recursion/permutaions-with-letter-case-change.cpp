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
// printPermutations will print all permutaions of str with letter case change
// Logic:
// If str is empty, then per will be the permutaion
// Else, we have 2 choices for the element
// First, change the case if it is char
// Second, keep it as it is
// GFG Trick:
// (char) ^ (1 << 5) toggles the 5th bit
// which means 97 will become 65 and 65 will become 97
// But, it will give int value, so we have to convert that to char
void printPermutations(string per, string str) {
	// Base Condition
	if(str == "") {
		cout<<'"'<<per<<'"'<<endl;
		return;
	}

	// Hypothesis and Induction
	char ele = str[0];
	str.erase(str.begin());

	if(isalpha(ele)) {
		printPermutations(per+char(ele ^ (1<<5)), str);
		printPermutations(per+ele, str);
	} else {
		printPermutations(per+ele, str);
	}
}

int main() {
	stayTORO();

	string str = "a1b2c3";

	printPermutations("", str);

	return 0;
}

// OUT 
// "A1B2C3"
// "A1B2c3"
// "A1b2C3"
// "A1b2c3"
// "a1B2C3"
// "a1B2c3"
// "a1b2C3"
// "a1b2c3"