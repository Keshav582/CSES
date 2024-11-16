#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int m; cin >> m;
    map<int, int> IAmAt;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++) {
        int number; cin >> number;
        v[i] = number;
        IAmAt[number] = i;
    }
    v[0] = 0, v[n+1] = n+1;
    IAmAt[0] = 0, IAmAt[n+1] = n+1;
    int numberOfChains = 0;
    vector<bool> visited(n+1, false);
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            numberOfChains++;
            int nextInChain = i+1;
            visited[i] = true;
            while(nextInChain<=n && !visited[nextInChain] && IAmAt[nextInChain]>IAmAt[nextInChain-1]) {
                visited[nextInChain] = true;
                nextInChain++;
            }
        }
    }
    for(int i=0;i<m;i++) {
        int index1, index2;
        cin >> index1 >> index2;
        if(index1>index2) swap(index1, index2);
        int x = v[index1], y = v[index2];
        if(x==y+1) numberOfChains++;
        else if(x+1==y) numberOfChains--;
        int smallThenXAt = IAmAt[x-1], greaterThenXAt = IAmAt[x+1];
        int smallThenYAt = IAmAt[y-1], greaterThenYAt = IAmAt[y+1];
        int smallThenXandXchain = smallThenXAt<index1?1:0;
        int greaterThenXandXchain = index1<greaterThenXAt?1:0;
        int smallThenYandYchain = smallThenYAt<index2?1:0;
        int greaterTheYandYchain = index2<greaterThenYAt?1:0;
        swap(v[index1], v[index2]);
        IAmAt[x] = index2, IAmAt[y] = index1;
        int pssmallThenXAt = IAmAt[x-1], psgreaterThenXAt = IAmAt[x+1];
        int pssmallThenYAt = IAmAt[y-1], psgreaterThenYAt = IAmAt[y+1];
        int pssmallThenXandXchain = pssmallThenXAt<index2?1:0;
        int psgreaterThenXandXchain = index2<psgreaterThenXAt?1:0;
        int pssmallThenYandYchain = pssmallThenYAt<index1?1:0;
        int psgreaterTheYandYchain = index1<psgreaterThenYAt?1:0;
        numberOfChains+=(smallThenXandXchain+greaterThenXandXchain+smallThenYandYchain+greaterTheYandYchain-pssmallThenXandXchain-psgreaterThenXandXchain-pssmallThenYandYchain-psgreaterTheYandYchain);
        cout << numberOfChains << '\n';
    }
    return 0;
}