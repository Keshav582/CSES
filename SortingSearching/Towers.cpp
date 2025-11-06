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
    map<int, int> mp;
    for(int i=0;i<n;i++) {
        auto itr = mp.upper_bound(v[i]);
        if(itr==mp.end()) {
            mp[v[i]]++;
        } else {
            int x = (*itr).first;
            mp[x]--;
            if(mp[x]==0) mp.erase(x);
            mp[v[i]]++;
        }
    }
    int ans = 0;
    for(auto itr:mp) ans+=itr.second;
    cout << ans << '\n';
    return 0;
}