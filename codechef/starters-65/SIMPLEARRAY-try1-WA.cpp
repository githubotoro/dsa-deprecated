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

int n, k;

int getGoods(vector<int> ip, vector<int> op) {
	if(ip.size() == 0) {
		if(op.size() == 0 || op.size() == 1) return 1;

		for(int i=0; i<op.size()-1; i++) {
			if((op[i] + op[i+1]) % k == 0) return 0;
		}

		return 1;
	}

	int num = ip[ip.size()-1];
	ip.pop_back();

	vector<int> op1 = op;
	op1.push_back(num);

	vector<int> op2 = op;

	return getGoods(ip, op1) + getGoods(ip, op2);
}

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
		cin>>n>>k;

		vector<int> arr(n, 0);
		vector<int> sub;

		for(int i=0; i<n; i++) {
			cin>>arr[i];
		}

		cout<<getGoods(arr, sub)<<"\n";
	}

	return 0;
}

// == IN ==
// 4
// 4 10
// 1 2 3 4
// 3 1
// 1 2 3
// 5 5
// 7 -5 5 -2 5
// 4 9
// -9 -9 8 0

// == OUT ==
// No
// Yes
// Yes
// No
