#include <bits/stdc++.h>
#define int long long
using namespace std;
int getSum(int targetLength, vector<int> &v) {
    int sum = 0;
    for(auto itr:v) sum+=abs(targetLength-itr);
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int lo = 1, hi = 1000000000;
    int ans = INT_MAX;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int leftSum = getSum(mid-1, v);
        int midSum = getSum(mid, v);
        int rightSum = getSum(mid+1, v);
        if(leftSum>=midSum && midSum<=rightSum) {
            ans = midSum;
            break;
        } else if(leftSum<rightSum) {
            hi = mid-1;
            ans = min(ans, leftSum);
        } else {
            lo = mid+1;
            ans = min(ans, rightSum);
        }
    }
    cout << ans << '\n';
    return 0;
}