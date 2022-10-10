#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.empty() || !s.count(x - 1)) {
            ans++;
        }
        s.insert(x);
    }
    cout << ans << '\n';
    return 0;
}