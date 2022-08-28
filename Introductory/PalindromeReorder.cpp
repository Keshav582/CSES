#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto itr:s) {
        mp[itr]++;
    }
    char oddChar;
    int oddCount = 0;
    for (auto itr:mp) {
        if (itr.second % 2) {
            oddChar = itr.first;
            oddCount++;
        }
    }
    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
    } else {
        string part1 = "";
        for (auto itr:mp) {
            if (itr.second % 2 == 0) {
                for (int i = 1; i <= itr.second / 2; i++) {
                    part1 += itr.first;
                }
            }
        }
        cout << part1;
        for (int i = 0; i < mp[oddChar]; i++) {
            cout << oddChar;
        }
        reverse(part1.begin(), part1.end());
        cout << part1 << '\n';
    }
    return 0;
}