#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353LL

int inv(int a, int m = MOD) {
    return a<=1 ? a : m - (int)(m/a) * inv(m%a, m) % m;
}

int add(int a, int b) {
    return (a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return (a * b) % MOD;
}

int compute(int ind, vector<int> &exclude, vector<int> &dp, map<int, vector<pair<int, int>>> &mpp) {
    if(dp[ind] != -1) return dp[ind];
    int prob = 0;
    for(auto [r, p] : mpp[ind]) {
        prob = add(prob, mul(compute(r+1, exclude, dp, mpp), 
                        mul(inv(exclude[r+1]), 
                        mul(exclude[ind],
                        mul(inv(add(1, -p)), p)))));
    }
    return dp[ind] = prob;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> exclude(m+1, 1);
    map<int, vector<pair<int, int>>> mpp;
    for(int i = 0 ; i<n ; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        mpp[l-1].push_back(make_pair(r-1, (p*inv(q)) % MOD));
        exclude[l-1] = mul(exclude[l-1], add(1, -mul(p, inv(q))));
    }

    for(int i = m-1 ; i>=0 ; i--) exclude[i] = mul(exclude[i], exclude[i+1]);

    vector<int> dp(m+1, -1);
    dp[m] = 1;
    // for(int i = m-1 ; i>=0 ; i--) compute(i, exclude, dp, mpp);
    // for(int num : dp) cout << num << "\n";
    cout << compute(0, exclude, dp, mpp) << "\n";

    return 0;
}