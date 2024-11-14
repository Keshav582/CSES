#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        mp[x]++;
    }
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        if (mp.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto itr = mp.upper_bound(x);
        if(itr!=mp.begin()) itr--;
        if((*itr).first<=x) {
            cout << (*itr).first << '\n';
            mp[(*itr).first]--;
            if(mp[(*itr).first]==0) mp.erase(itr);
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}