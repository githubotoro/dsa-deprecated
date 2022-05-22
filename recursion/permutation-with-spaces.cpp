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
// printPermutations will print all permutaions of str with spaces
// Logic:
// If str is empty, then per will be the permutaion
// Else, we have to take decision, whether to put space or not after element
// If there is already a char in per,
// then we have 2 choices, we can include space and exclude space
// Else, we have only 1 choice, we can't include space
void printPermutations(string per, string str) {
	// Base Condition
	if(str == "") {
		cout<<'"'<<per<<'"'<<endl;
		return;
	}

	// Hypothesis and Induction
	char ele = str[0];
	str.erase(str.begin());

	if(per != "") {
		printPermutations(per+"_"+ele, str);
		printPermutations(per+ele, str);
	} else {
		printPermutations(per+ele, str);
	}
}

int main() {
	stayTORO();

	string str = "abc";

	printPermutations("", str);

	return 0;
}

// OUT 
// "a_b_c"
// "a_bc"
// "ab_c"
// "abc"