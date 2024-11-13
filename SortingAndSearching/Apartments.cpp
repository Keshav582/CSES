#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> people(n), apartments(m);
    for(int i=0;i<n;i++) cin >> people[i];
    for(int i=0;i<m;i++) cin >> apartments[i];
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());
    int apartmentIdx = 0;
    int ans = 0;
    for(int i=0;i<n && apartmentIdx<m;i++) {
        while(apartmentIdx<m && apartments[apartmentIdx]+k<people[i]) apartmentIdx++;
        if(apartments[apartmentIdx]-k<=people[i] && people[i]<=apartments[apartmentIdx]+k) {
            ans++;
            apartmentIdx++;
        }
    }
    cout << ans << '\n';
    return 0;
}