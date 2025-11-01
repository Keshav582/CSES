#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second<b.second) return true;
    if(a.second>b.second) return false;
    if(a.first>=b.first) return true;
    return false;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    bool allSame = true;
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        if(i>0 && v[i]!=v[i-1]) allSame = false;
    }
    if(allSame) {
        cout << 1 << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    int ans = 1;
    int lastPickEnd = v[0].second;
    for(int i=1;i<n;i++) {
        if(v[i].first>=lastPickEnd) {
            ans++;
            lastPickEnd = v[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}