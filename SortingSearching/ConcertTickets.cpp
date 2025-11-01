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
    int n, m;
    cin >> n >> m;
    set<int> s;
    map<int, int> mp;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        s.insert(x);
        mp[x]++;
    }
    for(int i=0;i<m;i++) {
        int x; cin >> x;
        auto itr = s.upper_bound(x);
        if(itr==s.begin()) {
            cout << -1 << '\n';
        } else {
            itr--;
            if(*itr<=x) {
                int num = *itr;
                mp[num]--;
                cout << num << '\n';
                if(mp[num]==0) {
                    s.erase(num);
                }
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}