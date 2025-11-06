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
    int n; cin >> n;
    map<int, int> mp;
    int currSum = 0;
    int ans = 0;
    mp[0] = 1;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        currSum+=x;
        currSum%=n;
        currSum+=n;
        ans+=mp[currSum%n];
        mp[currSum%n]++;
    }
    cout << ans << '\n';
    return 0;
}