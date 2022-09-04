#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> wishList(n);
    for (int i = 0; i < n; i++) cin >> wishList[i];
    vector<int> availableApartments(m);
    for (int i = 0; i < m; i++) cin >> availableApartments[i];
    sort(wishList.begin(), wishList.end());
    sort(availableApartments.begin(), availableApartments.end());
    int ans = 0;
    int wishListIdx = 0, availableApartmentsIdx = 0;
    while (wishListIdx < n && availableApartmentsIdx < m) {
        if (wishList[wishListIdx] >= availableApartments[availableApartmentsIdx] - k &&
            wishList[wishListIdx] <= availableApartments[availableApartmentsIdx] + k) {
            wishListIdx++, availableApartmentsIdx++;
            ans++;
        } else if (wishList[wishListIdx] < availableApartments[availableApartmentsIdx] - k) {
            wishListIdx++;
        } else {
            availableApartmentsIdx++;
        }
    }
    cout << ans << '\n';
    return 0;
}