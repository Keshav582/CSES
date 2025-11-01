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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = n-1;
    bool flag = false;
    while(lo<hi) {
        int sum = v[lo].first+v[hi].first;
        if(sum<x) {
            lo++;
        } else if(sum>x) {
            hi--;
        } else {
            flag = true;
            cout << v[lo].second << ' ' << v[hi].second << '\n';
            break;
        }
    }
    if(!flag) cout << "IMPOSSIBLE\n";
    return 0;
}