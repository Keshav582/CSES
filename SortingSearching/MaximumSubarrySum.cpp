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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INT_MIN;
    int curr = 0;
    for(int i=0;i<n;i++) {
        curr+=v[i];
        ans = max(ans, curr);
        if(curr<0) curr = 0;
    }
    cout << ans << '\n';
    return 0;
}