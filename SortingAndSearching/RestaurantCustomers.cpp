#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);
    for (int i = 0; i < n; i++) cin >> arrival[i] >> departure[i];
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int ans = 0;
    int curr = 0;
    int arrivalPtr = 0, depPtr = 0;
    while (arrivalPtr < n) {
        if (arrival[arrivalPtr] < departure[depPtr]) {
            curr++;
            arrivalPtr++;
        } else {
            curr--;
            depPtr++;
        }
        ans = max(ans, curr);
    }
    cout << ans << '\n';
    return 0;
}