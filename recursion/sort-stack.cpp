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
// insertEle(s, ele) will insert ele at correct position in stack
// Logic: 
// If stack is empty, simply push the element
// If element is greater than top of stack, then push it
// If element is smaller than top of stack,
// then store the top element in lastEle and pop it
// now insert element in correct position by calling insertEle(s, ele)
// since, we know lastEle will always come at last, simply push it into the stack
void insertEle(stack <int> &s, int ele) {
	// Base Condition
	if(s.size() == 0) {
		s.push(ele);
		return;
	} else if(s.top() <= ele) {
		s.push(ele);
		return;
	}

	// Hypothesis
	int lastEle = s.top();
	s.pop();
	insertEle(s, ele);

	// Induction Step
	s.push(lastEle);
}

// Hypothesis:
// sortStack(s) will sort the stack
// Logic:
// I will pop the top element of stack and store it
// then sortStack(s) will sort the remaining stack
// then I will put popped element in correct position
void sortStack(stack <int> &s) {
	// Base Condition
	if(s.size() == 1) return;

	// Hypothesis
	int ele = s.top();
	s.pop();
	sortStack(s);

	// Induction Step
	insertEle(s, ele);
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

	sortStack(s);

	for(int i=0; i<n; i++) {
		ele = s.top();
		cout<<ele<<" ";
		s.pop();
	}

	return 0;
}

// IN
// 8
// 5 2 3 4 1 8 0 5
// OUT
// 8 5 5 4 3 2 1 0 