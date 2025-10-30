#include <bits/stdc++.h>
#define int long long
using namespace std;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    queue<vector<int>> q;
    q.push({0, 0, 0});
    grid[0][0] = 0;
    while(!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        for(int i=0;i<8;i++) {
            if(v[0]+dx[i]>=0 && v[0]+dx[i]<n && v[1]+dy[i]>=0 && v[1]+dy[i]<n && grid[v[0]+dx[i]][v[1]+dy[i]]==-1) {
                grid[v[0]+dx[i]][v[1]+dy[i]] = v[2]+1;
                q.push({v[0]+dx[i], v[1]+dy[i], v[2]+1});
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}