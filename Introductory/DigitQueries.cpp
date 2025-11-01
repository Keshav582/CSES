#include <bits/stdc++.h>
#define int long long
using namespace std;
char solve(int query) {
    if(query<=9) return '0'+query;
    int totalDigitsTillNow = 9;
    int individualNumberOfDigits = 1;
    int numbersWithCurrentIndividualDigitCount = 9;
    while(totalDigitsTillNow<query) {
        individualNumberOfDigits++;
        numbersWithCurrentIndividualDigitCount*=10;
        totalDigitsTillNow+=(individualNumberOfDigits*numbersWithCurrentIndividualDigitCount);
    }
    totalDigitsTillNow-=(individualNumberOfDigits*numbersWithCurrentIndividualDigitCount);
    int startingNumber = pow(10, individualNumberOfDigits-1);
    int blockQueryNumber = query-totalDigitsTillNow;
    int whatToAdd = blockQueryNumber/individualNumberOfDigits;
    if(blockQueryNumber%individualNumberOfDigits==0) whatToAdd--;
    int currentNumber = startingNumber+whatToAdd;
    int whatDigit = blockQueryNumber%individualNumberOfDigits;
    if(whatDigit==0) whatDigit = individualNumberOfDigits;
    whatDigit--;
    return to_string(currentNumber)[whatDigit];
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int q; cin >> q;
        cout << solve(q) << '\n';
    }
    return 0;
}