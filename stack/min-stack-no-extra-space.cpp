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

// Main stack
stack <int> s;

// Tracking minimum element
int minEle = -1;

// If passed element is less than minimum element,
// then push (2 * element - minimum element) in the stack
// and update the minimum element
// else simply push element in the stack
void push(int ele) {
    if(s.size() == 0) {
        s.push(ele);
        minEle = ele;
    } else {
        if(ele < minEle) {
            s.push(2 * ele - minEle);
            minEle = ele;
        } else s.push(ele);
    }
}

// If top of stack is less than minimum element,
// then minimum element will be: 2 * minimum element - top of stack
void pop() {
    if(s.size() != 0) {
        if(s.top() < minEle)
            minEle = 2 * minEle - s.top();
        
        s.pop();
    }
}

// If stack is empty, then minimum is -1
// else there would be another value in minimum element
int getMin() {
    return minEle;
}

int main() {
	stayTORO();

	push(5);
    push(15);
    push(10);
    push(0);

    cout<<"Min is: "<<getMin();

    pop();

    s.push(10);

    cout<<"\nMin is: "<<getMin();

	return 0;
}

// OUT
// Min is: 0
// Min is: 5