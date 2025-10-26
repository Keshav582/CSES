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
    for(int i=1;i<=n;i++) {
        if(i==1) {
            cout << 0 << '\n';
        } else if(i==2) {
            cout << 6 << '\n';
        } else if(i==3) {
            cout << 28 << '\n';
        } else if(i==4) {
            cout << 96 << '\n';
        } else if(i==5) {
            cout << 252 << '\n';
        } else {
            int totalPossibleWays = (i*i)*((i*i)-1);
            int notPossible = 2*4+3*8+4*(i-4)*4+4*4+4*(i-4)*6+8*(i-4)*(i-4);
            cout << (totalPossibleWays-notPossible)/2 << '\n';
        }
    }
    return 0;
}