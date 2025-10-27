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
    string s; cin >> s;
    set<string> perms;
    sort(s.begin(), s.end());
    do {
        perms.insert(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << perms.size() << '\n';
    for(auto itr:perms) cout << itr << '\n';
    return 0;
}