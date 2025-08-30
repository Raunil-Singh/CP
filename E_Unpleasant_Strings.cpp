#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> dpnp(n+1, vector<int>(k, n+1));
    for(int i = n-1 ; i>=0 ; i--) {
        for(int j = 0 ; j<k ; j++) dpnp[i][j] = dpnp[i+1][j];
        dpnp[i][s[i] - 'a'] = i+1;
    }
    vector<int> dp(n+2, INT_MAX);
    dp[n+1] = 0;
    for(int i = n ; i>=0 ; i--) {
        for(int j = 0 ; j<k ; j++) {
            dp[i] = min(dp[dpnp[i][j]] + 1, dp[i]);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string x;
        cin >> x;
        int curr = 0;
        for(char c : x) {
            curr = dpnp[curr][c - 'a'];
            if(curr == n+1) break;
        }
        cout << dp[curr] << "\n";
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}