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
int solve(int row, int col, int moves, vector<vector<bool>> &visited) {
    if(moves==48) {
        if(row==6 && col==6) {
            return 1;
        }
        return 0;
    }
    if(row==6 && col==6) {
        if(moves<48) return 0;
    }
    if(onlyOppDir(row, col, visited)) return 0;
    int sum=0;
    if(row-1>=0 && !visited[row-1][col]) {
        visited[row-1][col] = true;
        sum+=solve(row-1, col, moves+1, visited);
        visited[row-1][col] = false;
    }
    if(row+1<7 && !visited[row+1][col]) {
        visited[row+1][col] = true;
        sum+=solve(row+1, col, moves+1, visited);
        visited[row+1][col] = false;
    }
    if(col-1>=0 && !visited[row][col-1]) {
        visited[row][col-1] = true;
        sum+=solve(row, col-1, moves+1, visited);
        visited[row][col-1] = false;
    }
    if(col+1<7 && !visited[row][col+1]) {
        visited[row][col+1] = true;
        sum+=solve(row, col+1, moves+1, visited);
        visited[row][col+1] = false;
    }
    return sum;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    visited[0][0] = true;
    cout << solve(0, 0, 0, visited) << '\n';
    return 0;
}