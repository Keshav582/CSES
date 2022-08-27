#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1, false);
    for (int i = 0; i + 1 < n; i++) {
        int x;
        cin >> x;
        v[x] = true;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}