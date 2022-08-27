#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = (n * (n + 1LL)) / 2LL;
    if (sum % 2 == 0) {
        long long target = sum / 2LL;
        set<long long> set1, set2;
        for (long long i = 1; i <= n; i++) {
            set1.insert(i);
        }
        while (target) {
            auto itr = set1.lower_bound(target);
            if (itr == set1.end() || *itr > target) itr--;
            target -= (*itr);
            set2.insert(*itr);
            set1.erase(itr);
        }
        cout << "YES\n";
        cout << set1.size() << '\n';
        for (auto itr:set1) cout << itr << ' ';
        cout << '\n';
        cout << set2.size() << '\n';
        for (auto itr:set2) cout << itr << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}