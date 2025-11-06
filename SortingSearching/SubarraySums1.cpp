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
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    int currSum = 0;
    for(int i=0;i<n;i++) {
        int p; cin >> p;
        currSum+=p;
        ans+=mp[currSum-x];
        mp[currSum]++;
    }
    cout << ans << '\n';
    return 0;
}