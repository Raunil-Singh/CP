#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007LL

int mul(int a, int b) {
    return ((a % MOD) * (b %  MOD)) % MOD;
}

int dfs(int prev, int curr, vector<int> & depth, vector<vector<int>> & adj) {
    depth[curr] = 1;
    for(int next : adj[curr]) {
        if(prev == next) continue;
        depth[curr] = max(depth[curr], dfs(curr, next, depth, adj) + 1);
    }
    return depth[curr];
}

int power(int n, int p) {
    if(p == 0) return 1;
    if(p & 1LL) return mul(n, power(mul(n, n), p/2));
    else return power(mul(n, n), p/2);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n+1);
    dfs(0, 1, depth, adj);
    int sum = accumulate(depth.begin(), depth.end(), 0LL);
    cout << mul(power(2, n-1), sum) << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}