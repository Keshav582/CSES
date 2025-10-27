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
    int t; cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        if((a+b)%3==0 && 2*a>=b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}