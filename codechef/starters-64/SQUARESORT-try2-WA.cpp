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

pair<long long int, long long int> zeroPair = {0, 0};

map<pair< pair<long long int, long long int> , long long int>, pair<long long int, long long int>> mp;

pair<long long int, long long int> getSquareOperations(long long int n, long long int n_1) {
	long long int ops = 0;
	long long int initial_n = n;

	while(n_1 > n) {
		n = pow(n, 2);
		ops++;
	}

	mp.insert({{{initial_n, n_1}, 2}, {n, ops}});

	return {n, ops};
}

pair<long long int, long long int> getRootOperations(long long int n, long long int n_1) {
	long long int ops = 0;
	long long int initial_n_1 = n_1;
	long long int prev_n_1 = n_1;

	while(n_1 > n) {
		n_1 = floor(pow(n_1, 0.5));
		ops++;

		if(n_1 == 1) {
			n_1 = 1;
			break;
		}
	}

	mp.insert({{{n, initial_n_1}, -2}, {n_1, ops}});

	return {n_1, ops};
}

long long int squareSort(vector<long long int> &arr, long long int n) {
	// base condition
	if(n==0 || n==1) return 0;

	// cout<<"Arr: ";
	// for(int i=0; i<4; i++) {
	// 	cout<<arr[i]<<" ";
	// } cout<<endl;

	// hypothesis and induction
	if(arr[n-2] > arr[n-1]) {
		// cout<<"arr[n-2] = "<<arr[n-2]<<" and arr[n-1] = "<<arr[n-1]<<endl;
		long long int ans1 = INT_MAX;
		long long int ans2 = INT_MAX;

		if(pow(arr[n-1], 2) > arr[n-1]) {
			if(mp[{{arr[n-1], arr[n-2]}, 2}] == zeroPair) {
				pair<long long int, long long int> ans = getSquareOperations(arr[n-1], arr[n-2]);

				vector<long long int> newArr = arr;

				newArr[n-1] = ans.first;
				ans1 = ans.second + squareSort(newArr, n-1);
			} else {
				pair<long long int, long long int> ans = mp[{{arr[n-1], arr[n-2]}, 2}];

				vector<long long int> newArr = arr;

				newArr[n-1] = ans.first;
				ans1 = ans.second + squareSort(newArr, n-1);
			}
		}

		if(floor(pow(arr[n-2], 0.5)) < arr[n-2]) {
			if(mp[{{arr[n-1], arr[n-2]}, -2}] == zeroPair) {
				pair<long long int, long long int> ans = getRootOperations(arr[n-1], arr[n-2]);

				vector<long long int> newArr = arr;
				newArr[n-2] = ans.first;

				// cout<<"operations required = "<<ans.second<<endl;

				ans2 = ans.second + squareSort(newArr, n-1);
			} else {
				pair<long long int, long long int> ans = mp[{{arr[n-1], arr[n-2]}, -2}];

				vector<long long int> newArr = arr;
				newArr[n-2] = ans.first;

				// cout<<"operations required = "<<ans.second<<endl;
				
				ans2 = ans.second + squareSort(newArr, n-1);
			}
		}

		return min(ans1, ans2);
	} else {
		return squareSort(arr, n-1);
	}
}

int main() {
	stayTORO();

	long long int t;
	cin>>t;

	while(t--) {
		long long int n;
        cin>>n;

		vector<long long int> arr(n);

        for(long long int i=0; i<n; i++) {
            cin>>arr[i];
        }

		cout<<squareSort(arr, n)<<"\n";
	}

	return 0;
}

// == IN ==
// 3
// 4
// 1 3 9 9
// 4
// 1 9 3 9
// 3
// 4 2 1

// == OUT ==
// 0
// 1
// 3