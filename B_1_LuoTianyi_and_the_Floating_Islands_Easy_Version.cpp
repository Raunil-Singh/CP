#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007LL

int inv(int a) {
    return a <= 1 ? a : (MOD - ((int)(MOD/a) * inv(MOD%a)) % MOD);
}

int add(int a, int b) {
    return (a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void dfs1(int prev, int curr, vector<vector<int>> &adj, vector<int> &nc, vector<int> &dist) {
    for(int next : adj[curr]) {
        if(next == prev) continue;
        dfs1(curr, next, adj, nc, dist);
        dist[curr] += dist[next];
        nc[curr] += nc[next];
    }
    nc[curr]++;
    dist[curr] += nc[curr];
}

void dfs2(int prev, int curr, vector<vector<int>> &adj, vector<int> &nc, vector<int> &dist, int n) {
    if(prev)
        dist[curr] = dist[prev] - (nc[curr] + dist[curr]) + n - nc[curr] + dist[curr];
    for(int next : adj[curr]) {
        if(next == prev) continue;
        dfs2(curr, next, adj, nc, dist, n);
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(k != 2) {
        cout << 1 << "\n";
        return 0; 
    }

    vector<int> nc(n+1);
    vector<int> dist(n+1);

    dfs1(0, 1, adj, nc, dist);
    // for(int i = 1 ; i<=n ; i++) cout << nc[i] << " " << dist[i] << "\n";
    // cout << "----\n";
    dfs2(0, 1, adj, nc, dist, n);
    // for(int i = 1 ; i<=n ; i++) cout << nc[i] << " " << dist[i] << "\n";

    int sum = -n;
    for(int i = 1 ; i<=n ; i++) sum += dist[i];
    sum = mul(sum, inv(2));

    cout << mul(sum, inv(mul(mul(n, n-1), inv(2)))) << "\n";

    return 0;
}

/*
 *
 * 1 - 2 - 3 - 4
 * 1: 1+2+3 = 6
 * 2: 1+1+2 = 4
 * 3: 1+1+2 = 4
 * 4: 1+2+3 = 6
 *          = 20 - n
 * 
 */