#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int power(int a, int b) {
    if(b==0) return 1;
    if(b%2==0) {
        return (power(a, b/2)*power(a, b/2))%mod;
    } else {
        return (a*power(a, b-1))%mod;
    }
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << power(2, n) << '\n';
    return 0;
}