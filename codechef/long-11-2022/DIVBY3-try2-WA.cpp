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

int getAns(int even0, int even1, int odd0, int odd1, int n) {
    if(even1 == 0 && odd1 == 0) return 0;

    if(n<=2) return -1;

    if(even1+odd1 <= 2) return -1;

    if(abs(even1-odd1)%3 == 0) return 0;

    if((even1 + odd1)%2 == 0) return 1;

    if((even0 + odd0 + 1)%3 == 0) return 1;

    return -1;
}

int main() {
    stayTORO();

    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int even0=0;
        int even1=0;
        int odd1=0;
        int odd0=0;

        bool canbe2 = true;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '1') {
                if((i+1)%2==0) even1++;
                else odd1++;
            } else {
                if((i+1)%2==0) even0++;
                else odd0++;
            }
        }

        char prev=s[0];
        for(int i=1; i<s.length(); i++) {
            if(s[i] == prev) {
                canbe2 = false;
                break;
            }
            prev = s[i];
        }

        // if(s.length()<=2) {
        //     cout<<"-1\n";
        // } else if(canbe2 == false) {
        //     int ans = getAns(even0, even1, odd0, odd1, s.length());
        //     cout<<ans<<"\n";
        // } else {
        //     if((even1+odd1)%3 == 1) cout<<"2\n";
        //     else {
        //         int ans = getAns(even0, even1, odd0, odd1, s.length());
        //         cout<<ans<<"\n";
        //     }
        // }
        
        cout<<"0\n";
    }
}

// == IN ==
// 3
// 0000
// 111
// 11001

// == OUT ==
// 0
// -1
// 1