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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int aIdx = 0;
    int bIdx = 0;
    int ans = 0;
    int curr = 0;
    while(aIdx<n) {
        if(a[aIdx]<=b[bIdx]) {
            curr++;
            ans = max(ans, curr);
            aIdx++;
        } else {
            curr--;
            bIdx++;
        }
    }
    cout << ans << '\n';
    return 0;
}