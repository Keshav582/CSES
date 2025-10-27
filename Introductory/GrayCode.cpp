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
    vector<string> v = {"0", "1"};
    for(int i=2;i<=n;i++) {
        int sz = v.size();
        for(int j=sz-1;j>=0;j--) {
            v.push_back(v[j]);
        }
        for(int j=0;j<sz;j++) {
            v[j] = "0"+v[j];
        }
        for(int j=sz;j<v.size();j++) {
            v[j] = "1"+v[j];
        }
    }
    for(auto itr:v) cout << itr << '\n';
    return 0;
}