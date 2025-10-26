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
    int sum = (n*(n+1))/2;
    if(sum%2==0) {
        set<int> s1;
        for(int i=1;i<=n;i++) s1.insert(i);
        int target = sum/2;
        set<int> s2;
        while(target) {
            if(s1.count(target)) {
                s1.erase(target);
                s2.insert(target);
                break;
            } else {
                auto itr = s1.upper_bound(target);
                itr--;
                int num = *itr;
                s1.erase(num);
                s2.insert(num);
                target-=num;
            }
        }
        cout << "YES\n";
        cout << s1.size() << '\n';
        for(auto itr:s1) cout << itr << ' ';
        cout << '\n';
        cout << s2.size() << '\n';
        for(auto itr:s2) cout << itr << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}