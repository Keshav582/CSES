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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int lo = 0;
    int hi = 1e15;
    int ans = hi;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int numOfSubarrays = 0;
        bool possible = true;
        for(int i=0;i<n;) {
            int currSum = 0;
            int j=i;
            while(j<n && currSum+v[j]<=mid) {
                currSum+=v[j++];
            }
            if(i==j) {
                possible = false;
                break;
            }
            numOfSubarrays++;
            i = j;
        }
        if(!possible) {
            lo = mid+1;
            continue;
        }
        if(numOfSubarrays<=k) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}