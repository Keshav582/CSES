#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int currSum = 0, ans = INT_MIN;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        currSum+=v[i];
        ans = max(ans, currSum);
        if(currSum<0) currSum = 0;
    }
    cout << ans << '\n';
    return 0;
}