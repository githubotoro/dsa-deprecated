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

// Problem is a variation of The Dutch National Flag Problem
// The flag of the Netherlands consists of three colors: white, red, and blue.
// The task is to arrange balls of white, red, and blue such that balls of the same color
// are placed together in the order of white, red and blue.

// Time Complexity: O(n)
// Space Complexity: O(1)
void sort012(int arr[], int n) {
	int low = 0;
	int mid = 0;
	int high = n-1;

	while(mid <= high) {
		switch(arr[mid]) {
			case 0:
				swap(arr[low++], arr[mid++]);
				break;
			
			case 1:
				mid++;
				break;
			
			case 2:
				swap(arr[mid], arr[high--]);
				break;
		}
	}
}

int main() {
	stayTORO();
  
	int n;
	cin>>n;

	int arr[n];

	for(auto &ele: arr) cin>>ele;

	sort012(arr, n);

	for(auto ele: arr) cout<<ele<<" ";
   
	return 0;
}

// IN
// 6
// 2 0 2 1 1 0
// OUT
// 0 0 1 1 2 2 