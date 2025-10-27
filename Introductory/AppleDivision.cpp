#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INT_MAX;
    for(int i=0;i<(1<<n);i++) {
        int sum1 = 0;
        int sum2 = 0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                sum1+=v[j];
            } else {
                sum2+=v[j];
            }
        }
        ans = min(ans, abs(sum1-sum2));
    }
    cout << ans << '\n';
    return 0;
}