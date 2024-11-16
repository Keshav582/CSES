#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    set<int> curr;
    int ans = 0;
    int j = 0;
    for(int i=0;i<n;i++) {
        while(!curr.empty() && curr.count(v[i])) {
            curr.erase(v[j]);
            j++;
        }
        curr.insert(v[i]);
        ans = max(ans, (int)curr.size());
    }
    cout << ans << '\n';
    return 0;
}