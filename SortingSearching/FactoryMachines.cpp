#include <bits/stdc++.h>
#define int long long
using namespace std;

// Custom operator<< for __int128_t
std::ostream& operator<<(std::ostream& os, __int128_t val) {
    if (val == 0) {
        return os << "0";
    }
    std::string s;
    bool negative = false;
    if (val < 0) {
        negative = true;
        val = -val; // Make positive for digit extraction
    }
    while (val > 0) {
        s += (val % 10) + '0';
        val /= 10;
    }
    if (negative) {
        s += '-';
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    __int128_t lo = 0, hi = (__int128_t)1e19;
    __int128_t ans = hi;
    while(lo<=hi) {
        __int128_t mid = hi+(lo-hi)/2;
        __int128_t x = 0;
        for(auto itr:v) {
            x+=(mid/itr);
        }
        if(x>=t) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}