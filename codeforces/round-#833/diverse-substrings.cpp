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

int n;
int ans;
map<string, int> track;

void diverseStrings(string s, string sub) {
    // base condition
    if(s.length() == 0) {
        cout<<"Substring: "<<sub<<endl;

        if(track[sub] != 0) {
            if(track[sub] == 1) {
                ans++;
                return;
            } else {
                return;
            }
        }

        if(sub.length() == 0) return;
        if(sub.length() == 1) {
            ans++;
            return;
        }

        map<char, int> mp;

        for(int i=0; i<sub.length(); i++) {
            mp[sub[i]]++;
        }

        int prev = mp.begin()->second;
        int flag = 1;

        for(auto ele : mp) {
            if(ele.second != prev) {
                flag = 0;
                break;
            }
        }

        if(flag==1) {
            track[sub] = 1;
            ans++;
        } else {
            track[sub] = -1;
        }

        return;
    }

    // induction
    string temp(1, s[0]);

    string s1 = sub + s[0];
	string s2 = temp;
	s.erase(s.begin()+0);

    // hypothesis
	diverseStrings(s, s1);
	diverseStrings(s, s2);
}

int main() {
	stayTORO();

	int t;
	cin>>t;

	while(t--) {
        track.clear();

        ans=0;

        cin>>n;

		string s;
        cin>>s;

        diverseStrings(s, "");

		cout<<ans<<"\n";
	}

	return 0;
}

// == IN ==
// 7
// 1
// 7
// 2
// 77
// 4
// 1010
// 5
// 01100
// 6
// 399996
// 5
// 23456
// 18
// 789987887987998798

// == OUT ==
// 1
// 2
// 10
// 12
// 10
// 15
// 106