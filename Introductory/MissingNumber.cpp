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
    int n; cin >> n;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<n;i++) {
        int x; cin >> x;
        s.erase(x);
    }
    cout << *s.begin() << '\n';
    return 0;
}