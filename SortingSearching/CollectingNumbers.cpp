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
    set<int> s;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(s.count(v[i]-1)) {
            
        } else {
            ans++;
        }
        s.insert(v[i]);
    }
    cout << ans << '\n';
    return 0;
}