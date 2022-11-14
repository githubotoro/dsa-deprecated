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

bool isDivisible(int evenOnes, int oddOnes) {
    if(abs(evenOnes-oddOnes)%3 == 0) {
        return true;
    } else {
        return false;
    }
}

map<string, int> mp;

int getAns(int even0, int even1, int odd0, int odd1, string ip, string op, int swaps) {
    if(even0 < 0 || even1 < 0 || odd0 < 0 || odd1 < 0) return INT_MAX;

    // base condition
    if(ip.length() == 0) {
        if(isDivisible(even1, odd1)) return swaps;
        else return INT_MAX;
    }

    string str = op + ip[0];
    ip.erase(ip.begin()+0);

    int ans1, ans2;

    if(str[str.length()-1] == '0' && op[str.length()-2] == '1') {
        if(str.length()%2 == 0) {
            int n = str.length();

            string swappedStr = str;
            swappedStr[n-2] = str[n-1];
            swappedStr[n-1] = str[n-2];

            // swap even0 with odd1
            ans1 = getAns(even0--, even1++, odd0++, odd1--, ip, swappedStr, swaps++);

            // don't swap
            ans2 = getAns(even0, even1, odd0, odd1, ip, str, swaps);
        } else {
            int n = str.length();

            string swappedStr = str;
            swappedStr[n-2] = str[n-1];
            swappedStr[n-1] = str[n-2];

            // swap even1 with odd0
            ans1 = getAns(even0++, even1--, odd0--, odd1++, ip, swappedStr, swaps++);

            // don't swap
            ans2 = getAns(even0, even1, odd0, odd1, ip, str, swaps);
        }
    } else if(str[str.length()-1] == '1' && op[str.length()-2] == '0') {
        if(str.length()%2 == 0) {
            int n = str.length();

            string swappedStr = str;
            swappedStr[n-2] = str[n-1];
            swappedStr[n-1] = str[n-2];

            // swap even1 with odd0
            ans1 = getAns(even0++, even1--, odd0--, odd1++, ip, swappedStr, swaps++);

            // don't swap
            ans2 = getAns(even0, even1, odd0, odd1, ip, str, swaps);
        } else {
            int n = str.length();
            
            string swappedStr = str;
            swappedStr[n-2] = str[n-1];
            swappedStr[n-1] = str[n-2];

            // swap even0 with odd1
            ans1 = getAns(even0--, even1++, odd0++, odd1--, ip, swappedStr, swaps++);

            // don't swap
            ans2 = getAns(even0, even1, odd0, odd1, ip, str, swaps);
        }
    } else {
        return getAns(even0, even1, odd0, odd1, ip, str, swaps);
    }

    return min(ans1, ans2);
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

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '1') {
                if((i+1)%2==0) even1++;
                else odd1++;
            } else {
                if((i+1)%2==0) even0++;
                else odd0++;
            }
        }

        int ans = getAns(even0, even1, odd0, odd1, s, "", 0);

        if(ans == INT_MAX) {
            cout<<"-1\n";
        } else {
            cout<<ans<<"\n";
        }

    }
}

// 0
// -1
// 1
// 1
// 1


// int main() {
// 	stayTORO();

// 	int t;
// 	cin>>t;

// 	while(t--) {
//         string s;
//         cin>>s;

//         int even0=0;
//         int even1=0;
//         int odd1=0;
//         int odd0=0;

//         for(int i=0; i<s.length(); i++) {
//             if(s[i] == '1') {
//                 if((i+1)%2==0) even1++;
//                 else odd1++;
//             } else {
//                 if((i+1)%2==0) even0++;
//                 else odd0++;
//             }
//         }

//         int flag=-1;
//         bool isDivisible=false;

//         if(abs(even1-odd1)%3 == 0) {
//             flag=0;
//             isDivisible=true;
//         } else {
//             int oeMaxSwaps, maxSwaps;

//             int count = 0;

//             int oeEven0 = even0;
//             int oeEven1 = even1;
//             int oeOdd0 = odd0;
//             int oeOdd1 = odd1;

//             oeMaxSwaps = min(oeOdd1, oeEven0);

//             while(oeOdd1>=1 && oeEven0>=1) {
//                 oeEven0--;
//                 oeEven1++;
//                 oeOdd1--;
//                 oeOdd0++;

//                 count++;

//                 if(abs(oeEven1-oeOdd1)%3 == 0) {
//                     flag=count;
//                     isDivisible=true;
//                     break;
//                 }

//                 if(count>=oeMaxSwaps) break;

//                 oeMaxSwaps = min(oeOdd1, oeEven0);
//             }



//             if(isDivisible==false) {
//                 maxSwaps = min(even1, odd0);

//                 count = 0;
//                 while(even1>=1 && odd0>=1) {
//                     odd0--;
//                     odd1++;
//                     even1--;
//                     even0++;

//                     count++;

//                     if(abs(even1-odd1)%3 == 0) {
//                         flag=count;
//                         isDivisible=true;
//                         break;
//                     }

//                     if(count>=maxSwaps) break;

//                     maxSwaps = min(even1, odd0);
//                 }
//             }
//         }

//         cout<<flag<<"\n";
// 	}

// 	return 0;
// }

// == IN ==
// 3
// 0000
// 111
// 11001

// == OUT ==
// 0
// -1
// 1