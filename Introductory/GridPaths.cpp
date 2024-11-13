#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
bool possible(char dir, int row, int col) {
    if(dir=='U' && row-1>=0) return true;
    if(dir=='D' && row+1<7) return true;
    if(dir=='L' && col-1>=0) return true;
    if(dir=='R' && col+1<7) return true;
    return false;
}
int solve(int idx, int row, int col, vector<vector<bool> > &visited, string &orig) {
    if(row==6 && col==0) {
        if(idx<48) {
            return 0;
        } else {
            return 1;
        }
    }
    if(idx>=48) {
        if(row==6 && col==0) {
            return 1;
        }
        return 0;
    }
    if(row==0 || row==6) {
        if(col-1>=0 && !visited[row][col-1] && col+1<7 && !visited[row][col+1]) return 0;
    }
    if(col==0 || col==6) {
        if(row-1>=0 && !visited[row-1][col] && row+1<7 && !visited[row+1][col]) return 0;
    }
    int ans = 0;
    if(possible('U', row, col) && !visited[row-1][col] && (orig[idx]=='?' || orig[idx]=='U')) {
        visited[row-1][col] = true;
        ans+=solve(idx+1, row-1, col, visited, orig);
        visited[row-1][col] = false;
    }
    if(possible('D', row, col) && !visited[row+1][col] && (orig[idx]=='?' || orig[idx]=='D')) {
        visited[row+1][col] = true;
        ans+=solve(idx+1, row+1, col, visited, orig);
        visited[row+1][col] = false;
    }
    if(possible('L', row, col) && !visited[row][col-1] && (orig[idx]=='?' || orig[idx]=='L')) {
        visited[row][col-1] = true;
        ans+=solve(idx+1, row, col-1, visited, orig);
        visited[row][col-1] = false;
    }
    if(possible('R', row, col) && !visited[row][col+1] && (orig[idx]=='?' || orig[idx]=='R')) {
        visited[row][col+1] = true;
        ans+=solve(idx+1, row, col+1, visited, orig);
        visited[row][col+1] = false;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<vector<bool> > visited(8, vector<bool>(8, false));
    visited[0][0] = true;
    cout << solve(0, 0, 0, visited, s) << '\n';
    return 0;
}