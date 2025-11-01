#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
string s;
int visited[7][7];
int ans = 0;
bool onlyOppDir(int currRow, int currCol) {
    if((currRow-1<0 || visited[currRow-1][currCol]) && (currRow+1>=7 || visited[currRow+1][currCol]) && (currCol-1>=0 && !visited[currRow][currCol-1]) && (currCol+1<7 && !visited[currRow][currCol+1])) {
        return true;
    }
    if((currCol-1<0 || visited[currRow][currCol-1]) && (currCol+1>=7 || visited[currRow][currCol+1]) && (currRow-1>=0 && !visited[currRow-1][currCol]) && (currRow+1<7 && !visited[currRow+1][currCol])) {
        return true;
    }
    return false;
}
void solve(int row, int col, int moves) {
    if(moves==48) {
        if(row==6 && col==0) {
            ans++;
        }
    }
    if(row==6 && col==0) {
        if(moves<48) return;
    }
    if(onlyOppDir(row, col)) return;
    visited[row][col] = 1;
    if(row-1>=0 && (s[moves]=='U' || s[moves]=='?') && !visited[row-1][col]) {
        solve(row-1, col, moves+1);
    }
    if(row+1<7 && (s[moves]=='D' || s[moves]=='?') && !visited[row+1][col]) {
        solve(row+1, col, moves+1);
    }
    if(col-1>=0 && (s[moves]=='L' || s[moves]=='?') && !visited[row][col-1]) {
        solve(row, col-1, moves+1);
    }
    if(col+1<7 && (s[moves]=='R' || s[moves]=='?') && !visited[row][col+1]) {
        solve(row, col+1, moves+1);
    }
    visited[row][col] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    solve(0, 0, 0);
    cout << ans << '\n';
    return 0;
}

/*
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool onlyOppDir(int currRow, int currCol, vector<vector<bool>> &visited) {
    if((currRow-1<0 || visited[currRow-1][currCol]) && (currRow+1>=7 || visited[currRow+1][currCol]) && (currCol-1>=0 && !visited[currRow][currCol-1]) && (currCol+1<7 && !visited[currRow][currCol+1])) {
        return true;
    }
    if((currCol-1<0 || visited[currRow][currCol-1]) && (currCol+1>=7 || visited[currRow][currCol+1]) && (currRow-1>=0 && !visited[currRow-1][currCol]) && (currRow+1<7 && !visited[currRow+1][currCol])) {
        return true;
    }
    return false;
}
int solve(int row, int col, int moves, string &s, vector<vector<bool>> &visited) {
    if(moves==48) {
        if(row==6 && col==0) {
            return 1;
        }
        return 0;
    }
    if(row==6 && col==0) {
        if(moves<48) return 0;
    }
    if(onlyOppDir(row, col, visited)) return 0;
    visited[row][col] = true;
    int sum=0;
    if((s[moves]=='U' || s[moves]=='?') && row-1>=0 && !visited[row-1][col]) {
        sum+=solve(row-1, col, moves+1, s, visited);
    }
    if((s[moves]=='D' || s[moves]=='?') && row+1<7 && !visited[row+1][col]) {
        sum+=solve(row+1, col, moves+1, s, visited);
    }
    if((s[moves]=='L' || s[moves]=='?') && col-1>=0 && !visited[row][col-1]) {
        sum+=solve(row, col-1, moves+1, s, visited);
    }
    if((s[moves]=='R' || s[moves]=='?') && col+1<7 && !visited[row][col+1]) {
        sum+=solve(row, col+1, moves+1, s, visited);
    }
    visited[row][col] = false;
    return sum;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    cout << solve(0, 0, 0, s, visited) << '\n';
    return 0;
}
*/