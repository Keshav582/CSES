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
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    vector<int> at(n+1);
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        at[v[i]] = i;
    }
    int initialAns = 1;
    for(int i=2;i<=n;i++) {
        if(at[i-1]>at[i]) initialAns++;
    }
    for(int i=0;i<m;i++) {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        if(idx2<idx1) swap(idx1, idx2);
        int num1 = v[idx1];
        int num2 = v[idx2];
        int x = 0;
        if(num1+1<=n) {
            if(at[num1+1]>=idx1 && at[num1+1]<=idx2) x++;
        }
        if(num1-1>0) {
            if(at[num1-1]>=idx1 && at[num1-1]<=idx2) x--;
        }
        if(num2+1<=n) {
            if(at[num2+1]<=idx2 && at[num2+1]>=idx1) x--;
        }
        if(num2-1>0) {
            if(at[num2-1]<=idx2 && at[num2-1]>=idx1) x++;
        }
        if(num1-1==num2) x++;
        if(num1+1==num2) x--;
        initialAns+=x;
        cout << initialAns << '\n';
        v[idx1] = num2;
        v[idx2] = num1;
        at[num2] = idx1;
        at[num1] = idx2;
    }
    return 0;
}