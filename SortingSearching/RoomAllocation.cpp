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
    vector<vector<int>> v(n, vector<int>(3));
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int roomsAvail = 1;
    for(int i=0;i<n;i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++) {
        int room = roomsAvail;;
        if(pq.empty() || pq.top().first>=v[i][0]) {
            roomsAvail++;
        } else {
            room = pq.top().second;
            pq.pop();
        }
        pq.push({v[i][1], room});
        ans[v[i][2]] = room;
    }
    cout << roomsAvail-1 << '\n';
    for(auto itr:ans) cout << itr << ' ';
    cout << '\n';
    return 0;
}