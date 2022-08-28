#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n' << 1 << '\n';
    } else {
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        for (int i = 2; i <= n; i++) {
            vector<string> newVector;
            for (auto itr:v) {
                newVector.push_back("0" + itr);
            }
            for (auto itr = v.rbegin(); itr != v.rend(); itr++) {
                newVector.push_back("1" + (*itr));
            }
            v = newVector;
        }
        for (auto itr:v) {
            cout << itr << '\n';
        }
    }
    return 0;
}