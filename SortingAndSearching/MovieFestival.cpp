#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1 && y == 1000000000) cnt++;
        v.push_back({x, y});
    }
    if (cnt == n) {
        cout << 1 << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second <= b.second; });
    int ans = 0;
    int currEnd = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= currEnd) {
            currEnd = v[i].second;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}