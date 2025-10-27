#include <bits/stdc++.h>
#define int long long
using namespace std;
void toh(int n, int left, int middle, int right) {
    if(n==1) {
        cout << left << " " << right << '\n';
        return;
    }
    toh(n-1, left, right, middle);
    cout << left << " " << right << '\n';
    toh(n-1, middle, left, right);
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << pow(2, n)-1 << '\n';
    toh(n, 1, 2, 3);
    return 0;
}