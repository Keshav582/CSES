#include <bits/stdc++.h>
#define int long long
using namespace std;
bool safe(vector<string> &board, int row, int col) {
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(row+i*dx[j]>=0 && row+i*dx[j]<8 && col+i*dy[j]>=0 && col+i*dy[j]<8) {
                if(board[row+i*dx[j]][col+i*dy[j]]=='#') {
                    return false;
                }
            }
        }
    }
    return true;
}
int solve(int currRow, vector<string> &board) {
    if(currRow==8) {
        return 1;
    }
    int ways = 0;
    for(int tryColumn=0;tryColumn<8;tryColumn++) {
        if(board[currRow][tryColumn]=='.' && safe(board, currRow, tryColumn)) {
            board[currRow][tryColumn] = '#';
            ways+=solve(currRow+1, board);
            board[currRow][tryColumn] = '.';
        }
    }
    return ways;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board(8);
    for(int i=0;i<8;i++) cin >> board[i];
    cout << solve(0, board) << '\n';
    return 0;
}