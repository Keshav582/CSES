#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

string s;
int vis[7][7];

bool isWallPartitioned(int x, int y) {
    if (x == 0 && y > 0 && y < 6 && vis[1][y] == 1 && vis[0][y + 1] == 0 && vis[0][y - 1] == 0)return true;
    if (x == 6 && y > 0 && y < 6 && vis[5][y] == 1 && vis[6][y + 1] == 0 && vis[6][y - 1] == 0)return true;
    if (y == 0 && x > 0 && x < 6 && vis[x][1] == 1 && vis[x + 1][0] == 0 && vis[x - 1][0] == 0)return true;
    if (y == 6 && x > 0 && x < 6 && vis[x][5] == 1 && vis[x + 1][6] == 0 && vis[x - 1][6] == 0)return true;
    else return false;
}

bool isLooped(int x, int y) {
    if (x == 0 || x == 6 || y == 0 || y == 6)return false;
    if (vis[x][y + 1] == 1 && vis[x][y - 1] == 1 && vis[x - 1][y] == 0 && vis[x + 1][y] == 0)return true;
    if (vis[x + 1][y] == 1 && vis[x - 1][y] == 1 && vis[x][y + 1] == 0 && vis[x][y - 1] == 0)return true;
    return false;
}


int solve(int x, int y, int i) {

    if (x == 6 && y == 0) {
        if (i == 48)return 1;
        return 0;
    }
    if (i == 48) {
        return 0;
    }
    if (isWallPartitioned(x, y))return 0;
    if (isLooped(x, y))return 0;
    if (s[i] == '?') {
        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};
        int k = 0;
        for (int j = 0; j < 4; j++) {
            int newX = x + r[j];
            int newY = y + c[j];
            if (newX < 0 || newX > 6)continue;
            if (newY < 0 || newY > 6)continue;
            if (vis[newX][newY] == 1)continue;
            vis[newX][newY] = 1;
            k += solve(newX, newY, i + 1);
            vis[newX][newY] = 0;
        }
        return k;
    }

    if (s[i] == 'L')y--;
    else if (s[i] == 'R')y++;
    else if (s[i] == 'D')x++;
    else if (s[i] == 'U')x--;
    if (x < 0 || x > 6)return 0;
    if (y < 0 || y > 6)return 0;
    if (vis[x][y] == 1)return 0;
    vis[x][y] = 1;
    int k = solve(x, y, i + 1);
    vis[x][y] = 0;
    return k;

}

int main() {
    vis[0][0] = 1;
    cin >> s;
    cout << solve(0, 0, 0);
    return 0;
}