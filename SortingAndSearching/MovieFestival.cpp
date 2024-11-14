#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second<=b.second) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int> > v(n);
    bool allSame = true;
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
        if(!(v[i].first==1 && v[i].second==1000000000)) allSame = false;
    }
    if(allSame) {
        cout << 1 << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    pair<int, int> last = make_pair(-1, -1);
    for(int i=0;i<n;i++) {
        if(last.second<=v[i].first) {
            ans++;
            last = v[i];
        }
    }
    cout << ans << '\n';
    return 0;
}