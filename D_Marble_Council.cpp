#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 998244353LL

void solve() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &num : v) cin >> num;

    // cout << "---\n";

    map<int, int> mpp;
    for(int num : v) {
        mpp[num]++;
    }

    map<int, int> freq;
    for(auto [a, b] : mpp) {
        freq[b]++;
    }

    bool flag = false;
    int ans = 1;
    for(auto itr = freq.rbegin() ; itr!=freq.rend() ; itr++) {
        int num = itr->first, cnt = itr->second;
        if(!flag) {
            flag = true;
            int x = 1;
            for(int i = 0 ; i<cnt ; i++)
                x = (x * (num+1)) % MOD;
            x = (x - 1 + MOD) % MOD; // empty not allowed
            ans = (ans * x) % MOD;
        } else {
            for(int i = 0 ; i<cnt ; i++)
                ans = (ans * (num+1)) % MOD;
        }
        // cout << num << " " << cnt << " " << ans << "\n";
    }

    // if mod completely absent, then this means atleast sigma mod numbers in output for sure
    int ignore = freq.rbegin()->first;


    // logic to compute when mod is completely missing
    vector<int> dp(n+2);
    dp[0] = 1;
    int del = 0;
    for(auto [a, b] : mpp) {
        if(b == ignore) {
            del += ignore;
            continue;
        }
        for(int i = n ; i>=0 ; i--) {
            for(int j = max(0LL, i-b) ; j<i ; j++) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        cout << a << ":\n";
        for(int num : dp) cout << num << " ";
        cout << "\n";
    }

    // cout << del << "@@\n";

    // for(int i = 0 ; i<=n ; i++) {
    //     cout << i << "->" << dp[i] << " ";
    // }
    // cout << "\n";

    for(int i = del ; i<=n ; i++)
        ans = (ans + dp[i]) % MOD;
    cout << ans << "\n";

}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}