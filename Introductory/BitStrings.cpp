#include <bits/stdc++.h>

using namespace std;

long long power(long long base, long long exp) {
    long long mod = 1000000007;
    long long res = 1;
    while (exp) {
        if (exp % 2) {
            res *= base;
            res %= mod;
        }
        base *= base;
        base %= mod;
        exp /= 2;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    cout << power(2LL, n) << '\n';
    return 0;
}