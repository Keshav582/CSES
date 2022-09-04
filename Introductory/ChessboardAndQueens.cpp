#include <bits/stdc++.h>

using namespace std;

bool canPlace(int row, int col, vector<string> &board) {
    if (board[row][col] != '*') {
        for (int c = 0; c < 8; c++) {
            if (board[row][c] == '#') return false;
        }
        for (int r = 0; r < 8; r++) {
            if (board[r][col] == '#') return false;
        }
        for (int sub = 1; row - sub >= 0 && col - sub >= 0; sub++) {
            if (board[row - sub][col - sub] == '#') return false;
        }
        for (int sub = 1, add = 1; row - sub >= 0 && col + add < 8; sub++, add++) {
            if (board[row - sub][col + add] == '#') return false;
        }
        for (int sub = 1, add = 1; row + add < 8 && col - sub >= 0; sub++, add++) {
            if (board[row + add][col - sub] == '#') return false;
        }
        for (int add = 1; row + add < 8 && col + add < 8; add++) {
            if (board[row + add][col + add] == '#') return false;
        }
        return true;
    }
    return false;
}

int solve(int col, vector<string> &board) {
    if (col == 8) return 1;
    int ans = 0;
    for (int row = 0; row < 8; row++) {
        if (canPlace(row, col, board)) {
            board[row][col] = '#';
            ans += solve(col + 1, board);
            board[row][col] = '.';
        }
    }
    return ans;
}

int main() {
    vector<string> initialConfig(8);
    for (int i = 0; i < 8; i++) {
        cin >> initialConfig[i];
    }
    cout << solve(0, initialConfig) << '\n';
    return 0;
}