#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(a+b>n) {
            cout << "NO\n";
            continue;
        }
        vector<int> aMoves, bMoves;
        bool flag = true;
        int numberOfDraws = n-(a+b);
        for(int i=1;i<=numberOfDraws;i++) {
            aMoves.push_back(i);
            bMoves.push_back(i);
        }
        for(int i=1;i<=a;i++) {
            if(n-a+i>numberOfDraws+i) {
                aMoves.push_back(n-a+i);
                bMoves.push_back(numberOfDraws+i);
            } else {
                flag = false;
            }
        }
        for(int i=1;i<=b;i++) {
            if(numberOfDraws+i<n-b+i) {
                aMoves.push_back(numberOfDraws+i);
                bMoves.push_back(n-b+i);
            } else {
                flag = false;
            }
        }
        if(flag) {
            cout << "YES\n";
            for(auto itr:aMoves) cout << itr << ' ';
            cout << '\n';
            for(auto itr:bMoves) cout << itr << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}