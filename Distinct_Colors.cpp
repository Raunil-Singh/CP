#include <bits/stdc++.h>
using namespace std;

void dfs1(int par, int curr, vector<vector<int>>&adj, map<int, int> &mpp, vector<int> &w, vector<int> &c) {
    int prev = mpp[c[curr]];
    w[prev]--;
    mpp[c[curr]] = curr;

    for(int next : adj[curr]) {
        if(next == par) continue;
        dfs1(curr, next, adj, mpp, w, c);
    }

    mpp[c[curr]] = prev;
}

int dfs2(int prev, int curr, vector<vector<int>> &adj, vector<int> &w, vector<int> &ans) {
    for(int next : adj[curr]) {
        if(next == prev) continue;
        ans[curr] += dfs2(curr, next, adj, w, ans);
    }
    return ans[curr] += w[curr];
}

int main() {

    int n;
    cin >> n;
    vector<int> c(n+1);
    for(int i = 1 ; i<=n ; i++) cin >> c[i];
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int, int> mpp; // color -> closest ancestor
    vector<int> w(n+1, 1);

    dfs1(0, 1, adj, mpp, w, c);

    for(int num : w) cout << num << " ";
    cout << "\n";

    vector<int> ans(n+1);

    dfs2(0, 1, adj, w, ans);

    for(int i = 1 ; i<=n ; i++) cout << ans[i] << " ";
    cout << "\n";

}