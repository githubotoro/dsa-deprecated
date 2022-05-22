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
// printPermutations will print all permutaions of str with case change
// Logic:
// If str is empty, then per will be the permutaion
// Else, we have 2 choices for the element
// First, change the case
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

	printPermutations(per+char(ele ^ (1<<5)), str);
	printPermutations(per+ele, str);
}

int main() {
	stayTORO();

	string str = "abc";

	printPermutations("", str);

	return 0;
}

// OUT 
// "abc"
// "abC"
// "aBc"
// "aBC"
// "Abc"
// "AbC"
// "ABc"
// "ABC"