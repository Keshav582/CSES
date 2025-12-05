#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second<b.second) return true;
    if(a.second>b.second) return false;
    if(a.first<b.first) return true;
    return false;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // cout << "n and k done\n";
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), comp);
    // cout << "sorted\n";
    // for(auto itr:v) cout << itr.first << ' ' << itr.second << '\n';
    set<pair<int, int>> s;
    int ans = 1;
    s.insert({v[0].second, v[0].first});
    int x = 1;
    for(int i=1;i<n;i++) {
        auto itr = s.upper_bound({v[i].first, v[i].first});
        if(itr!=s.begin()) itr--;
        if((*itr).first<=v[i].first) {
            s.insert({v[i].second, (*itr).second});;
            s.erase(itr);
            ans++;
        } else if(x<k) {
            x++;
            s.insert({v[i].second, v[i].first});
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}