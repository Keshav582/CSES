#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> arrivals(n), departures(n);
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        arrivals[i] = a, departures[i] = b;
    }
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    int arrivalPtr = 0, departurePtr = 0;
    int ans = 0, current = 0;
    while(arrivalPtr<n) {
        if(arrivals[arrivalPtr]<departures[departurePtr]) {
            current++;
            arrivalPtr++;
        } else {
            current--;
            departurePtr++;
        }
        ans = max(ans, current);
    }
    cout << ans << '\n';
    return 0;
}