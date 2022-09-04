#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0, middle;
    if (n % 2 == 0) {
        middle = (v[n / 2] + v[(n / 2) - 1]) / 2;
    } else {
        middle = v[n / 2];
    }
    for (int i = 0; i < n; i++) {
        ans += abs(v[i] - middle);
    }
    cout << ans << '\n';
    return 0;
}