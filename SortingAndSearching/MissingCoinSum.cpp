// Taken help from: https://discuss.codechef.com/t/cses-missing-coin-sum/84039
#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int currSum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (currSum + 1 < v[i]) {
            break;
        }
        currSum += v[i];
    }
    cout << currSum + 1 << '\n';
    return 0;
}