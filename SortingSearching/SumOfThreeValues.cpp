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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    bool solutionFound = false;
    for(int i=0;!solutionFound && i<n;i++) {
        for(int j=i+1;!solutionFound && j<n;j++) {
            int lo = j+1;
            int hi = n-1;
            int remSum = x-(v[i].first+v[j].first);
            while(lo<=hi) {
                int mid = (lo+hi)/2;
                if(v[mid].first==remSum) {
                    solutionFound = true;
                    cout << v[i].second << ' ' << v[j].second << ' ' << v[mid].second << '\n';
                    break;
                } else if(v[mid].first<remSum) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
    }
    if(!solutionFound) cout << "IMPOSSIBLE\n" << '\n';
    return 0;
}