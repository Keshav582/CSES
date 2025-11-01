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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    sort(b.begin(), b.end());
    int idx = 0;
    int ans = 0;
    for(int i=0;i<n;i++) {
        while(idx<m && b[idx]<v[i]-k) {
            idx++;
        }
        if(idx<m && b[idx]>=v[i]-k && b[idx]<=v[i]+k) {
            ans++;
            idx++;
        }
    }
    cout << ans << '\n';
    return 0;
}