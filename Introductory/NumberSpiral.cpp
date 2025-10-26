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
        int r, c;
        cin >> r >> c;
        if(r>=c) {
            if(r%2==0) {
                cout << (r*r)-c+1 << '\n';
            } else {
                cout << (r-1)*(r-1)+c << '\n';
            }
        } else {
            if(c%2==0) {
                cout << (c-1)*(c-1)+r << '\n';
            } else {
                cout << (c*c)-r+1 << '\n';
            }
        }
    }
    return 0;
}