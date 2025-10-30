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
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            set<int> nums;
            for(int k=0;k<=2*n;k++) nums.insert(k);
            for(int k=0;k<i;k++) nums.erase(v[k][j]);
            for(int k=0;k<j;k++) nums.erase(v[i][k]);
            v[i][j] = *nums.begin();
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}