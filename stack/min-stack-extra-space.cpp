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

// Supporting Stack
stack <int> ss;

// If element is minimum than currently stored element in supporting stack,
// then we will push in supporting stack
// If supporting stack is empty, then again we will push in supporting stack
void push(int ele) {
    s.push(ele);

    if(ss.size() == 0)
        ss.push(ele);
    else if(ss.top() >= ele)
        ss.push(ele);
}

// If top of supporting stack is same as top of main stack,
// then we will pop from both stacks
// else we will pop only from main stack
void pop() {
    if(s.size() !=0 && ss.size() != 0) {
        if(ss.top() == s.top()) ss.pop();
        s.pop();
    }
    
}

// If supporting stack is empty, then minimum is -1
// else top of supporting stack will be minimum element
int getMin() {
    if(ss.size() == 0) return -1;
    else return ss.top();
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