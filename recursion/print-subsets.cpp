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
// printSubsets(str) will print all subsets of string str
// Logic:
// If string is empty, that means there is subset in sub
// Else, we have to decide whether to include current element in subset or not
// First, I will print subsets including current element
// Then, I will print subsets excluding current element
void printSubsets(string sub, string str) {
	// Base Condition
	if(str == "") {
		cout<<'"'<<sub<<'"'<<endl;
		return;
	}

	// Hypothesis and Induction
	char ele = str[0];
	str.erase(str.begin());

	// Including ele
	printSubsets(sub+ele, str);

	// Excluding ele
	printSubsets(sub, str);
}

int main() {
	stayTORO();

	string str = "abc";

	printSubsets("", str);

	return 0;
}

// OUT 
// "abc"
// "ab"
// "ac"
// "a"
// "bc"
// "b"
// "c"
// ""