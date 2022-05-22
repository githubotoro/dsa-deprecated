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
// towerOfHanoi(src, des, aux) will move all disks from src to dest using aux
// Logic:
// First I will ask towerOfHanoi to move n-1 disks to aux
// Then, I will place nth disk to dest
// Then, I will ask towerOfHanoi to move n-1 disks to dest
void towerOfHanoi(int src, int dest, int aux, int n) {
	// Base Condition
	if(n == 0) return;
	
	// Hypothesis
	towerOfHanoi(src, aux, dest, n-1);

	// Induction
	cout<<"Moving Disk "<<n<<" from Tower "<<src<<" to Tower "<<dest<<endl;

	// Hypothesis
	towerOfHanoi(aux, dest, src, n-1);
}

int main() {
	stayTORO();

	int n = 3;

	towerOfHanoi(1, 2, 3, n);

	return 0;
}

// OUT (Total steps should be 2^3 - 1 = 7, thus output is verified.)
// Moving Disk 1 from Tower 1 to Tower 2
// Moving Disk 2 from Tower 1 to Tower 3
// Moving Disk 1 from Tower 2 to Tower 3
// Moving Disk 3 from Tower 1 to Tower 2
// Moving Disk 1 from Tower 3 to Tower 1
// Moving Disk 2 from Tower 3 to Tower 2
// Moving Disk 1 from Tower 1 to Tower 2