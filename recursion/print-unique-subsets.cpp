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
// printSubsets will print all subsets of string str
// Logic:
// If string is empty, that means there is subset in sub
// We will check that sub is present in map or not, 
// If not, print and include in map, else don't print
// Then, we have to decide whether to include current element in subset or not
// First, I will print subsets including current element
// Then, I will print subsets excluding current element
void printSubsets(string sub, string str,unordered_map <string, int> &ump) {
	// Base Condition
	if(str == "") {
		if(ump[sub] != 1) {
			ump[sub] = 1;
			cout<<'"'<<sub<<'"'<<endl;
		}
		return;
	}

	// Hypothesis and Induction
	char ele = str[0];
	str.erase(str.begin());

	// Including ele
	printSubsets(sub+ele, str, ump);

	// Excluding ele
	printSubsets(sub, str, ump);
}

int main() {
	stayTORO();

	unordered_map <string, int> ump;

	string str = "aab";

	printSubsets("", str, ump);

	return 0;
}

// OUT 
// "aab"
// "aa"
// "ab"
// "a"
// "b"
// ""