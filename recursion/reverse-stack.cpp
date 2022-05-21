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
// insertFirst(s, ele) will insert ele at first position of the stack
// Logic:
// If stack is empty, we will push ele into the stack
// Else, we will remove the top element and store it in lastEle
// Then, we will call insertFirst(s, ele) which will insert ele at first position
// Now, we know that lastEle will at last position, so we will push it into the stack
void insertFirst(stack <int> &s, int ele) {
    // Base Condition
    if(s.size() == 0) {
        s.push(ele);
        return;
    }

    // Hypothesis
    int lastEle = s.top();
    s.pop();
    insertFirst(s, ele);

    // Induction Step
    s.push(lastEle);
}

// Hypothesis:
// reverseStack(s) will reverse the stack s
// Logic:
// If stack size is 1, its reversal will be same, so we will return
// Else we will remove the top element of stack and store it in firstEle
// Now, we will call reverseStack(s) on remaining stack
// Then, we will insert firstEle in first position of the stack
void reverseStack(stack <int> &s) {
    // Base Condition
    if(s.size() == 1) return;

    // Hypothesis
    int firstEle = s.top();
    s.pop();
    reverseStack(s);

    // Induction Step
    insertFirst(s, firstEle);
}

int main() {
	stayTORO();

	int n;
	cin>>n;

	int ele;
	stack <int> s, sc; // s is main stack, sc is stack copy
	for(int i=0; i<n; i++) {
		cin>>ele;
		s.push(ele);
        sc.push(ele);
	}

    cout<<"Initial Stack:"<<endl;
	for(int i=0; i<n; i++) {
		ele = sc.top();
		cout<<ele<<" ";
		sc.pop();
	}

	reverseStack(s);

    cout<<"\nReversed Stack:"<<endl;
	for(int i=0; i<n; i++) {
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
// Initial Stack:
// 9 8 7 6 5 4 3 2 1 
// Reversed Stack:
// 1 2 3 4 5 6 7 8 9 