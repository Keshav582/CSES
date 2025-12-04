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
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v;
    for(int i=1;i<=n;i++) {
        int num; cin >> num;
        v.push_back({num, i});
    }
    sort(v.begin(), v.end());
    bool ansFound = false;
    for(int i=0;!ansFound && i+3<n;i++) {
        for(int j=i+1;!ansFound && j+2<n;j++) {
            int remSum = x-v[i].first-v[j].first;
            int lo = j+1;
            int hi = n-1;
            if(2*v[lo].first>remSum || 2*v[hi].first<remSum) continue;
            while(lo<hi) {
                if(v[lo].first+v[hi].first==remSum) {
                    ansFound = true;
                    cout << v[i].second << ' ' << v[j].second << ' ' << v[lo].second << ' ' << v[hi].second << '\n';
                    break;
                } else if(v[lo].first+v[hi].first<remSum) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
    }
    if(!ansFound) {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}