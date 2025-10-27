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
    string s; cin >> s;
    map<char, int> charCounter;
    for(auto itr:s) charCounter[itr]++;
    char oddChar = '0';
    int oddCharCount = 0;
    for(auto itr:charCounter) {
        if(itr.second%2!=0) {
            oddChar = itr.first;
            oddCharCount++;
        }
    }
    if(oddCharCount<=1) {
        for(char a='A';a<='Z';a++) {
            if(a!=oddChar) {
                for(int i=0;i<charCounter[a]/2;i++) {
                    cout << a;
                }
            }
        }
        for(int i=0;i<charCounter[oddChar];i++) cout << oddChar;
        for(char a='Z';a>='A';a--) {
            if(a!=oddChar) {
                for(int i=0;i<charCounter[a]/2;i++) {
                    cout << a;
                }
            }
        }
        cout << '\n';
    } else {
        cout << "NO SOLUTION\n";
    }
    return 0;
}