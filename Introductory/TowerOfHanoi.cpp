#include <bits/stdc++.h>

using namespace std;

void toh(int disks, int from, int aux, int to) {
    if (disks == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    toh(disks - 1, from, to, aux);
    cout << from << " " << to << '\n';
    toh(disks - 1, aux, from, to);
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    toh(n, 1, 2, 3);
    return 0;
}