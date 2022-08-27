#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) j++;
        ans = max(ans, j - i);
        i = j;
    }
    cout << ans << '\n';
    return 0;
}