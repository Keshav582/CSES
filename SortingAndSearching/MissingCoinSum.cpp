#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int x = 1;
    for(int i=0;i<n;i++) {
        if(v[i]>x) {
            break;
        }
        x+=v[i];
    }
    cout << x << '\n';
    return 0;
}