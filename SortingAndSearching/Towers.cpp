#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<int, int> topFreq;
    for(int i=0;i<n;i++) {
        auto itr = topFreq.upper_bound(v[i]);
        if(itr!=topFreq.end()) {
            topFreq[itr->first]--;
            if(topFreq[itr->first]==0) topFreq.erase(itr);
        }
        topFreq[v[i]]++;
    }
    int ans = 0;
    for(auto itr:topFreq) ans+=itr.second;
    cout << ans << '\n';
    return 0;
}