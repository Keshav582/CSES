#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        ms.insert(p);
    }
    int ans = 0;
    while (!ms.empty()) {
        ans++;
        auto itr = ms.begin();
        int p = *itr;
        ms.erase(itr);
        if (ms.empty()) break;
        itr = ms.upper_bound(x - p);
        if (itr != ms.begin()) itr--;
        if (*itr + p <= x) {
            ms.erase(itr);
        }
    }
    cout << ans << '\n';
    return 0;
}