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
// printBalancedParenthesis will generate all balanced parenthesis
// for given open and close brackets
// Logic:
// If open and close are 0, then ans will be the answer
// Else we have the option to put either open or close bracket
// We can only close a bracket, if it has been opened, else not
// If open >= close, we have only 1 choice, put the open bracket
// If open < close, we have 2 choices, put either open or close bracket 
// Note: We can only put a bracket, if required bracket is available in either open or close
void printBalancedParenthesis(string ans, int open, int close) {
	// Base Condition
	if(open == 0 && close == 0) {
		cout<<ans<<endl;
		return;
	}

	// Hypothesis and Induction
	if(open >= close && open>0) {
		printBalancedParenthesis(ans+"(", open-1, close);
	} else {
		if(open>0) printBalancedParenthesis(ans+"(", open-1, close);
		
		if(close>0) printBalancedParenthesis(ans+")", open, close-1);
	}
}

int main() {
	stayTORO();

	int n=3;

	printBalancedParenthesis("", n, n);

	return 0;
}

// OUT 
// ((()))
// (()())
// (())()
// ()(())
// ()()()