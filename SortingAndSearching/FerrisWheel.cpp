#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ans = 0;
    int lo = 0, hi = n-1;
    while(lo<=hi) {
        ans++;
        if(lo==hi) {
            break;
        } else {
            if(p[lo]+p[hi]<=x) {
                lo++, hi--;
            } else {
                hi--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}