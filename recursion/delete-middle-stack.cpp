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
// deleteEle(s, n) will delete element at position n
// Logic:
// If n is 1, than it is the element to be deleted, we will remove it from the stack
// Else we will remove the top element of stack and store it in lastEle
// then we will call deleteEle(s, n-1) which will delete the element at (n-1)th position
// now we know that, lastEle will come at last, so we will push it back into the stack 
void deleteEle(stack <int> &s, int n) {
	// Base Condition
	if(n == 1) {
		s.pop();
		return;
	}

	// Hypothesis
	int lastEle = s.top();
	s.pop();
	deleteEle(s, n-1);

	// Induction Step
	s.push(lastEle);
}

int main() {
	stayTORO();

	int n;
	cin>>n;

	int ele;
	stack <int> s;
	for(int i=0; i<n; i++) {
		cin>>ele;
		s.push(ele);
	}

	int middleEle;
	if(s.size() % 2 == 0) middleEle = s.size()/2;
	else middleEle = (s.size()/2) + 1;

	deleteEle(s, middleEle);

	for(int i=0; i<n-1; i++) {
		ele = s.top();
		cout<<ele<<" ";
		s.pop();
	}

	return 0;
}

// IN
// 9
// 1 2 3 4 5 6 7 8 9
// OUT
// 9 8 7 6 4 3 2 1 