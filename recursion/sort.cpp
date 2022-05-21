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
// insertEle(arr, ele) will put ele at correct position in the sorted array arr
// Logic:
// If ele is greater than last element of arr, then it will be placed at last
// If ele is smaller than first element of arr, then it will be placed at first
// Else ele will be somewhere in the middle
// If ele is somewhere in the middle,
// then I will remove last element of arr and store it in lastEle
// then call insertEle(arr, ele) which will put ele at correct position
// then I already know that lastEle will be placed at last, so I will put it at last
void insertEle(vector <int> &arr, int ele) {
    // Base Condition
    if(arr.size() == 0) {
        arr.push_back(ele);
        return;
    } else if(arr[arr.size()-1] <= ele) {
        arr.insert(arr.end(), ele);
        return;
    } else if(arr[0] >= ele) {
        arr.insert(arr.begin(), ele);
        return;
    }

    // Hypothesis
    int lastEle = arr[arr.size()-1];
    arr.pop_back();
    insertEle(arr, ele);

    // Induction Step
    arr.push_back(lastEle);
}

// Hypothesis:
// sortArr(arr) will sort an array
// Logic:
// I will remove the last element from arr and store it
// then sortArr(arr) will sort the remaining arr
// then I will put last element in correct place
void sortArr(vector <int> &arr) {
	// Base Condition
    // If there is only 1 element in array, then it is already sorted
	if(arr.size() == 1) return;

	// Hypothesis
    int ele = arr[ arr.size()-1 ];
    arr.pop_back();
	sortArr(arr);

	// Induction Step
	insertEle(arr, ele);
}


int main() {
	stayTORO();

	int n;
    cin>>n;

    vector <int> arr(n);
    for(auto &ele: arr) cin>>ele;

	sortArr(arr);

    for(auto ele: arr) cout<<ele<<" ";

	return 0;
}

// IN
// 8
// 5 2 3 4 1 8 0 5
// OUT
// 0 1 2 3 4 5 5 8 