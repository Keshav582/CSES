#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int numberOfDigits = 1;
        while (9LL * numberOfDigits * pow(10LL, numberOfDigits - 1LL) < k) {
            k -= (9LL * numberOfDigits * pow(10LL, numberOfDigits - 1LL));
            numberOfDigits++;
        }
        int currentNumber =
                pow(10LL, numberOfDigits - 1LL) + (k % numberOfDigits == 0LL ? (k / numberOfDigits) - 1LL : k / numberOfDigits);
        k %= numberOfDigits;
        if (k == 0) k = numberOfDigits;
        k--;
        cout << to_string(currentNumber)[k] << '\n';
    }
    return 0;
}