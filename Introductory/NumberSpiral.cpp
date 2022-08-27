#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long row, col;
        cin >> row >> col;
        if (row <= col) {
            if (col % 2 == 0) {
                cout << (col - 1LL) * (col - 1LL) + row << '\n';
            } else {
                cout << col * col - row + 1LL << '\n';
            }
        } else {
            if (row % 2 == 0) {
                cout << row * row - col + 1LL << '\n';
            } else {
                cout << (row - 1LL) * (row - 1LL) + col << '\n';
            }
        }
    }
    return 0;
}