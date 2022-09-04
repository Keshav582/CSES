#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (ms.empty()) {
            cout << -1 << '\n';
        } else {
            auto itr = ms.upper_bound(x);
            if (itr != ms.begin()) itr--;
            if (*itr <= x) {
                cout << *itr << '\n';
                ms.erase(itr);
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}