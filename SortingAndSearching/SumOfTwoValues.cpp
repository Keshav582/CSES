#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<pair<int, int> > v(n);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v[i] = make_pair(x, i);
    }
    sort(v.begin(), v.end());
    bool foundAnAnswer = false;
    for(int i=0;i+1<n;i++) {
        int lo = i+1, hi = n-1, ans = -1;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(v[mid].first+v[i].first==target) {
                ans = mid;
                break;
            } else if(v[mid].first+v[i].first<target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        if(ans!=-1) {
            foundAnAnswer = true;
            cout << v[i].second+1 << ' ' << v[ans].second+1 << '\n';
            break;
        }
    }
    if(!foundAnAnswer) {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}