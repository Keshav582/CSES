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
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = 0;
    int ans = 0;
    for(int i=0;i<n;i++) {
        int newLo = lo+v[i];
        int newHi = hi+v[i];
        if(newLo>hi+1) {
            ans = hi+1;
            break;
        }
        hi = newHi;
    }
    if(ans!=0) {
        cout << ans << '\n';
    } else {
        cout << hi+1 << '\n';
    }
    return 0;
}