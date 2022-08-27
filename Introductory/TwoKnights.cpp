#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << '\n';
        } else if (i == 2) {
            cout << 6 << '\n';
        } else if (i == 3) {
            cout << 28 << '\n';
        } else if (i == 4) {
            cout << 96 << '\n';
        } else if (i == 5) {
            cout << 252 << '\n';
        } else {
            long long total = ((i * i) - 1LL) * i * i;
            long long sub = 2LL * 4LL + 3LL * 8LL + (i - 4LL) * 4LL * 4LL + 16LL + (i - 4LL) * 4LL * 6LL + (i - 4LL) * (i - 4LL) * 8LL;
            cout << (total - sub) / 2 << '\n';
        }
    }
    return 0;
}