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
    int n = s.size();
    vector<char> ans(n);
    map<char, int> mp;
    for(int i=0;i<n;i++) mp[s[i]]++;
    bool flag = true;
    for(int i=0;i<n;i++) {
        char minChar = 'A';
        int minCharFreq = mp[minChar];
        char charWithMaxFreq = 'Z';
        int maxFreq = mp[charWithMaxFreq];
        for(char ch='A';ch<='Z';ch++) {
            if(mp[ch]>0 && (i==0 || ans[i-1]!=ch)) {
                minChar = ch;
                minCharFreq = mp[ch];
                break;
            }
        }
        for(char ch='Z';ch>='A';ch--) {
            if(mp[ch]>maxFreq && (i==0 || ans[i-1]!=ch)) {
                charWithMaxFreq = ch;
                maxFreq = mp[ch];
            }
        }
        int positionsLeft = n-i;
        int reqdForMaxFreq = (maxFreq*2)-1;
        if(reqdForMaxFreq>positionsLeft) {
            flag = false;
            break;
        } else if(reqdForMaxFreq==positionsLeft) {
            mp[charWithMaxFreq]--;
            ans[i] = charWithMaxFreq;
        } else {
            mp[minChar]--;
            ans[i] = minChar;
        }
    }
    if(flag) {
        for(auto itr:ans) cout << itr;
        cout << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}