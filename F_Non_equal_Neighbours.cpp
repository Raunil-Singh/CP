#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353LL

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1 ; i<=n ; i++) cin >> a[i];
    stack<int> st;
    vector<int> x(n+1);
    for(int i = 1 ; i<=n ; i++) {
        while(!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }
        if(!st.empty()) x[i] = st.top();
        st.push(i);
    }
    vector<int> dp(n+1), sdp(n+1);
    dp[0] = 1;
    sdp[0] = 1;
    for(int i = 1 ; i<=n ; i++) {
        dp[i] = (((sdp[i-1] + ((i-x[i])%2 ? -1 : 1)*sdp[x[i]]) * a[i]) % MOD 
                - (((i-x[i])%2 ? -1 : 1) * dp[x[i]] * (a[i]-(x[i]>0))) % MOD + 2*MOD) % MOD;
        sdp[i] = (dp[i] - sdp[i-1] + MOD) % MOD;
    }
    // for(int num : dp) cout << num << " "; cout << "\n";
    // for(int num : sdp) cout << num << " "; cout << "\n";
    // for(int num : x) cout << num << " "; cout << "\n";
    cout << dp[n] << " "; cout << "\n";
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}