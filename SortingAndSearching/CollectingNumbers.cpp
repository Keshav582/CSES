#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    set<int> gotIt;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(!gotIt.count(v[i]-1)) {
            ans++;
        }
        gotIt.insert(v[i]);
    }
    cout << ans << '\n';
    return 0;
}