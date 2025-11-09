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
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    stack<int> st;
    st.push(0);
    for(int i=0;i<n;i++) {
        while(st.top()!=0 && v[st.top()-1]>=v[i]) {
            st.pop();
        }
        cout << st.top() << ' ';
        st.push(i+1);
    }
    cout << '\n';
    return 0;
}