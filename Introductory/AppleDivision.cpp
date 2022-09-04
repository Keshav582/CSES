#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long ans = INT64_MAX;
    for (int i = 0; i < (1 << n); i++) {
        long long sumA = 0, sumB = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sumA += v[j];
            } else {
                sumB += v[j];
            }
        }
        ans = min(ans, abs(sumA - sumB));
    }
    cout << ans << '\n';
    return 0;
}