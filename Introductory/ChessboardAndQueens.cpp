#include <bits/stdc++.h>
#define int long long
using namespace std;
bool safe(int r1, int c1, int r2, int c2) {
    if(r1==r2) return false;
    if(c1==c2) return false;
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};
    for(int i=0;i<4;i++) {
        int orig_r1 = r1, orig_c1 = c1;
        while(r1+dx[i]>=0 && r1+dx[i]<8 && c1+dy[i]>=0 && c1+dy[i]<8) {
            if(r1+dx[i]==r2 && c1+dy[i]==c2) return false;
            r1+=dx[i], c1+=dy[i];
        }
        r1 = orig_r1, c1 = orig_c1;
    }
    return true;
}
bool canPlace(int row, int column, vector<string> &board) {
    if(board[row][column]=='.') {
        for(int j=0;j<column;j++) {
            for(int i=0;i<8;i++) {
                if(board[i][j]=='Q') {
                    if(!safe(i, j, row, column)) return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}
int solve(int column, vector<string> &board) {
    if(column>=8) {
        return 1;
    }
    int ans = 0;
    for(int row=0;row<8;row++) {
        if(canPlace(row, column, board)) {
            board[row][column] = 'Q';
            ans+=solve(column+1, board);
            board[row][column] = '.';
        }
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board(8);
    for(int i=0;i<8;i++) cin >> board[i];
    cout << solve(0, board) << '\n';
    return 0;
}