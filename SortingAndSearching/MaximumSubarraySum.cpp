#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = INT_MIN;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += v[i];
        ans = max(ans, curr);
        curr = max(curr, 0LL);
    }
    cout << ans << '\n';
    return 0;
}