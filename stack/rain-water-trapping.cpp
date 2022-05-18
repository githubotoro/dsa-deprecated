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

int main() {
	stayTORO();

    int n;
    cin>>n;

    int arr[n];

    // Taking input array
    for(auto &ele: arr) cin>>ele;

    // Declaring arrays for max left, max right and water
    int maxL[n], maxR[n], water[n];

    // We will initialize first element of max left
    // and last element of max right
    maxL[0] = arr[0];
    maxR[n-1] = arr[n-1];
    
    // Max Left traverses from beginning
    // Max Right traverses from ending
    for(int i=1, j=n-2; i<n, j>=0; i++, j--) {
        maxL[i] = max(arr[i], maxL[i-1]);
        maxR[j] = max(arr[j], maxR[j+1]);
    }

    int totalWater = 0;

    // Formula:
    // water in ith building = minimum( maximum of left, maximum of right) - height of building
    for(int i=0; i<n; i++) {
        water[i] = min(maxL[i], maxR[i]) - arr[i];
        totalWater += water[i];
    }

    cout<<totalWater;

	return 0;
}

// IN
// 6
// 3 0 0 2 0 4
// OUT
// 10