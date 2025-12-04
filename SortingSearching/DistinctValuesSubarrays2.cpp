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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = 0;
    int r = 0;
    set<int> runningSet;
    map<int, int> mp;
    for(int i=0;i<n;i++) {
        // cout << "i: " << i << '\n';
        while(r<n) {
            if(runningSet.size()<k || (runningSet.size()==k && runningSet.count(v[r]))) {
                runningSet.insert(v[r]);
                mp[v[r]]++;
                r++;
            } else {
                break;
            }
        }
        // cout << "r: " << r << '\n';
        ans+=(r-i);
        mp[v[i]]--;
        if(mp[v[i]]==0) runningSet.erase(v[i]);
    }
    cout << ans << '\n';
    return 0;
}