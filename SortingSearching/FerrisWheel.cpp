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
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for(int i=0;i<n;i++) cin >> weights[i];
    sort(weights.begin(), weights.end());
    vector<bool> picked(n, false);
    int ans = 0;
    int idx = 0;
    for(int i=n-1;i>=0;i--) {
        if(!picked[i]) {
            ans++;
            if(weights[idx]+weights[i]<=x) {
                picked[idx] = true;
                idx++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}