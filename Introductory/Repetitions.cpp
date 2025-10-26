#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int ans = 1;
    for(int i=0;i<s.size();) {
        int j = i+1;
        while(j<s.size() && s[j]==s[i]) j++;
        ans = max(ans, j-i);
        i = j;
    }
    cout << ans << '\n';
    return 0;
}