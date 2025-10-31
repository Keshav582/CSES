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
    int n, m;
    cin >> n >> m;
    vector<string> orig(n), ans(n);
    for(int i=0;i<n;i++) {
        cin >> orig[i];
        ans[i] = orig[i];
    }
    char options[] = {'A', 'B', 'C', 'D'};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(auto itr:options) {
                if(itr!=ans[i][j] && (i-1<0 || ans[i-1][j]!=itr) && (j-1<0 || ans[i][j-1]!=itr)) {
                    ans[i][j] = itr;
                    break;
                }
            }
        }
    }
    for(auto itr:ans) cout << itr << '\n';
    return 0;
}