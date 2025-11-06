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
    int x, n;
    cin >> x >> n;
    set<int> intervalStart, intervalEnd;
    intervalStart.insert(0);
    intervalEnd.insert(x);
    map<int, int> mp;
    mp[x]++;
    for(int i=0;i<n;i++) {
        int p; cin >> p;
        auto endItr = intervalEnd.lower_bound(p);
        auto startItr = intervalStart.lower_bound(p);
        startItr--;
        int diff = *endItr-*startItr;
        mp[diff]--;
        if(mp[diff]==0) mp.erase(diff);
        intervalEnd.insert(p);
        mp[p-*startItr]++;
        intervalStart.insert(p);
        mp[*endItr-p]++;
        cout << (*mp.rbegin()).first << ' ';
    }
    cout << '\n';
    return 0;
}