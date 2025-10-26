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
    if(n==1) {
        cout << 1 << '\n';
    } else if(n==2 || n==3) {
        cout << "NO SOLUTION\n";
    } else {
        for(int i=2;i<=n;i+=2) cout << i << ' ';
        for(int i=1;i<=n;i+=2) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}