#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    int ansx = -1, ansy = -1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (ansx == -1 && mp.find(x - a) != mp.end()) {
            ansx = mp[x - a];
            ansy = i;
        }
        mp[a] = i;
    }
    if (ansx == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ansx+1 << ' ' << ansy+1 << '\n';
    }
    return 0;
}